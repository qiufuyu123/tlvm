#pragma once
#include"vmtype/TLToken.h"
//#include"vmtype/TLArray.h"
#include"vmtype/TLString.h"
#include"vmtype/TLFuncList.h"
#include"vmtype/TLError.h"
enum{
    TL_LEXER_BULTIN_NEXT,
    TL_LEXER_BULTIN_NEXT_SKIP,
    TL_LEXER_BULTIN_ONLYNEXT,
    TL_LEXER_BULTIN_NEXT_TOK,
    TL_LEXER_DO_NUM,
    TL_LEXER_DO_STR,
    TL_LEXER_DO_OPER,
    TL_LEXER_DO_SYM,
    TL_LEXER_DO_KEYWORD,
    TL_LEXER_DO_WORD,
    TL_LEXER_CUSTOM,
    TL_LEXER_DO_NR
};
#define TL_L2P(lexer) lexer->process_flow
typedef struct
{
    TL_TokenList_t* token_module_list;
    TL_String_t* current_code_page;
    //TL_String_t* file_path;
    TL_FuncList* process_flow;
    TL_CompileErrorTranslator translator;
    uint32_t current, nowtok,currow,curcol;
}TL_Lexer_t;
extern TL_FuncList* TL_DefaultLexerFlow;
void TL_LexerInitDefault();
TL_Lexer_t* TL_LexerAlloc(TL_String_t* filename,TL_String_t* codepage,TL_FuncList* funclist,TL_CompileErrorTranslator errtrans);

TL_TokenList_t* TL_LexerStart(TL_Lexer_t *lexer,TL_CompilingErrorList errs);
