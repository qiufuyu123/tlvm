#pragma once
#include<stdint.h>
#include"vmtype/TLString.h"
#include"vmtype/TLArray.h"
#include"config.h"
#define MAX_WORD_LEN 20
typedef TL_MAX_TOKEN_TYPE TL_TokenType;

enum{
    TL_RT_OPERATION,
    TL_RT_SYMBOL,
    TL_RT_UNION,
    TL_RT_KEYWORD,
    TL_RT_WORD,
    TL_RT_UNKNOWN
};
enum{
    TL_TT_OPER_ADD=1, //+
    TL_TT_OPER_MINUS, //-
    TL_TT_OPER_MUL,   //*
    TL_TT_OPER_DIV,   // /
    TL_TT_OPER_EQUAL, // =
    TL_TT_BIGGER,     // >
    TL_TT_SMALLER,    // <
    TL_TT_OPER_POWER, // ^ POWER
    TL_TT_OPER_MOD,   //% GET MOD
    TL_TT_OPER_NOT,   //! NOT
    TL_TT_OPER_AND,   //& AND
    TL_TT_OPER_OR,    //|OR
    TL_TT_OPER_REV,    //~REVERSE BITS    
    TL_TT_DOUBLE_CALC_OPR,  //++ -- ** // 
    TL_TT_SELF_DOUBLE_OPER,    //+= -= *= /=
    TL_TT_DOUBLE_AND, //&&
    TL_TT_DOUBLE_OR,  //||
    TL_TT_DOUBLE_EQU, //==
    TL_TT_NOT_EQU,      //!=
    TL_TT_LARGE_AND_EQU,//>=
    TL_TT_SMALL_AND_EQU,//<=
    TL_TT_LEFT_SMALL_BRACKET,
    TL_TT_RIGHT_SMALL_BRACKET
};

enum
{
    TL_TT_SYM_AT=1,
    TL_TT_SYM_SHARP,
    TL_TT_SYM_DOLLAR,
    TL_TT_SYM_LEFT_MID_BRACKET,
    TL_TT_SYM_RIGHT_MID_BRACKET,
    TL_TT_SYM_LEFT_LARGE_BRACKET,
    TL_TT_SYM_RIGHT_LARGE_BRACKET,
    TL_TT_SYM_DOT,//.
    TL_TT_SYM_COMMA,//,
    TL_TT_SYM_SIMECOLON,//;
    TL_TT_SYM_QUESTION,//?
    TL_TT_SYM_SLASH,// /
    TL_TT_SYM_OPPO_SLASH,// \ /
    TL_TT_SYM_DOUBLE_QUOTATION,//"
    TL_TT_SYM_SINGLE_QUOTATION,
    TL_TT_SYM_COLON,  //:
    TL_TT_SYM_WAVE,  //~
    TL_TT_SYM_OPPO_SINGLE_QUOTATION //  `
};
enum{
    TL_TT_KWD_INT,
    TL_TT_KWD_SHORT,
    TL_TT_KWD_CHAR,
    TL_TT_KWD_VOID,
    TL_TT_KWD_RETURN,
    TL_TT_PRINT
};
typedef struct 
{
    char root_type;
    TL_TokenType type;
    TL_String_t *val;
    uint32_t row,col;
}TL_Token_t;

typedef struct 
{
    TL_Array_t *token_array;
    TL_String_t *file_path;    
}TL_TokenList_t;

typedef struct 
{
    
}TL_TokenTypeMapper;

TL_Token_t* TL_TokenAlloc(char root_type, TL_TokenType type,TL_String_t* val);

TL_LInteger TL_TokenToInteger(TL_Token_t* t,int base,TLChar *lasts);

TL_LDouble TL_TokenToDouble(TL_Token_t* t,TLChar *lasts);

TL_LFloat TL_TokenToFloat(TL_Token_t* t,TLChar *lasts);

void TL_TokenFree(TL_Token_t* t);

TL_TokenList_t*  TL_TokenListAlloc(TL_String_t* s);
#define TL_TokenGetRootType(t)t->root_type
#define TL_TokenGetType(t)t->type
#define TL_TokenGetString(t)t->val
#define TL_TokenGetRow(t)t->row
#define TL_TokenGetCol(t)t->col
#define TL_TokenListAdd(tl,t)TL_ArrayPush(tl->token_array,t);
#define TL_TokenListGet(tl,index)TL_TokenListGet(tl->token_array,index);