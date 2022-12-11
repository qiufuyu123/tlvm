#include"vmtype/TLToken.h"
#include<string.h>
#include<stdlib.h>
#include"vmtype/TLError.h"
#define TL_ASSERT_TOKEN(token)TL_ASSERT(token,TL_ERROR_NULL_PTR);TL_ASSERT(token->val,TL_ERROR_NULL_PTR);
TL_Token_t* TL_TokenAlloc(char root_type,TL_TokenType type,TL_String_t* val)
{
    TL_ASSERT(val,TL_ERROR_NULL_PTR);
    TL_RESOUCE_NEW(TL_Token_t,re);
    TL_ASSERT(re,TL_ERROR_MEMORY_EXHAUST);
    re->type=type;
    re->val=val;
    re->root_type=root_type;
    return re;
}

TL_LInteger TL_TokenToInteger(TL_Token_t* t,int base,TLChar *lasts)
{
    //char *buf=TL_MEM_ALLOC(t->val->len+1);
    //TLChar* lasts;
    TL_ASSERT_TOKEN(t);
    #if TL_BITS == 64
        return wcstoll(t->val->strs,&lasts,base);
    #else
        return wcstol(t->val->strs,&lasts,base);
    #endif
}

TL_LDouble TL_TokenToDouble(TL_Token_t* t,TLChar*lasts)
{
    TL_ASSERT_TOKEN(t);
    return wcstold(t->val->strs,lasts);
}

TL_LFloat TL_TokenToFloat(TL_Token_t* t,TLChar*lasts)
{
    TL_ASSERT_TOKEN(t);
    return wcstof(t->val->strs,lasts);
}
void TL_TokenFree(TL_Token_t* t)
{
    TL_ASSERT_TOKEN(t);
    TL_StringFree(t->val);
    TL_MEM_FREE(t);
}

TL_TokenList_t* TL_TokenListAlloc(TL_String_t*s)
{
    TL_ASSERT(s,TL_ERROR_NULL_PTR);
    TL_RESOUCE_NEW(TL_TokenList_t,re);
    TL_ASSERT(re,TL_ERROR_MEMORY_EXHAUST);
    re->token_array=TL_ArrayAlloc(30);
    TL_ASSERT_WITH_EXPR(re->token_array,TL_MEM_FREE(re),TL_ERROR_MEMORY_EXHAUST);
    re->file_path=s;
    return re;
}