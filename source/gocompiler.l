	//	"gocompiler.l"
	//
	//	====================================
	//
	//	Universidade de Coimbra
	//	Faculdade de Ciências e Tecnologia
	//	Departamento de Engenharia Informatica
	//
	//	Daniel Gonçalves Portovedo - 2019214315
	//	Luís Miguel Gomes Batista  - 2019214869
	//
	//	====================================
	//
	//	this file is used to lexically analyse
	//	deiGo coding language

	// lex start states
%X MULTI_COMMENTS
%X STRING_LIT

	// lex pre declarations
%{
	#include "functions.h"
	#include "structures.h"			// include structures
	#include "y.tab.h"				// include yacc

	extern int token_status;		// declared in gocompiler.y
	int column = 1, line = 1;
	int comment_status = 0;
	int comment_line = 0, comment_col = 0;
	int semi_col_status = 0;
	int str_start = 0, str_valid = 0;

	int strlit = 0;
	int newline = 0, column_save = 0;

	void printToken(char* token, char* yytext, int yyleng, int semicol);
	void logError(char* message, char* yytext, int yyleng, int l, int c);
	void resolveIntLit(char* yytext, int yyleng);
	void printStrToken(char* yytext);
	void checkForSemiColon(void);
	void endLex(void);
	char* convert_hex_oct(char* int_str);
	char* convert_exp(char* exp_str);
%}

	// tokens declaration
ID						[a-zA-Z_]([a-zA-Z_]|[0-9])*
INTLIT					[1-9][0-9]*|0[0-9]*|0[xX][0-9|a-f|A-F]+
REALLIT					[0-9]+"."[0-9]*([eE][-+]?[0-9]+)?|[0-9]+[eE][-+]?[0-9]+|"."[0-9]+([eE][-+]?[0-9]+)?
SEMICOLON 				";"
COMMA 					","
BLANKID					"_"
ASSIGN					"="
STAR					"*"
DIV						"/"
MINUS					"-"
PLUS					"+"
EQ						"=="
GE 						">="
GT						">"
LBRACE					"{"
LE 						"<="
LPAR 					"("
LSQ						"["
LT 						"<"
MOD 					"%"
NE 						"!="
NOT 					"!"
AND 					"&&"
OR 						"||"
RBRACE 					"}"
RPAR 					")"
RSQ 					"]"
PACKAGE 				"package"
RETURN 					"return"
ELSE 					"else"
FOR 					"for"
IF 						"if"
VAR 					"var"
INT 					"int"
FLOAT32 				"float32"
BOOL 					"bool"
STRING 					"string"
PRINT 					"fmt.Println"
PARSEINT 				"strconv.Atoi"
FUNC 					"func"
CMDARGS 				"os.Args"
LINE_COMMENTS			"//"[^\n\r]*
START_MULTI_COMMENTS	"/*"
RESERVED				(break|case|chan|const|continue|default|defer|fallthrough|go|goto|import|interface|map|range|select|struct|switch|type|"++"|"--")

	// definitions
%%

{SEMICOLON} 				{strlit = 0; newline = 0; printToken("SEMICOLON", "", yyleng, 0); return SEMICOLON;}
{COMMA} 					{strlit = 0; newline = 0; printToken("COMMA", "", yyleng, 0); return COMMA;}
{BLANKID}					{strlit = 0; newline = 0; printToken("BLANKID", "", yyleng, 0); return BLANKID;}
{ASSIGN}					{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("ASSIGN", "", yyleng, 0); return ASSIGN;}
{STAR}						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("STAR", "", yyleng, 0); return STAR;}
{DIV}						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("DIV", "", yyleng, 0); return DIV;}
{MINUS}						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("MINUS", "", yyleng, 0); return MINUS;}
{PLUS}						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("PLUS", "", yyleng, 0); return PLUS;}
{EQ}						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("EQ", "", yyleng, 0); return EQ;}
{GE} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("GE", "", yyleng, 0); return GE;}
{GT}						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("GT", "", yyleng, 0); return GT;}
{LBRACE}					{strlit = 0; newline = 0; printToken("LBRACE", "", yyleng, 0); return LBRACE;}
{LE} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("LE", "", yyleng, 0); return LE;}
{LPAR} 						{strlit = 0; newline = 0; printToken("LPAR", "", yyleng, 0); return LPAR;}
{LSQ}						{strlit = 0; newline = 0; printToken("LSQ", "", yyleng, 0); return LSQ;}
{LT} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("LT", "", yyleng, 0); return LT;}
{MOD} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("MOD", "", yyleng, 0); return MOD;}
{NE} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("NE", "", yyleng, 0); return NE;}
{NOT} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("NOT", "", yyleng, 0); return NOT;}
{AND} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("AND", "", yyleng, 0); return AND;}
{OR} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("OR", "", yyleng, 0); return OR;}
{RBRACE} 					{strlit = 0; newline = 0; printToken("RBRACE", "", yyleng, 1); return RBRACE;}
{RPAR} 						{strlit = 0; newline = 0; printToken("RPAR", "", yyleng, 1); return RPAR;}
{RSQ} 						{strlit = 0; newline = 0; printToken("RSQ", "", yyleng, 1); return RSQ;}
{PACKAGE} 					{strlit = 0; newline = 0; printToken("PACKAGE", "", yyleng, 0); return PACKAGE;}
{RETURN} 					{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("RETURN", "", yyleng, 1); return RETURN;}
{ELSE} 						{strlit = 0; newline = 0; printToken("ELSE", "", yyleng, 0); return ELSE;}
{FOR} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("FOR", "", yyleng, 0); return FOR;}
{IF} 						{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("IF", "", yyleng, 0); return IF;}
{VAR} 						{strlit = 0; newline = 0; printToken("VAR", "", yyleng, 0); return VAR;}
{INT} 						{strlit = 0; newline = 0; printToken("INT", "", yyleng, 0); return INT;}
{FLOAT32} 					{strlit = 0; newline = 0; printToken("FLOAT32", "", yyleng, 0); return FLOAT32;}
{BOOL} 						{strlit = 0; newline = 0; printToken("BOOL", "", yyleng, 0); return BOOL;}
{STRING} 					{strlit = 0; newline = 0; printToken("STRING", "", yyleng, 0); return STRING;}
{PRINT} 					{strlit = 0; newline = 0; yylval.value = create_value(NULL, line, column); printToken("PRINT", "", yyleng, 0); return PRINT;}
{PARSEINT} 					{strlit = 0; newline = 0; yylval.value = create_value(strdup(yytext), line, column); printToken("PARSEINT", "", yyleng, 0); return PARSEINT;}
{FUNC} 						{strlit = 0; newline = 0; printToken("FUNC", "", yyleng, 0); return FUNC;}
{CMDARGS} 					{strlit = 0; newline = 0; printToken("CMDARGS", "", yyleng, 0); return CMDARGS;}
{LINE_COMMENTS}				{strlit = 0; newline = 0; ;}
{START_MULTI_COMMENTS}		{strlit = 0; newline = 0; comment_line = line; comment_col = column; column += yyleng; comment_status = 1; BEGIN MULTI_COMMENTS;}
<MULTI_COMMENTS>\n 			{strlit = 0; newline = 0; int scs_save = semi_col_status; checkForSemiColon(); semi_col_status = 0; line++; column = 1; if (scs_save) return SEMICOLON;}
<MULTI_COMMENTS>.	 		{strlit = 0; newline = 0; column += yyleng;}
<MULTI_COMMENTS>"*/"		{strlit = 0; newline = 0; BEGIN 0; column += yyleng; comment_status = 0;}
{RESERVED}					{strlit = 0; newline = 0; printToken("RESERVED", yytext, yyleng, 0); return RESERVED;}
{ID}						{strlit = 0; newline = 0; yylval.value = create_value(strdup(yytext), line, column); printToken("ID", yytext, yyleng, 1); return ID;}
{INTLIT}					{strlit = 0; newline = 0; yylval.value = create_value(convert_hex_oct(yytext), line, column); resolveIntLit(yytext, yyleng); return INTLIT;}
{REALLIT}					{strlit = 0; newline = 0; yylval.value = create_value(convert_exp(yytext), line, column); printToken("REALLIT", yytext, yyleng, 1); return REALLIT;}

\"                            					{strlit = 0; newline = 0; str_valid = 1; str_start = column; BEGIN STRING_LIT; column++; semi_col_status = 0;}
<STRING_LIT>([^\\\"\n\r]|\\[fnrt\\\"])*\"    	{strlit = 1; newline = 0; BEGIN 0; yytext[yyleng - 1] = '\0'; if (str_valid)
																									   {	
																									   		if (token_status == 1)
																									   			printf("STRLIT(\"%s\")\n", yytext);
																									   		semi_col_status = 1;
																									   		yylval.value = create_value(strdup(yytext), line, column);
																									   		return STRLIT;
																									   	}; column += yyleng;}
<STRING_LIT>(\n|\r\n|\r)    					{strlit = 0; newline = 0; logError("unterminated string literal", "", 0, line, str_start); column = 1; line++; BEGIN 0;}
<STRING_LIT>\\[fnrt\\\"]						{strlit = 0; newline = 0; column += yyleng;}
<STRING_LIT>\\.?            					{strlit = 0; newline = 0; logError("invalid escape sequence", yytext, 0, line, column); column += yyleng; str_valid = 0;}
<STRING_LIT><<EOF>>          					{strlit = 0; newline = 0; logError("unterminated string literal", "", 0, line, str_start); column = 1; BEGIN 0;}
<STRING_LIT>.									{strlit = 0; newline = 0; column++;}

" "|"\t"|"\r"				{strlit = 0; newline = 0; column++;}
"\n"						{column_save = column; newline = 1; strlit = 0; int scs_save = semi_col_status; line++; checkForSemiColon(); column = 1; if (scs_save) return SEMICOLON;}
.							{strlit = 0; newline = 0; logError("illegal character", yytext, yyleng, line, column); semi_col_status = 0;}
<<EOF>>						{strlit = 0; newline = 0; line++; column = 1; int scs_save = semi_col_status; endLex(); if (scs_save) {line--;return SEMICOLON;} else return 0;}

%%
//"
void endLex(void)
{
	checkForSemiColon();

	if (comment_status)
		logError("unterminated comment", "", yyleng, comment_line, comment_col);
}

int yywrap(void)
{
	return 1;
}

void checkForSemiColon(void)
{
	if (semi_col_status)
		printToken("SEMICOLON", "", 0, 0);
}

void printToken(char* token, char* yytext, int yyleng, int semicol)
{
	semi_col_status = semicol;
	if (token_status == 1)
	{
		if (yytext[0] != '\0')
			printf("%s(%s)\n", token, yytext);
		else
			printf("%s\n", token);
	}
	column += yyleng;
}

void logError(char* message, char* yytext, int yyleng, int l, int c)
{
	if (yytext[0] != '\0')
		printf("Line %d, column %d: %s (%s)\n", l, c, message, yytext);
	else
		printf("Line %d, column %d: %s\n", l, c, message);
	column += yyleng;
}

void resolveIntLit(char* yytext, int yyleng)
{
	for (int i = 0; yytext[0] == '0' && (yytext[1] != 'x' && yytext[1] != 'X') && i < yyleng; i++)
	{
		if (yytext[i] > '7' && yytext[i] <= '9')
		{
			semi_col_status = 0;
			logError("invalid octal constant", yytext, yyleng, line, column);
			return;
		}

	}
	printToken("INTLIT", yytext, yyleng, 1);
}

void yyerror(const char *s)
{
	// don't print AST if something goes wrong in yacc
	token_status = -1;

	if (strlit)
		printf("Line %d, column %lu: %s: \"%s\"\n", line, column - strlen(yytext) - 2, s, yytext);
	else if (newline)
		printf("Line %d, column %d: %s: %s\n", line - 1, column_save-1, s, yytext);
	else
		printf("Line %d, column %lu: %s: %s\n", line, column - strlen(yytext), s, yytext);
}

char* convert_hex_oct(char* int_str){

    // convert hexadecimal to int
    if (int_str[0] == '0' && (int_str[1] == 'x' || int_str[1] == 'X')){

        char * pEnd;
        long int li1;
        li1 = strtol (int_str, &pEnd, 16);

        long int n = li1;
        int count = 0;
        while(n!=0){
           n=n/10;
           count++;
        }  

        char* str_decimal = (char*)malloc(count + 1);
        sprintf(str_decimal, "%lu", li1);

        return str_decimal;
    }

    // convert octal to int
    else if (int_str[0] == '0'){

        char * pEnd;
        long int li1;
        li1 = strtol (int_str, &pEnd, 8);

        long int n = li1;
        int count = 0;
        while(n!=0){
           n=n/10;
           count++;
        }  

        char* str_decimal = (char*)malloc(count + 1);
        sprintf(str_decimal, "%lu", li1);

        return str_decimal;
    }

    return strdup(int_str);
}

char* convert_exp(char* exp_str){

	if(exp_str[0] == '.'){
		float tmp = atof(exp_str);

		char tmp_str[30] = "";

		sprintf(tmp_str,"%f",tmp);

		return strdup(tmp_str);
	}else{
		int true = 0;
		for(int i = 1; i< strlen(exp_str);i++){
			if (exp_str[i] == 'e' || exp_str[i] == 'E'){
				true = 1;
				break;
			}
		}

		if(true){
			float tmp = atof(exp_str);

			char tmp_str[30] = "";

			sprintf(tmp_str,"%f",tmp);
			

			return strdup(tmp_str);
		}
	}
	return strdup(exp_str);
}