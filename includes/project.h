#ifndef _PROJECT_H
#define _PROJECT_H

#include <stdbool.h>

typedef enum { typeCon, typeStr, typeId, typeOpr, typeTyp, typeMop } nodeEnum;

typedef enum { imageTyp, intTyp, stringTyp, floatTyp } cTyp;

typedef enum {  AMP, PLS, AST, NEG, DIV, MNS, TIL, MOD, L_THAN, G_THAN, L_SHF, R_SHF, GE_THAN, 
                LE_THAN, EQ, NEQ, AND, EXCL_OR, OR, LOG_AND, LOG_OR, INC, DEC, ASS_MLT,
                ASS_DIV, ASS_ADD, ASS_MOD, ASS_R_SHIFT, ASS_SUB, ASS_L_SHIFT} mathOp;

typedef enum {TRANS_UNIT, FUNC_DEF, FUNC_DEC, COMP_STAT, JUMP_STAT, 
              STAT_LIST, RET, POST_EXP, ARG_EXP_LIST, HEAD, EXT_DECL, 
              PROG, EXP_STAT, DECL_LIST, DECL, INIT_DECL, INIT_DECL_LIST, 
              DIR_DECL, INIT_DEF_DECL, SEL_STAT, IF_STAT, ITER_STAT, WHILE_STAT, DO_WHILE_STAT,
              FOR_STAT, FOR_IN_STAT, UNARY_EXP_OP, ADD_EXP, MULT_EXP, SHI_EXP, EQU_EXP, AND_EXP, 
              COND_EXP, INIT_LIST, PARAM_DECL, PARAM_DECL_LIST , REL_EXP, CONST_EXP_C, CONST_EXP_N,
              EXCL_OR_EXP, OR_EXP, LOG_AND_EXP, LOG_OR_EXP, DECL_STAT_LIST, PROG_HEADER, ASS_EXP
              } oper_types; 

#define STRING_MAX_SIZE 256
#define IDENTIFIER_MAX_SIZE 128

typedef char stringT[STRING_MAX_SIZE];
typedef char identifierT[IDENTIFIER_MAX_SIZE];

typedef struct {
    stringT s;
} strNodeType;

/* constants */
typedef struct {
    int value;
} conNodeType;


/* identifiers */
typedef struct {
    identifierT i;                      /* subscript to sym array */
} idNodeType;

/* operators */
typedef struct {
    oper_types oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag **op;	/* operands, extended at runtime */
} oprNodeType;

/* type */
typedef struct {
    cTyp t;                   /* operator */
    bool arr;
} typNodeType;

typedef struct {
    mathOp op;
} mathOpNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    union {
        strNodeType str;
        conNodeType con;        /* constants */
        idNodeType ide;          /* identifiers */
        oprNodeType opr;        /* operators */
        typNodeType typ;
        mathOpNodeType mop;
    };
} nodeType;

extern int sym[26];

#endif