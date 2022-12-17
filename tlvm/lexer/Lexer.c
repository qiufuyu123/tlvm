#include"lexer/Lexer.h"
#include<wchar.h>

TL_FuncList* TL_DefaultLexerFlow;

TL_Lexer_t* TL_LexerAlloc(TL_String_t*filename,TL_String_t*codepage,TL_FuncList* funclist,TL_CompileErrorTranslator errtrans)
{
    TL_RESOUCE_NEW(TL_Lexer_t,re);
    TL_ASSERT(re,TL_ERROR_MEMORY_EXHAUST);
    re->current_code_page=codepage;
    //re->file_path=filename;
    re->process_flow=funclist;
    re->current=0;
    re->curcol=re->currow=1;
    re->translator=errtrans;
    re->token_module_list=TL_TokenListAlloc(filename);
    return re;
}
TLChar TL_LexerNext(TL_Lexer_t *lexer)
{
    if(lexer->current>=lexer->current_code_page->len)return 0;
    lexer->current++;
    if(lexer->current_code_page->strs[lexer->current-1]==L'\n')
    {
        lexer->curcol=1;
        lexer->currow++;
    }else lexer->curcol++;
    return lexer->current_code_page->strs[lexer->current-1];
}
TLChar TL_LexerOnlyNext(TL_Lexer_t*lexer,int step)
{
    if(lexer->current+step-1>=lexer->current_code_page->len)return 0;
    return lexer->current_code_page->strs[lexer->current+step-1];
}
TLChar TL_LexerNextSkip(TL_Lexer_t *lexer,TLChar c)
{
    TLChar r=0;
    while ((r=TL_LexerNext(lexer))==c);
    if(!r)return 0;
    return lexer->current_code_page->strs[lexer->current-1];
}
bool TL_LexerNextToken(TL_Lexer_t* lexer)
{
    if(!TL_LexerNextSkip(lexer,L' '))return false;
    lexer->nowtok=lexer->current-1;
    printf("next tok%lc;",lexer->current_code_page->strs[lexer->nowtok]);
    return true;
}
void* TL_LexDoNum(TL_Lexer_t*lex,TL_CompilingErrorList err)
{
    return 0;
}
void* TL_LexDoStr(TL_Lexer_t*lex,TL_CompilingErrorList err)
{
    return 0;
}
void* TL_LexDoOper(TL_Lexer_t*lex,TL_CompilingErrorList err)
{
    return 0;
}
void* TL_LexDoSym(TL_Lexer_t*lex,TL_CompilingErrorList err)
{
    return 0;
}
void* TL_LexDoKeyword(TL_Lexer_t*lex,TL_CompilingErrorList err)
{
    return 0;
}
void* TL_LexDoWord(TL_Lexer_t*lex,TL_CompilingErrorList err)
{
    return 0;
}
void* TL_LexDoCustom(TL_Lexer_t*lex,TL_CompilingErrorList err)
{
    return 0;
}
TL_TokenList_t* TL_LexerStart(TL_Lexer_t *lexer,TL_CompilingErrorList errs)
{
    while (TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_BULTIN_NEXT_TOK,TL_Func_v1)(lexer))
    {
        if(TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_DO_NUM,TL_Func_v2)(lexer,errs))continue;
        else if(TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_DO_STR,TL_Func_v2)(lexer,errs))continue;
        else if(TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_DO_OPER,TL_Func_v2)(lexer,errs))continue;
        else if(TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_DO_SYM,TL_Func_v2)(lexer,errs))continue;
        else if(TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_DO_KEYWORD,TL_Func_v2)(lexer,errs))continue;
        else if(TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_DO_WORD,TL_Func_v2)(lexer,errs))continue;
        else if(TL_FlowInvoke(TL_L2P(lexer),TL_LEXER_CUSTOM,TL_Func_v2)(lexer,errs))continue;
        else 
        {
            
            TLChar *bufs=TL_MEM_ALLOC(sizeof(TLChar)*80);
            swprintf(bufs,80,L"[PANIC!] Illegal Character (Unpassed to Lexer)[!PANIC]\nAt row:%d col:%d arround '%lc'!\n",lexer->currow,lexer->curcol,lexer->current_code_page->strs[lexer->nowtok]);
            TL_ErrorListPush(errs,bufs);
            //printf("1111111 %ls",bufs);
            return 0;
        }
    }
    return lexer->token_module_list;
}
void TL_LexerInitDefault()
{
    TL_DefaultLexerFlow=TL_FuncListAllocOri;
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_BULTIN_NEXT,TL_LexerNext);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_BULTIN_ONLYNEXT,TL_LexerOnlyNext);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_BULTIN_NEXT_SKIP,TL_LexerNextSkip);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_BULTIN_NEXT_TOK,TL_LexerNextToken);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_DO_NUM,TL_LexDoNum);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_DO_STR,TL_LexDoStr);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_DO_OPER,TL_LexDoOper);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_DO_SYM,TL_LexDoSym);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_DO_KEYWORD,TL_LexDoKeyword);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_DO_WORD,TL_LexDoWord);
    TL_FuncListAdd(TL_DefaultLexerFlow,TL_LEXER_CUSTOM,TL_LexDoCustom);
}