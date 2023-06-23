  	//  "functions.h"
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
    //  this file contains the declarations of the
    //  functions used throughout the program

#include "structures.h"

//-----------------------------------
// ast management functions
//-----------------------------------

is_node* insert_block(is_node* node, int add_sibling);
is_node* insert_sibling(is_node* brother, is_node* node);
is_node* insert_terminal(is_value* value, char* type);
is_node* insert_node(is_value* value,char* type, is_node* expr1, is_node* expr2);
void change_type(is_node* start, char* new_type);
is_value* create_value(char* token, int line, int col);

//-----------------------------------
// print ast
//-----------------------------------

void print_program(is_node* start, int depth);

//-----------------------------------
// symbol table build functions
//-----------------------------------

void check_ast(is_node* nd, int depth, is_symb_table* head_symb_tab);
is_symb_table* get_symb(is_node* in, is_symb_table* head_func, int is_call);
is_symb_table* insert_symb(char* p_name, char* p_type, int depth, int new_amb, is_symb_table* head_symb_tab, is_node* in);
void check_unused_symbs();
void print_global(int print);
void print_symb_tab(is_symb_table* symb_head,int print);
void print_func_params(is_ambient* func_head,int print);
char* convert_type(char* type);

//-----------------------------------
// clear ast functions
//-----------------------------------

void free_ast(is_node* start);

//-----------------------------------
// generate llvm code
//-----------------------------------

void set_declared_local_var(is_node* in);
void generate_llvm(is_node* in, int depth);
void print_call_params(is_node* in, int cond);
void generate_llvm_prints();
is_string_list* insert_string_list(char* string);
char* llvm_types(char* type);
void print_llvm_params(is_node* in);
int print_llvm_operation(is_node* in);
char* llvm_opetators(char* operator,int is_float);