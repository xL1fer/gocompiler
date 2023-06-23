    //  "functions.c"
    //
    //  ====================================
    //
    //  Universidade de Coimbra
    //  Faculdade de Ciências e Tecnologia
    //  Departamento de Engenharia Informatica
    //
    //  Daniel Gonçalves Portovedo - 2019214315
    //  Luís Miguel Gomes Batista  - 2019214869
    //
    //  ====================================
    //
    //  this file contains the definitions of the
    //  functions used throughout the program

#include "structures.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern int token_status;
extern is_node* last_node;
extern int errors;

//-----------------------------------
// ast management functions
//-----------------------------------

is_node* insert_block(is_node* node, int add_sibling){
     
     if(token_status == -1) return NULL;

     is_node* in = (is_node*)malloc(sizeof(is_node));
     is_node* in_s;
     

     in->type = "Block";
     in->val = NULL;
     in->notation = NULL;
     in->temp_num = 0;

     if(add_sibling){
        in_s = (is_node*)malloc(sizeof(is_node));
        in_s->type = "Block";
        in_s->val = NULL;
        in_s->notation = NULL;
        in_s->temp_num = 0;
        in_s->child = NULL;
        in_s->sibling = NULL;
        in->sibling = in_s;
     }else{
        in->sibling = NULL;
     }

     in->child = node;

     last_node = in;

     return in;
}

is_node* insert_sibling(is_node* brother, is_node* node){
        
        if(token_status == -1) return NULL;

        is_node* tmp;
        for (tmp = brother; tmp->sibling; tmp=tmp->sibling);

        tmp->sibling=node;
        
        last_node = brother;

        return brother;
}

is_node* insert_terminal(is_value* value, char* type){

        if(token_status == -1) return NULL;

        is_node* in = (is_node*)malloc(sizeof(is_node));

        in->type = type;
        in->val = value;

        if(strcmp(type,"IntLit")==0){
                in->notation = "int";
        }else if(strcmp(type,"RealLit")==0){
                in->notation = "float32";
        }else if(strcmp(type,"StrLit")==0){
                in->notation = "string";
        }else{
                in->notation = NULL;    
        }
        in->temp_num = 0;
        
        in -> child = NULL;
        in -> sibling = NULL;

        last_node = in;

        return in;
}

is_node* insert_node(is_value* value,char* type, is_node* expr1, is_node* expr2){    
        
        if(token_status == -1) return NULL;

        is_node* in = (is_node*)malloc(sizeof(is_node));

        if(expr2 != NULL){
                expr1->sibling = expr2;
        }

        in->type = type;
        in->val = value;

        if(strcmp(type,"And") == 0 || strcmp(type,"Or") == 0 || strcmp(type,"Lt") == 0 || strcmp(type,"Gt") == 0 || strcmp(type,"Eq") == 0 || strcmp(type,"Ne") == 0 || strcmp(type,"Le") == 0 || strcmp(type,"Ge") == 0){
                in->notation = "bool";
        }else{
                in->notation = NULL;
        }
        in->temp_num = 0;

        in->child = expr1;
        in->sibling = NULL;

        last_node = in;

        return in;
}

void change_type(is_node* start, char* new_type)
{
        if(token_status == -1) return;

        if (strcmp(start->type, "None") == 0) start->type = new_type;

        if (start->child)
                change_type(start->child, new_type);
        else
        {  
                if(start->sibling) change_type(start->sibling, new_type);
                return;
        }

        if (start->sibling)
                change_type(start->sibling, new_type);
}

is_value* create_value(char* token, int line, int col)
{
        is_value* iv = (is_value*)malloc(sizeof(is_value));
        iv->token = token;
        iv->line = line;
        iv->col = col;

        return iv;
}

//-----------------------------------
// print ast
//-----------------------------------

void print_program(is_node* start, int depth)
{
        if(errors || start == NULL || token_status == -1) return;       // exit if current node is null

        for (int i = 0; i < depth; i++) printf("..");

        printf("%s", start->type);

        if(token_status == 3 && start->notation && (strcmp(start->type,"Call") == 0 || strcmp(start->type,"Or") == 0 || strcmp(start->type,"And") == 0 || strcmp(start->type,"Eq") == 0 ||strcmp(start->type,"Ne") == 0 ||strcmp(start->type,"Lt") == 0 ||strcmp(start->type,"Gt") == 0 ||strcmp(start->type,"Le") == 0 ||strcmp(start->type,"Ge") == 0 ||strcmp(start->type,"Add") == 0 ||strcmp(start->type,"Sub") == 0 ||strcmp(start->type,"Mul") == 0 ||strcmp(start->type,"Div") == 0 ||strcmp(start->type,"Mod") == 0 || strcmp(start->type,"Not") == 0 || strcmp(start->type,"Minus") == 0 || strcmp(start->type,"Plus") == 0 || strcmp(start->type,"Assign") == 0 ||strcmp(start->type,"ParseArgs") == 0)){
                if(strcmp(start->notation,"none") != 0)
                        printf(" - %s",start->notation);
        }

        if (start->child)
        {
                printf("\n");
                print_program(start->child, depth + 1);
        }
        else
        {
                if(start->val){
                        if(strcmp(start->type,"StrLit")==0){
                            printf("(\"%s\")", start->val->token);    
                        }else if(strcmp(start->type,"Return")!=0){
                            printf("(%s)", start->val->token);    
                        }

                        if(token_status == 3 && start->notation && (strcmp(start->type,"StrLit") == 0 || strcmp(start->type,"RealLit") == 0 || strcmp(start->type,"IntLit") == 0 || strcmp(start->type,"Id") == 0)){
                                printf(" - %s",start->notation);       
                        }
                }    
                printf("\n");

                if(start->sibling) print_program(start->sibling, depth);
                return;
        }

        if (start->sibling)
                print_program(start->sibling, depth);
}

//-----------------------------------
// symbol table build functions
//-----------------------------------

extern is_ambient* amb_head;
is_symb_table* symb_head = NULL;


void check_ast(is_node* nd, int depth, is_symb_table* head_symb_tab)
{
        if (nd == NULL || token_status == -1) return;

        if (strcmp(nd->type, "VarDecl") == 0)
        {

                //printf("We need to insert VAR %s (depth: %d)\n", nd->child->sibling->token, depth);
                if(depth == 0){
                        insert_symb(nd->child->sibling->val->token, nd->child->type, depth, 0,NULL, nd->child->sibling);
                }else{
                        insert_symb(nd->child->sibling->val->token, nd->child->type, depth, 0,head_symb_tab, nd->child->sibling);        
                }
                
                check_ast(nd->sibling, depth,head_symb_tab);                                  // go to next sibling, we dont need to check the childs

                return;
        }
        else if (strcmp(nd->type, "FuncDecl") == 0)
        {       

                is_symb_table* func_head;
                is_node* is_tmp;
                //printf("We need to insert FUNC %s (depth: %d)\n", nd->child->child->token, depth);
                if (strcmp(nd->child->child->sibling->type, "FuncParams") == 0)
                {
                        func_head = insert_symb(nd->child->child->val->token, "None", depth, 1,head_symb_tab, nd->child->child);
                        is_tmp = nd->child->child->sibling->child;
                        for(;is_tmp;is_tmp = is_tmp->sibling){
                                insert_symb(is_tmp->child->sibling->val->token,is_tmp->child->type,3,0,func_head, is_tmp->child->sibling);
                        }
                }
                else
                {
                        
                        func_head = insert_symb(nd->child->child->val->token, nd->child->child->sibling->type, depth, 1,head_symb_tab, nd->child->child);
                        
                        is_tmp = nd->child->child->sibling->sibling->child;
                        for(;is_tmp;is_tmp = is_tmp->sibling){
                                insert_symb(is_tmp->child->sibling->val->token,is_tmp->child->type,3,0,func_head, is_tmp->child->sibling);
                        }
                }

                check_ast(nd->sibling,depth,head_symb_tab);
                check_ast(nd->child->sibling, depth + 1,func_head);

                return;
        }
        else if (strcmp(nd->type, "Call") == 0)                                 // notate Call
        {
                check_ast(nd->child->sibling, depth + 1,head_symb_tab);                       // ignore the Call Id child
                check_ast(nd->sibling, depth,head_symb_tab);

                is_symb_table* tmp;
                
                if((tmp = get_symb(nd->child,head_symb_tab, 1))){
                        if (strcmp(tmp->type, "none") != 0)
                                nd->notation = tmp->type;
                        else
                                nd->notation = "none";    
                }
                else nd->notation = "undef";

                // make a string with function parameters

                char params[256] = "";
                if (tmp){
                        int cond = 1;
                        strcat(params, "(");
                        for(tmp = tmp->next;tmp && tmp->is_param;tmp = tmp->next){
                                if (cond){
                                        cond = 0;
                                        strcat(params, tmp->type);
                                }
                                else{
                                        strcat(params, ",");
                                        strcat(params, tmp->type);
                                }
                        }
                        strcat(params, ")\0");

                        nd->child->notation = strdup(params);
                }
                
                return;
        }
        else if (strcmp(nd->type, "Mul") == 0 || strcmp(nd->type, "Sub") == 0 || strcmp(nd->type, "Div") == 0 || strcmp(nd->type, "Mod") == 0 || strcmp(nd->type, "Add") == 0 || strcmp(nd->type, "Assign") == 0 || strcmp(nd->type, "ParseArgs") == 0)  // notate Operations (NOTE: not completed, some operators missing)
        {       
                
                check_ast(nd->child, depth + 1,head_symb_tab);                                // complete childrens notation first, then we can check the operator
                check_ast(nd->sibling, depth,head_symb_tab);

                if(strcmp(nd->type, "ParseArgs") == 0){
                        if (strcmp(head_symb_tab->type,"undef") != 0 && (strcmp(nd->child->notation, "int") != 0 || strcmp(nd->child->sibling->notation,"int") != 0)){
                                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation, nd->child->sibling->notation);
                                errors = 1;
                                nd->notation = "undef";
                                return;
                        }   
                        nd->notation = nd->child->notation;     
                        return;
                }else if(strcmp(nd->type, "Assign") == 0){
                        if (strcmp(head_symb_tab->type,"undef") != 0 && (strcmp(nd->child->sibling->notation,"none") == 0 || strcmp(nd->child->sibling->notation,"undef") == 0 || strcmp(nd->child->notation, nd->child->sibling->notation) != 0)){
                                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation, nd->child->sibling->notation);
                                errors = 1;
                                nd->notation = "undef";
                                return;
                        }  
                        nd->notation = nd->child->notation;
                        return;  
                }

                if (strcmp(nd->child->notation, nd->child->sibling->notation) == 0 && strcmp(nd->child->notation,"bool") != 0 && strcmp(nd->child->sibling->notation,"none") != 0 && strcmp(nd->child->notation,"undef") != 0){
                        nd->notation = nd->child->notation;
                }
                else if(strcmp(head_symb_tab->type,"undef") != 0 ){
                        printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation, nd->child->sibling->notation);
                        errors = 1;
                        nd->notation = "undef";
                }
                return;
        }
        else if (strcmp(nd->type,"And") == 0 || strcmp(nd->type,"Or") == 0)
        {
                check_ast(nd->child, depth + 1,head_symb_tab);                                // complete childrens notation first, then we can check the operator
                check_ast(nd->sibling, depth,head_symb_tab);

                if (strcmp(head_symb_tab->type,"undef") != 0 && (strcmp(nd->child->notation,"none") == 0 || strcmp(nd->child->sibling->notation,"none") == 0 || strcmp(nd->child->notation, "bool") != 0 || strcmp(nd->child->sibling->notation, "bool") != 0)){
                        printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation, nd->child->sibling->notation);
                        errors = 1;
                }
                return;
        }
        else if (strcmp(nd->type, "Not") == 0 || strcmp(nd->type, "Minus") == 0 || strcmp(nd->type, "Plus") == 0)
        {       
                check_ast(nd->child, depth + 1,head_symb_tab);
                check_ast(nd->sibling, depth,head_symb_tab);

                if(strcmp(nd->type, "Not") == 0){
                        if(strcmp(head_symb_tab->type,"undef") != 0 && (strcmp(nd->child->notation,"none") == 0 || strcmp(nd->child->notation,"bool") != 0)){
                                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation);
                                errors = 1;
                        }
                        nd->notation = "bool";
                        return;
                }else if(strcmp(nd->type, "Minus") == 0 || strcmp(nd->type, "Plus") == 0){
                        if(strcmp(head_symb_tab->type,"undef") != 0 && (strcmp(nd->child->notation,"int") != 0 && strcmp(nd->child->notation,"float32") != 0)){
                                printf("Line %d, column %d: Operator %s cannot be applied to type %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation);
                                nd->notation = "undef";
                                errors = 1;
                                return;
                        } 
                }

                nd->notation = nd->child->notation;
                return;
        }
        else if (strcmp(nd->type, "Id") == 0)                                   // only Id's of variables that need to be checked get here
        {                                                                         // for example "x = 2" or "if (x == 2){}"
                if(get_symb(nd,head_symb_tab, 0)){
                        //printf("Found Id %s with type %s!\n", nd->token,get_symb(nd)->type);
                        nd->notation = get_symb(nd,head_symb_tab, 0)->type;
                }
                else{
                        nd->notation = "undef";
                }
                
        }else if(strcmp(nd->type, "If") == 0 || strcmp(nd->type, "For") == 0 || strcmp(nd->type,"Return") == 0 || strcmp(nd->type,"Print") == 0){
                check_ast(nd->child, depth + 1,head_symb_tab);
                check_ast(nd->sibling, depth,head_symb_tab);
                


                char aux[7] = "";
                strcpy(aux,nd->type);
                aux[0] += 32;

                if(strcmp(nd->type,"Return") == 0){
                        if(strcmp(head_symb_tab->type,"undef") != 0 && ((nd->child && nd->child->notation && strcmp(head_symb_tab->type,nd->child->notation) != 0 ) || (nd->child && nd->child->notation && strcmp(nd->child->notation,"none") == 0))){
                                if(nd->child->val)
                                        printf("Line %d, column %d: Incompatible type %s in %s statement\n",nd->val->line, nd->child->val->col,nd->child->notation,aux);
                                else
                                        printf("Line %d, column %d: Incompatible type %s in %s statement\n",nd->val->line, nd->child->child->val->col,nd->child->notation,aux);
                                errors = 1;
                        }
                        else if (nd->child == NULL && strcmp(head_symb_tab->type, "none") != 0) {
                                printf("Line %d, column %d: Incompatible type none in %s statement\n",nd->val->line, nd->val->col,aux);
                                errors = 1;
                        }
                              
                }else if(strcmp(nd->type,"Print") == 0){
                        if(strcmp(head_symb_tab->type,"undef") != 0 && ((nd->child && nd->child->notation && strcmp(nd->child->notation, "undef") == 0 )|| strcmp(nd->child->notation,"none") == 0)){
                                if(nd->child->val)
                                        printf("Line %d, column %d: Incompatible type %s in %s statement\n",nd->val->line, nd->child->val->col,nd->child->notation,convert_type(nd->type));
                                else
                                        printf("Line %d, column %d: Incompatible type %s in %s statement\n",nd->val->line, nd->child->child->val->col,nd->child->notation,convert_type(nd->type));
                                errors = 1;
                        }
                }else if(strcmp(head_symb_tab->type,"undef") != 0 && ((nd->child && nd->child->notation && strcmp(nd->child->notation,"bool") != 0 )|| (nd->child && nd->child->notation && strcmp(nd->child->notation,"none") == 0 ))){
                        if(nd->child->val)
                                printf("Line %d, column %d: Incompatible type %s in %s statement\n",nd->val->line, nd->child->val->col,nd->child->notation,aux);
                        else
                                printf("Line %d, column %d: Incompatible type %s in %s statement\n",nd->val->line, nd->child->child->val->col,nd->child->notation,aux);
                        errors = 1;
                }
                return;
        }else if(strcmp(nd->type,"Lt") == 0 || strcmp(nd->type,"Gt") == 0 || strcmp(nd->type,"Eq") == 0 || strcmp(nd->type,"Ne") == 0 || strcmp(nd->type,"Le") == 0 || strcmp(nd->type,"Ge") == 0){
                check_ast(nd->child, depth + 1,head_symb_tab);                                // complete childrens notation first, then we can check the operator
                check_ast(nd->sibling, depth,head_symb_tab);

                if(strcmp(nd->type,"Eq") == 0 || strcmp(nd->type,"Ne") == 0){
                        if (strcmp(head_symb_tab->type,"undef") != 0 && (strcmp(nd->child->notation,"none") == 0 || strcmp(nd->child->sibling->notation,"none") == 0 || strcmp(nd->child->notation, nd->child->sibling->notation) != 0 || strcmp(nd->child->notation,"undef") == 0)){
                                printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation, nd->child->sibling->notation);
                                errors = 1;
                        }  
                        nd->notation = "bool";  
                        return;        
                }

                if (strcmp(head_symb_tab->type,"undef") != 0 && (strcmp(nd->child->notation,"none") == 0 || strcmp(nd->child->sibling->notation,"none") == 0 || strcmp(nd->child->notation, nd->child->sibling->notation) != 0 || strcmp(nd->child->notation,"undef") == 0 || (strcmp(nd->child->notation,"bool") == 0 || strcmp(nd->child->notation,"string") == 0))){
                        printf("Line %d, column %d: Operator %s cannot be applied to types %s, %s\n",nd->val->line, nd->val->col, convert_type(nd->type), nd->child->notation, nd->child->sibling->notation);
                        errors = 1;
                        
                }

                nd->notation = "bool";
                return;        
        }


        check_ast(nd->child, depth + 1,head_symb_tab);
        check_ast(nd->sibling, depth,head_symb_tab);
        
}

is_symb_table* get_symb(is_node* in, is_symb_table* head_func, int is_call){

        if(is_call)
        {
                //----------------------------------------------------------------
                //check for global funcs
                int get_func = 0;
                is_symb_table* symb_tmp;

                char func_params[256] = "";
                char call_params[256] = "";

                int cond = 1;
                is_node* aux_n;
                for (aux_n = in->sibling; aux_n; aux_n = aux_n->sibling){
                        if (cond){
                                cond = 0;
                                strcat(call_params, aux_n->notation);
                        }
                        else{
                                strcat(call_params, ",");
                                strcat(call_params, aux_n->notation);
                        }
                }

                for(symb_tmp = amb_head->symb_tab;symb_tmp;symb_tmp = symb_tmp->next){
                        //----------------------------------------------------------------
                        //if its a function go get the name and type
                        if(symb_tmp->name == NULL){
                                get_func += 1;
                                is_ambient* amb_aux = amb_head;
                                for(int i = 0;i<get_func;i++){
                                        amb_aux = amb_aux->next;
                                }

                                if(strcmp(in->val->token,amb_aux->symb_tab->name)==0){
                                        //----------------------------------------------------------------
                                        // found the function symbol, compare its parameters aswell
                                        cond = 1;

                                        is_symb_table* aux_s;
                                        for (aux_s = amb_aux->symb_tab->next; aux_s && aux_s->is_param; aux_s = aux_s->next){
                                                if (cond){
                                                        cond = 0;
                                                        strcat(func_params, aux_s->type);
                                                }
                                                else{
                                                        strcat(func_params, ",");
                                                        strcat(func_params, aux_s->type);
                                                }
                                        }

                                        
                                        //----------------------------------------------------------------
                                        // check if parameters are equal
                                        if (strcmp(func_params, call_params) != 0) break;

                                        amb_aux->symb_tab->is_used = 1;

                                        return amb_aux->symb_tab;     
                                }
                        }     
                }

                //----------------------------------------------------------------
                //nothing found
                if(strcmp(head_func->type,"undef") != 0)
                        printf("Line %d, column %d: Cannot find symbol %s(%s)\n",in->val->line, in->val->col, in->val->token, call_params);
                errors = 1;
                return NULL;
        }
        else
        {
                //----------------------------------------------------------------
                //check inside own function first
                is_symb_table* symb_tmp;

                for(symb_tmp = head_func->next;symb_tmp;symb_tmp = symb_tmp->next){
                        if(strcmp(in->val->token,symb_tmp->name) == 0){
                                symb_tmp->is_used = 1;
                                return symb_tmp;
                        }         
                }

                //----------------------------------------------------------------
                //check for global vars second
                for(symb_tmp = amb_head->symb_tab;symb_tmp;symb_tmp = symb_tmp->next){
                        if(symb_tmp->name){
                                if(strcmp(in->val->token,symb_tmp->name) == 0){
                                        symb_tmp->is_used = 1;
                                        return symb_tmp;
                                }     
                        }       
                }

                //----------------------------------------------------------------
                //nothing found;
                if(strcmp(head_func->type,"undef") != 0)
                        printf("Line %d, column %d: Cannot find symbol %s\n",in->val->line, in->val->col, in->val->token);
                errors = 1;
                return NULL;
        }

}

is_symb_table* insert_symb(char* p_name, char* p_type, int depth, int new_amb, is_symb_table* head_symb_tab, is_node* in)
{
        is_symb_table* ist = (is_symb_table*)malloc(sizeof(is_symb_table));

        ist->name = p_name;
        ist->type = strdup(p_type);
        ist->type[0] += 32;                     // first letter to lower case
        ist->is_used = 0;
        ist->is_declared = 0;
        ist->line = in->val->line;
        ist->col = in->val->col;
        ist->is_param = 0;
        ist->next = NULL;

        if(amb_head == NULL && new_amb != 1){   //creat ambient head
                amb_head = (is_ambient*)malloc(sizeof(is_ambient));
                amb_head->name = "Global";
                amb_head->symb_tab = ist;
                amb_head->next = NULL;

                symb_head = ist;
                return ist;
        }else if(new_amb){

                is_ambient* ia = (is_ambient*)malloc(sizeof(is_ambient));
                ia->name = "Func";
                ia->symb_tab = ist;
                ia->next = NULL;

                //----------------------------------------------------------------
                //when a function is created add a null symb in global scope
                is_symb_table* tmp_symb;           

                //create null symb
                is_symb_table* ist_null = (is_symb_table*)malloc(sizeof(is_symb_table));
                ist_null->name = NULL;
                ist_null->type = NULL;
                ist_null->next = NULL;

                //----------------------------------------------------------------
                //if function its the head of the global scope
                if(amb_head == NULL){
                        amb_head = (is_ambient*)malloc(sizeof(is_ambient));
                        amb_head->name = "Global";
                        amb_head->symb_tab = ist_null;
                        amb_head->next = NULL;
                //add null symb in global scope and check if new func name equals something else name
                }else{  

                        int check_func = 0;
                        int check = 1;
                        for(tmp_symb = amb_head->symb_tab;tmp_symb->next;tmp_symb = tmp_symb->next){
                                //----------------------------------------------------------------
                                //if is null it means its a function
                                if(tmp_symb->name == NULL){
                                        //----------------------------------------------------------------
                                        //loop through all functions
                                        check_func += 1;
                                        is_ambient* amb_aux = amb_head;
                                        for(int i = 0;i<check_func;i++)amb_aux = amb_aux->next;

                                        if(strcmp(amb_aux->symb_tab->name,p_name)==0){
                                                if(check)printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                                                errors = 1;
                                                ist->type = "undef";
                                                check = 0;
                                        }
                                        //----------------------------------------------------------------
                                }else{
                                        //----------------------------------------------------------------
                                        
                                        if(tmp_symb->name){
                                                if(strcmp(tmp_symb->name,p_name)==0){
                                                        if(check)printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                                                        ist->type = "undef";
                                                        errors = 1;
                                                        check = 0;
                                                }       
                                        }
                                        //----------------------------------------------------------------
                                }
                        }

                        if(tmp_symb->name == NULL && check){
                                //----------------------------------------------------------------
                                //loop through all functions
                                check_func += 1;
                                is_ambient* amb_aux = amb_head;
                                for(int i = 0;i<check_func;i++)amb_aux = amb_aux->next;

                                if(strcmp(amb_aux->symb_tab->name,p_name)==0){
                                        printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                                        errors = 1;
                                        ist->type = "undef";
                                        check = 0;
                                }
                                //----------------------------------------------------------------
                        }else if(check){
                                //----------------------------------------------------------------
                                
                                if(tmp_symb->name){
                                        if(strcmp(tmp_symb->name,p_name)==0){
                                                printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                                                errors = 1;
                                                ist->type = "undef";
                                                check = 0;
                                        }       
                                }
                                //----------------------------------------------------------------
                        }
                        tmp_symb->next = ist_null;    
                }
                
                //----------------------------------------------------------------
                //add new ambient
                is_ambient* tmp_amb;

                for(tmp_amb = amb_head;tmp_amb->next;tmp_amb = tmp_amb->next);

                tmp_amb->next = ia;
                //----------------------------------------------------------------

                symb_head = ist;
                return ist;
        }else if(depth == 0){
                //----------------------------------------------------------------
                //we changed to global scope
                symb_head = amb_head->symb_tab;
        }else if(depth == 3){
                ist->is_param = 1;
                ist->is_declared = 1;
                int cond = 1;
                is_symb_table* tmp_last_symb;

                if(head_symb_tab->next == NULL){
                        head_symb_tab->next = ist;
                        return NULL;
                }

                for(tmp_last_symb = head_symb_tab->next;tmp_last_symb->next;tmp_last_symb = tmp_last_symb->next){
                        if(strcmp(tmp_last_symb->name,p_name)==0){
                                if(strcmp(symb_head->type,"undef") != 0 && cond) printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                                errors = 1;
                                ist->type = "undef";
                                cond = 0;
                        }  
                }

                if(strcmp(tmp_last_symb->name,p_name)==0){
                        if(strcmp(symb_head->type,"undef") != 0 && cond) printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                        errors = 1;
                        ist->type = "undef";
                        cond = 0;
                }

                tmp_last_symb->next = ist;
                return NULL;

        }

        if(head_symb_tab == NULL){
                symb_head = amb_head->symb_tab;
        }else{
                symb_head = head_symb_tab;
        }

        is_symb_table* tmp_last_symb;

        //----------------------------------------------------------------
        //go to the last symb in the scope we are in
        int check_func = 0;
        int check = 1;
        for(tmp_last_symb = symb_head;tmp_last_symb->next;tmp_last_symb = tmp_last_symb->next){
                if(tmp_last_symb->name && check){
                        if(strcmp(tmp_last_symb->name,p_name)==0){
                                if(strcmp(symb_head->type,"undef") != 0)printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                                errors = 1;
                                ist->type = "undef";
                                check = 0;
                        }       
                }else if(check){
                        check_func += 1;
                        is_ambient* amb_aux = amb_head;
                        for(int i = 0;i<check_func;i++)amb_aux = amb_aux->next;

                        if(strcmp(amb_aux->symb_tab->name,p_name)==0){
                                printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                                errors = 1;
                                ist->type = "undef";
                                check = 0;
                        }
                }
                
        }

        if(tmp_last_symb->name && check){
                if(strcmp(tmp_last_symb->name,p_name)==0){
                        if(strcmp(symb_head->type,"undef") != 0)printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                        errors = 1;
                        ist->type = "undef";
                }       
        }else if(check){
                check_func += 1;
                is_ambient* amb_aux = amb_head;
                for(int i = 0;i<check_func;i++)amb_aux = amb_aux->next;

                if(strcmp(amb_aux->symb_tab->name,p_name)==0){
                        printf("Line %d, column %d: Symbol %s already defined\n",in->val->line, in->val->col, p_name);
                        errors = 1;
                        ist->type = "undef";
                        check = 0;
                }
        }

        tmp_last_symb->next = ist;
        return NULL;
}

void check_unused_symbs(){

        is_ambient* tmp_amb;
        is_symb_table* tmp_symb;

        if (amb_head == NULL) return;

        for(tmp_amb = amb_head->next;tmp_amb;tmp_amb = tmp_amb->next){

                if(strcmp(tmp_amb->symb_tab->type,"undef") == 0){
                        continue;
                }

                for(tmp_symb = tmp_amb->symb_tab->next;tmp_symb;tmp_symb = tmp_symb->next){
                        if(tmp_symb->name != NULL){
                                if(tmp_symb->is_used == 0 && tmp_symb->is_param == 0 && strcmp(tmp_symb->type,"undef") != 0){
                                        printf("Line %d, column %d: Symbol %s declared but never used\n",tmp_symb->line,tmp_symb->col,tmp_symb->name);
                                        errors = 1;        
                                }
                        }
                }
        }      
}

void print_global(int print){

        if(errors || amb_head == NULL) return;

        is_ambient* tmp_amb;
        
        if(print) printf("===== Global Symbol Table =====\n");
        print_symb_tab(amb_head->symb_tab,print);

        for(tmp_amb = amb_head->next;tmp_amb;tmp_amb = tmp_amb->next){
                //----------------------------------------------------------------
                //print function name and params
                if(print)printf("===== Function");
                is_symb_table* tmp = tmp_amb->symb_tab;
                if(print)printf(" %s(",tmp->name);
                int cond = 1;
                for(tmp = tmp->next;tmp && tmp->is_param;tmp = tmp->next){
                        if (cond){
                                cond = 0;
                                if(print)printf("%s",tmp->type);
                        }
                        else
                                if(print)printf(",%s", tmp->type);
                }
                if(print)printf(") Symbol Table =====\n");
                //----------------------------------------------------------------
                //printf return type
                if(print)printf("return\t\t%s\n",tmp_amb->symb_tab->type);
                //----------------------------------------------------------------
                //print rest of the symbs in the table
                print_symb_tab(tmp_amb->symb_tab->next,print);
                //----------------------------------------------------------------
        }
}

int print_func = 0;
void print_symb_tab(is_symb_table* symb_head,int print){
        is_symb_table* tmp_symb;

        for(tmp_symb = symb_head;tmp_symb;tmp_symb = tmp_symb->next){
                //----------------------------------------------------------------
                //if is null it means its a function
                if(tmp_symb->name == NULL){
                        //----------------------------------------------------------------
                        //loop through all functions
                        print_func += 1;
                        is_ambient* amb_aux = amb_head;
                        for(int i = 0;i<print_func;i++)amb_aux = amb_aux->next;
                        //----------------------------------------------------------------
                        //print function params
                        print_func_params(amb_aux, print);
                        //----------------------------------------------------------------
                }else{
                        //----------------------------------------------------------------
                        //print var types or param types
                        if(print)printf("%s\t\t%s",tmp_symb->name,tmp_symb->type);
                        if(tmp_symb->is_param){
                                if(print)printf("\t%s","param");
                        }
                        if(print)printf("\n");
                        //----------------------------------------------------------------
                }
        }
        if(print)printf("\n");
}

void print_func_params(is_ambient* func_head, int print){
        is_symb_table* tmp = func_head->symb_tab;
        if(print)printf("%s\t(",tmp->name);
        int cond = 1;
        for(tmp = tmp->next;tmp && tmp->is_param;tmp = tmp->next){
                if (cond){
                        cond = 0;
                        if(print)printf("%s",tmp->type);
                }
                else
                        if(print)printf(",%s", tmp->type);
        }
        if(print)printf(")\t%s\n",func_head->symb_tab->type);
}

char* convert_type(char* type)
{
        if (strcmp(type, "Mul") == 0)
                return "*";
        else if (strcmp(type, "Not") == 0)
                return "!";
        else if (strcmp(type, "Sub") == 0 || strcmp(type, "Minus") == 0)
                return "-";
        else if (strcmp(type, "Div") == 0)
                return "/";
        else if (strcmp(type, "Mod") == 0)
                return "%";
        else if (strcmp(type, "Add") == 0 || strcmp(type, "Plus") == 0)
                return "+";
        else if (strcmp(type, "Assign") == 0)
                return "=";
        else if (strcmp(type, "ParseArgs") == 0)
                return "strconv.Atoi";
        else if (strcmp(type,"Print") == 0)
                return "fmt.Println";
        else if (strcmp(type, "Or") == 0)
                return "||";
        else if (strcmp(type, "And") == 0)
                return "&&";
        else if (strcmp(type, "Lt") == 0)
                return "<";
        else if (strcmp(type, "Gt") == 0)
                return ">";
        else if (strcmp(type, "Eq") == 0)
                return "==";
        else if (strcmp(type, "Ne") == 0)
                return "!=";
        else if (strcmp(type, "Le") == 0)
                return "<=";
        else if (strcmp(type, "Ge") == 0)
                return ">=";

        return "default";
}

//-----------------------------------
// clear ast functions
//-----------------------------------

void free_ast(is_node* start){
        if (start == NULL) return;

        if(start->sibling)
                free_ast(start->sibling);

        if (start->child)
                free_ast(start->child);

        /*if (start->token) printf("Freed node %s(%s)\n", start->type, start->token);
        else printf("Freed node %s\n", start->type);*/

        if(start->val != NULL)
        {
                free(start->val->token);
                free(start->val);
        }
        free(start);

        return;
}

//-----------------------------------
// generate llvm code
//-----------------------------------

int temp_counter = 1;
int print_int = 0;
int print_double = 0;
int print_string = 0;
int print_atoi = 0;
is_string_list* isl_head;
int llvm_func_counter = 0;

int if_counter = 0;

int for_counter = 0;

void set_declared_local_var(is_node* in){
        //get current function

        int func = 0;
        is_symb_table* symb_tmp;
        is_ambient* amb_aux = NULL;
        for(symb_tmp = amb_head->symb_tab;symb_tmp && llvm_func_counter != 0;symb_tmp = symb_tmp->next){
                //----------------------------------------------------------------
                //if is null it means its a function
                if(symb_tmp->name == NULL){
                        //----------------------------------------------------------------
                        //loop through all functions
                        func += 1;
                        if(llvm_func_counter == func){
                                amb_aux = amb_head;
                                for(int i = 0;i<llvm_func_counter;i++)amb_aux = amb_aux->next;      
                        }
                }
        }
        //----------------------------------------------------------------
        //check for function vars first
        for(symb_tmp = amb_aux->symb_tab;symb_tmp;symb_tmp = symb_tmp->next){
                if(strcmp(in->val->token,symb_tmp->name) == 0){
                        symb_tmp->is_declared = 1;
                }         
        }
}

int check_global(is_node* in){
        //get current function
        int func = 0;
        is_symb_table* symb_tmp;
        is_ambient* amb_aux = NULL;
        for(symb_tmp = amb_head->symb_tab;symb_tmp && llvm_func_counter != 0;symb_tmp = symb_tmp->next){
                //----------------------------------------------------------------
                //if is null it means its a function
                if(symb_tmp->name == NULL){
                        //----------------------------------------------------------------
                        //loop through all functions
                        func += 1;
                        if(llvm_func_counter == func){
                                amb_aux = amb_head;
                                for(int i = 0;i<llvm_func_counter;i++)amb_aux = amb_aux->next;      
                        }
                }
        }

        //----------------------------------------------------------------
        //check for function vars first
        for(symb_tmp = amb_aux->symb_tab;symb_tmp;symb_tmp = symb_tmp->next){
                if(strcmp(in->val->token,symb_tmp->name) == 0 && symb_tmp->is_declared){
                        return 1;
                }         
        }
        return 0;
}

int first_param_save = 0;

void generate_llvm(is_node* in, int depth) {

        if (in == NULL || errors == 1){      
                return;         
        } 

        if (strcmp(in->type, "VarDecl") == 0) {
                // global var declarations
                if (depth == 0) {
                        printf("@%s = global %s ", in->child->sibling->val->token, llvm_types(in->child->type));

                        // global variables must be initialized
                        if (strcmp(in->child->type, "Float32") == 0) printf("0.0\n");
                        else printf("0\n");
                }
                // local variables
                else{   
                        set_declared_local_var(in->child->sibling);
                        printf("\t%%%s = alloca %s\n",in->child->sibling->val->token,llvm_types(in->child->type));
                        printf("\tstore %s ",llvm_types(in->child->type));
                        if (strcmp(in->child->type, "Float32") == 0) printf("0.0");
                        else printf("0");
                        printf(", %s* %%%s\n",llvm_types(in->child->type),in->child->sibling->val->token);
                        
                }

                // skip to sibling
                generate_llvm(in->sibling, depth);
                return;
        }

        else if (strcmp(in->type, "FuncDecl") == 0) {
                llvm_func_counter+=1;   //current function
                

                printf("\ndefine ");
                if (strcmp(in->child->child->sibling->type, "FuncParams") != 0) printf("%s", llvm_types(in->child->child->sibling->type));
                else{
                        if (strcmp(in->child->child->val->token,"main") == 0) printf("i32");
                        else printf("void");
                }
                printf(" @%s(", in->child->child->val->token);

                if(strcmp(in->child->child->val->token,"main") == 0){
                        temp_counter = 3;
                        printf("i32, i8**) {\n");

                }else{
                        temp_counter = 1; //reset temp vars
                        if (strcmp(in->child->child->sibling->type, "FuncParams") != 0){
                                print_llvm_params(in->child->child->sibling->sibling->child);
                        }else{
                                print_llvm_params(in->child->child->sibling->child);
                        }
                }

                
                generate_llvm(in->child, depth+1);
                
                //print default return
                if(strcmp(in->child->child->sibling->type, "FuncParams") != 0){
                        printf("\tret %s ",llvm_types(in->child->child->sibling->type));
                        if (strcmp(in->child->child->sibling->type, "Float32") == 0) printf("0.0\n");
                        else printf("0\n");    
                }else{
                        if (strcmp(in->child->child->val->token,"main") == 0){
                                printf("\tret i32 0\n");
                        }
                        else {
                                printf("\tret void\n"); 
                        }
                }
                
                
                printf("}\n");

                generate_llvm(in->sibling, depth);
                return;

        }else if(strcmp(in->type, "Return") == 0){
                if(in->child){
                        int tmp1 = print_llvm_operation(in->child);

                        if(tmp1 == -1){
                                printf("\tret %s %s\n",llvm_types(in->child->notation),in->child->val->token);
                        }else{
                                printf("\tret %s %%%d\n",llvm_types(in->child->notation),temp_counter-1);
                        }               
                               
                }else{
                        printf("\tret\n"); 
                }

                temp_counter++;

                generate_llvm(in->sibling,depth);
                return;
                                
        }else if(strcmp(in->type,"Assign") == 0){
                int tmp1 = print_llvm_operation(in->child->sibling);

                if(tmp1 == -1){
                        
                        if(check_global(in->child))
                                printf("\tstore %s %s, %s* %%%s\n",llvm_types(in->notation),in->child->sibling->val->token,llvm_types(in->notation),in->child->val->token);
                        else
                                printf("\tstore %s %s, %s* @%s\n",llvm_types(in->notation),in->child->sibling->val->token,llvm_types(in->notation),in->child->val->token);
                }else{
                        if(check_global(in->child))
                                printf("\tstore %s %%%d, %s* %%%s\n",llvm_types(in->notation),temp_counter-1,llvm_types(in->notation),in->child->val->token);
                        else
                                printf("\tstore %s %%%d, %s* @%s\n",llvm_types(in->notation),temp_counter-1,llvm_types(in->notation),in->child->val->token); 
                }
                generate_llvm(in->sibling,depth);
                return;
        }else if(strcmp(in->type,"Print") == 0){
                int tmp1 = print_llvm_operation(in->child);

                if(tmp1 == -1){
                        //change float to int
                        /*int is_int = 0;
                        if(strcmp(in->child->type, "RealLit") == 0){
                                is_int = 1;
                                for(int i = strlen(in->child->val->token)-1;i>0;i--){
                                        if(in->child->val->token[i] == '.'){
                                                in->child->val->token[i] = '\0';
                                                break;
                                        }
                                        if(in->child->val->token[i] != '0'){
                                                is_int = 0;
                                                break;
                                        }
                                }     
                        }

                        if(is_int && strcmp(in->child->type, "RealLit") == 0){
                                print_int = 1;
                                printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.int, i32 0, i32 0), i32 %s)\n",temp_counter, in->child->val->token);   
                        }
                        else*/ if(strcmp(in->child->notation,"int") == 0){
                                print_int = 1;
                                printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.int, i32 0, i32 0), %s %s)\n",temp_counter,llvm_types(in->child->notation), in->child->val->token);
                        }
                        else{
                                print_double = 1;
                                printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.double, i32 0, i32 0), %s %s)\n",temp_counter,llvm_types(in->child->notation), in->child->val->token);
                        }
                }else{
                        if(strcmp(in->child->notation,"int") == 0){
                                print_int = 1;
                                printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.int, i32 0, i32 0), %s %%%d)\n",temp_counter,llvm_types(in->child->notation), temp_counter-1);
                        }else if(strcmp(in->child->notation,"bool") == 0){
                                printf("\t%%%d = icmp eq i1 %%%d, 1\n",temp_counter++,tmp1);
                                if_counter++;
                                printf("\tbr i1 %%%d, label %%then%d, label %%else%d\n",temp_counter-1,if_counter,if_counter);

                                printf("then%d:\n",if_counter);
                                print_string++;
                                is_string_list* isl_tmp = insert_string_list("true");
                                printf("\t%%%d = call i32 @puts(i8* getelementptr inbounds ([%d x i8], [%d x i8]* @.str.%d, i32 0, i32 0))\n",temp_counter++,isl_tmp->size_llvm ,isl_tmp->size_llvm , print_string);
                                printf("\tbr label %%ifcont%d\n",if_counter);

                                printf("else%d:\n",if_counter);
                                print_string++;
                                isl_tmp = insert_string_list("false");
                                printf("\t%%%d = call i32 @puts(i8* getelementptr inbounds ([%d x i8], [%d x i8]* @.str.%d, i32 0, i32 0))\n",temp_counter,isl_tmp->size_llvm ,isl_tmp->size_llvm , print_string);
                                printf("\tbr label %%ifcont%d\n",if_counter);


                                printf("ifcont%d:\n",if_counter);
                        }
                        else if(strcmp(in->child->notation,"string") == 0){
                                print_string++;
                                is_string_list* isl_tmp;
                                if(strcmp(in->child->type,"Id") == 0){
                                        isl_tmp = insert_string_list(""); 
                                }else{
                                        isl_tmp = insert_string_list(in->child->val->token); 
                                }
                                
                                printf("\t%%%d = call i32 @puts(i8* getelementptr inbounds ([%d x i8], [%d x i8]* @.str.%d, i32 0, i32 0))\n",temp_counter,isl_tmp->size_llvm ,isl_tmp->size_llvm , print_string);
                        }
                        else{
                                print_double = 1;
                                printf("\t%%%d = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.double, i32 0, i32 0), %s %%%d)\n",temp_counter,llvm_types(in->child->notation), temp_counter-1);
                        }
                }
                temp_counter++;

                generate_llvm(in->sibling,depth);
                return;
        }
        else if (strcmp(in->type, "If") == 0){
                if_counter++;
                int if_save = if_counter;

                int tmp1 = print_llvm_operation(in->child);

                printf("\tbr i1 %%%d, label %%then%d, label %%else%d\n", tmp1, if_save, if_save);

                //then label
                printf("then%d:\n", if_save);
                generate_llvm(in->child->sibling->child, depth+2);
                printf("\tbr label %%ifcont%d\n", if_save); //continue the if   

                //else label
                printf("else%d:\n",if_save);
                generate_llvm(in->child->sibling->sibling->child, depth+2);
                printf("\tbr label %%ifcont%d\n", if_save); //continue the if

                printf("ifcont%d:\n", if_save);


                generate_llvm(in->sibling, depth);
                return;
        }else if(strcmp(in->type,"For") == 0){

                if(strcmp(in->child->type, "Block") == 0){
                        generate_llvm(in->sibling,depth);
                        return;                        
                }

                for_counter++;
                int for_save = for_counter;

                int tmp1 = print_llvm_operation(in->child);

                printf("\tbr i1 %%%d, label %%for%d, label %%forcont%d\n", tmp1, for_save, for_save);
                printf("for%d:\n",for_save);

                generate_llvm(in->child->sibling->child,depth+2);

                tmp1 = print_llvm_operation(in->child);
                printf("\tbr i1 %%%d, label %%for%d, label %%forcont%d\n", tmp1, for_save, for_save);
                printf("forcont%d:\n", for_save);

                generate_llvm(in->sibling,depth);
                return;
        }else if(strcmp(in->type,"ParseArgs") == 0){
                print_atoi = 1;
                int tmp1 = print_llvm_operation(in->child->sibling);
                
                if(tmp1 == -1){
                        printf("\t%%%d = getelementptr inbounds i8*, i8** %%1, i32 %s\n",temp_counter,in->child->sibling->val->token);   
                }else{
                        printf("\t%%%d = getelementptr inbounds i8*, i8** %%1, i32 %%%d\n",temp_counter,tmp1);
                }
                temp_counter++;
                printf("\t%%%d = load i8*, i8** %%%d\n",temp_counter,temp_counter-1);
                temp_counter++;
                
                printf("\t%%%d = call i32 @atoi(i8* %%%d)\n",temp_counter,temp_counter-1);
                temp_counter++;
                
                if(check_global(in->child))
                        printf("\tstore %s %%%d, %s* %%%s\n",llvm_types(in->notation),temp_counter-1,llvm_types(in->notation),in->child->val->token);
                else
                        printf("\tstore %s %%%d, %s* @%s\n",llvm_types(in->notation),temp_counter-1,llvm_types(in->notation),in->child->val->token);
        }else if(strcmp(in->type,"Call") == 0){
                if(in->child->sibling == NULL){ //without arguments
                        if(strcmp(in->notation,"none") == 0){
                                printf("\tcall void @%s()\n",in->child->val->token);
                                temp_counter--;
                        }else{
                                printf("\tcall %s @%s()\n",llvm_types(in->notation),in->child->val->token);
                        }     
                }else{

                        is_node* in_temp;

                        first_param_save = temp_counter;

                        for(in_temp = in->child->sibling;in_temp;in_temp = in_temp->sibling){
                                print_llvm_operation(in_temp);
                                in_temp->temp_num = temp_counter - 1;

                        }

                        if(strcmp(in->notation,"none") == 0){
                                printf("\tcall void @%s(",in->child->val->token);
                                temp_counter--;
                        }else{
                                printf("\tcall %s @%s(",llvm_types(in->notation),in->child->val->token); 
                        }

                        print_call_params(in->child->sibling,1);
                        printf(")\n");
                }
                temp_counter++;
                generate_llvm(in->sibling, depth);
                return;               
        }

        generate_llvm(in->child, depth+1);
        generate_llvm(in->sibling, depth);
                
}

void print_call_params(is_node* in, int cond){
        if(in == NULL) return;

        if(strcmp(in->type,"Call") == 0){

                if(cond){
                        printf("%s %%%d",llvm_types(in->notation),in->temp_num);
                        cond = 0;
                }else{
                        printf(", %s %%%d",llvm_types(in->notation),in->temp_num);
                }

                print_call_params(in->sibling,cond);
                return;
        }

        if(in->val->token){
                if(cond){
                        if(strcmp(in->type,"Id")==0){
                                printf("%s %%%d",llvm_types(in->notation),in->temp_num);
                        }else{
                                printf("%s %s",llvm_types(in->type),in->val->token);
                        }
                        cond = 0;
                                
                }else{
                        if(strcmp(in->type,"Id")==0){
                                printf(", %s %%%d",llvm_types(in->notation),in->temp_num);
                        }else{
                                printf(", %s %s",llvm_types(in->type),in->val->token);
                        }
                }
                                 
        }else{
                if(cond){
                        printf("%s %%%d",llvm_types(in->notation),in->temp_num);
                        cond = 0;        
                }else{
                        printf(", %s %%%d",llvm_types(in->notation),in->temp_num);
                }
        }       
                        
        print_call_params(in->sibling,cond);
}

void generate_llvm_prints() {
        if (print_int) {
                printf("@.int = private unnamed_addr constant [4 x i8] c\"%%d\\0A\\00\"\n");
        }
        if (print_double) {
                printf("@.double = private unnamed_addr constant [7 x i8] c\"%%.08f\\0A\\00\"\n");
        }

        if (print_int || print_double) printf("declare dso_local i32 @printf(i8*, ...)\n");

        if (print_string){
                is_string_list* isl_tmp;
                int str_counter = 1;
                for (isl_tmp = isl_head; isl_tmp; isl_tmp = isl_tmp->next){
                        printf("@.str.%d = private unnamed_addr constant [%d x i8] c\"%s\\00\"\n", str_counter++, isl_tmp->size_llvm, isl_tmp->str);
                }

                printf("declare dso_local i32 @puts(i8*)\n");
        }
        if(print_atoi){
                printf("declare dso_local i32 @atoi(i8*)\n");
        }
        
}

is_string_list* insert_string_list(char* string){
        is_string_list* isl = (is_string_list*)malloc(sizeof(is_string_list));

        char* str_final = (char*)malloc(strlen(string) + strlen(string)/2);
        int final_size = 0;

        int current = 0;

        for(int i = 0;i<strlen(string);i++){
                if(string[i] == '\\'){
                        i++;
                        str_final[current++] = '\\';
                        if(string[i] == '\\'){
                                str_final[current++] = '5';
                                str_final[current++] = 'C';
                                final_size += 1;
                        }else if(string[i] == '\"'){
                                str_final[current++] = '2';
                                str_final[current++] = '2';
                                final_size += 1;       
                        }else if(string[i] == 'n'){
                                str_final[current++] = '0';
                                str_final[current++] = 'A';
                                final_size += 1;
                        }else if(string[i] == 'f'){
                                str_final[current++] = '0';
                                str_final[current++] = 'C';
                                final_size += 1;
                        }else if(string[i] == 'r'){
                                str_final[current++] = '0';
                                str_final[current++] = 'D';
                                final_size += 1;
                        }else if(string[i] == 't'){
                                str_final[current++] = '0';
                                str_final[current++] = '9';
                                final_size += 1;
                        }
                }else{
                        str_final[current++] = string[i];
                        final_size += 1;
                }
        }

        str_final[current] = '\0';

        isl->str = strdup(str_final);

        free(str_final);

        isl->size_llvm = final_size+1;

        isl->next = NULL;

        if (isl_head == NULL) {
                isl_head = isl;
                return isl;
        }

        is_string_list* isl_tmp;
        for (isl_tmp = isl_head; isl_tmp->next; isl_tmp = isl_tmp->next);
        isl_tmp->next = isl;

        return isl;
}

void print_llvm_params(is_node* in){
        if(in == NULL) {
                printf(") {\n");
                return;
        }

        is_node* is_tmp;
        int cond = 1;
        for(is_tmp = in;is_tmp;is_tmp = is_tmp->sibling){
                temp_counter++;
                if(cond){
                        printf("%s",llvm_types(is_tmp->child->type));
                        cond = 0;
                        continue;
                }
                printf(", %s",llvm_types(is_tmp->child->type));
        }
        printf(") {\n");

        int param_counter = 0;
        for(is_tmp = in;is_tmp;is_tmp = is_tmp->sibling){
                printf("\t%%%s = alloca %s\n", is_tmp->child->sibling->val->token,llvm_types(is_tmp->child->type));
                printf("\tstore %s %%%d, %s* %%%s\n",llvm_types(is_tmp->child->type),param_counter++,llvm_types(is_tmp->child->type),is_tmp->child->sibling->val->token);
        }


}

int print_llvm_operation(is_node* in){
        if(in == NULL) return -2;

        if(strcmp(in->type,"IntLit") == 0 || strcasecmp(in->type, "RealLit") == 0){
                return -1;
        
        }else if(strcmp(in->type,"Call") == 0){
                is_node* in_temp;

                first_param_save = temp_counter;

                for(in_temp = in->child->sibling;in_temp;in_temp = in_temp->sibling){
                        print_llvm_operation(in_temp);
                        in_temp->temp_num = temp_counter - 1;
                }

                if(strcmp(in->notation,"none") == 0){
                        printf("\t%%%d = call void @%s(",temp_counter++,in->child->val->token);
                }else{
                        printf("\t%%%d = call %s @%s(",temp_counter++,llvm_types(in->notation),in->child->val->token); 
                }
                print_call_params(in->child->sibling,1);
                printf(")\n");

                return temp_counter - 1;
        }

        int tmp1 = print_llvm_operation(in->child);

        if(strcmp(in->type,"Id") == 0){
                if(check_global(in)){
                        printf("\t%%%d = load %s, %s* %%%s\n",temp_counter++,llvm_types(in->notation),llvm_types(in->notation),in->val->token);      
                }else{
                        printf("\t%%%d = load %s, %s* @%s\n",temp_counter++,llvm_types(in->notation),llvm_types(in->notation),in->val->token);
                }

                return temp_counter-1;
                
        }



        if(tmp1 == -2) return 0;

        int tmp2 = print_llvm_operation(in->child->sibling);    

        if(in->val->token == NULL){
                if(strcmp(in->type,"Not") == 0){
                        printf("\t%%%d = xor i1 1,",temp_counter++);

                        if(tmp1 == -1){
                                printf(" %s\n",in->child->val->token);
                        }else{
                                printf(" %%%d\n",tmp1);
                        }

                        return temp_counter-1;
                }else if(strcmp(in->type,"Plus") == 0){
                        if(strcmp(in->notation,"int") == 0)
                                printf("\t%%%d = add %s 0,",temp_counter++,llvm_types(in->notation));
                        else
                                printf("\t%%%d = fadd %s 0.0,",temp_counter++,llvm_types(in->notation));

                        if(tmp1 == -1){
                                printf(" %s\n",in->child->val->token);
                        }else{
                                printf(" %%%d\n",tmp1);
                        }

                        return temp_counter-1;
                }else if(strcmp(in->type,"Minus") == 0){
                        if(strcmp(in->notation,"int") == 0)
                                printf("\t%%%d = sub %s 0,",temp_counter++,llvm_types(in->notation));
                        else
                                printf("\t%%%d = fsub %s -0.0,",temp_counter++,llvm_types(in->notation));

                        if(tmp1 == -1){
                                printf(" %s\n",in->child->val->token);
                        }else{
                                printf(" %%%d\n",tmp1);
                        }

                        return temp_counter-1;
                }else if(strcmp(in->type,"Eq") == 0 || strcmp(in->type,"Ne") == 0 || strcmp(in->type,"Lt") == 0 || strcmp(in->type,"Gt") == 0 || strcmp(in->type,"Le") == 0 || strcmp(in->type,"Ge") == 0){
                        if(strcmp(in->child->notation,"int") == 0 || strcmp(in->child->notation,"bool") == 0){
                                printf("\t%%%d = icmp %s %s",temp_counter++,llvm_opetators(in->type,0),llvm_types(in->child->notation));       
                        }else{
                                printf("\t%%%d = fcmp %s %s",temp_counter++,llvm_opetators(in->type,1),llvm_types(in->child->notation));
                        }
                }else{


                        if(strcmp(in->notation,"int") == 0){
                                printf("\t%%%d = %s %s",temp_counter++,llvm_opetators(in->type,0),llvm_types(in->notation));       
                        }else{
                                printf("\t%%%d = %s %s",temp_counter++,llvm_opetators(in->type,1),llvm_types(in->notation));
                        }
                }

                //left child is terminal
                if(tmp1 == -1){
                        printf(" %s, ",in->child->val->token);
                }else{
                        printf(" %%%d, ",tmp1);
                }

                //right child is terminal
                if(tmp2 == -1){
                        printf("%s\n", in->child->sibling->val->token);
                }else{
                        printf("%%%d\n",tmp2);
                }

                return temp_counter-1;
        }

        return 0;
}

char* llvm_types(char* type) {
        if (strcasecmp(type, "Int") == 0 || strcasecmp(type, "IntLit") == 0)
                return "i32";
        else if (strcasecmp(type, "Float32") == 0 || strcasecmp(type, "RealLit") == 0)
                return "double";
        else if (strcasecmp(type, "String") == 0)
                return "i8";
        else if (strcasecmp(type, "Bool") == 0)
                return "i1";
        else 
                return "default";
}

char* llvm_opetators(char* operator,int is_float) {
        if (strcasecmp(operator, "Mod") == 0){
                if(is_float){
                        return "frem";
                }
                return "srem";
        }else if(strcasecmp(operator, "Add") == 0){
                if(is_float){
                        return "fadd";
                }
                return "add";
        }else if(strcasecmp(operator, "Sub") == 0){
                if(is_float){
                        return "fsub";
                }
                return "sub";
        }else if(strcasecmp(operator, "Mul") == 0){
                if(is_float){
                        return "fmul";
                }
                return "mul";
        }else if(strcasecmp(operator, "Div") == 0){
                if(is_float){
                        return "fdiv";
                }
                return "sdiv";
        }else if(strcasecmp(operator, "Not") == 0)
                return "xor";
        else if(strcasecmp(operator, "Minus") == 0)
                return "mul";
        else if(strcasecmp(operator, "Plus") == 0)
                return "add";
        else if(strcasecmp(operator, "Or") == 0)
                return "or";
        else if(strcasecmp(operator, "And") == 0)
                return "and";
        else if(strcasecmp(operator, "Eq") == 0){
                if(is_float){
                        return "oeq";
                }
                return "eq";
        }
        else if(strcasecmp(operator, "Ne") == 0){
                if(is_float){
                        return "one";
                }
                return "ne";
        }
        else if(strcasecmp(operator, "Lt") == 0){
                if(is_float){
                        return "olt";
                }
                return "slt";
        }
        else if(strcasecmp(operator, "Gt") == 0){
                if(is_float){
                        return "ogt";
                }
                return "sgt";
        }
        else if(strcasecmp(operator, "Le") == 0){
                if(is_float){
                        return "ole";
                }
                return "sle";
        }
        else if(strcasecmp(operator, "Ge") == 0){
                if(is_float){
                        return "oge";
                }
                return "sge";
        }
        else
                return "default";
}
