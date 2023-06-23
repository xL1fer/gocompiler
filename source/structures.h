    //  "structures.h"
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
    //  this file contains the structures used
    //  throughout the program

#ifndef STRUCTURES_H
#define STRUCTURES_H

// AST structures
typedef struct _s0 {
    char* token;
    int line;
    int col;
} is_value;

typedef struct _s1 {
    char* type;
    is_value* val;
    int temp_num;
    char* notation;
    struct _s1 *child, *sibling;
} is_node;

// Symbol Table structures
typedef struct _s2 {
    char* name;
    char* type;
    int is_used;
    int is_declared;
    int line;
    int col;
    int is_param;
    struct _s2 *next;
} is_symb_table;

typedef struct _s3 {
    char* name;
    is_symb_table* symb_tab;
    struct _s3 *next;
} is_ambient;

typedef struct _s4 {
    char* str;
    int size_llvm;
    struct _s4* next;
} is_string_list;

#endif // STRUCTURES_H