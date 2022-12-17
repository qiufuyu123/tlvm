#include"vmtype/TLString.h"
#include"config.h"
#include"vmtype/TLError.h"
#include"string.h"
#define _STRING_ASSERT(str) TL_ASSERT(str,TL_ERROR_NULL_PTR);TL_ASSERT(str->strs,TL_ERROR_NULL_PTR);
TL_String_t* TL_StringAlloc(TLStringLength len)
{
    TL_RESOUCE_NEW(TL_String_t,re);
    TL_ASSERT(re,TL_ERROR_MEMORY_EXHAUST);
    re->len=len;
    re->strs=TL_MEM_ALLOC(len*sizeof(TLChar)+1);
    TL_ASSERT_WITH_EXPR(re->strs,TL_MEM_FREE(re),TL_ERROR_MEMORY_EXHAUST)
    return re;
}
TL_String_t* TL_StringAllocConst(TLChar*str)
{
    TL_String_t*r=TL_StringAlloc(wcslen(str));
    TL_StringCopyConstant(r,str);
    return r;
}
void TL_StringFree(TL_String_t* str)
{
    _STRING_ASSERT(str);
    TL_ASSERT(str->len,TL_ERROR_NULL_VALUE);
    TL_MEM_FREE(str->strs);
    TL_MEM_FREE(str);
}

bool TL_StringCompare(TL_String_t* str,TL_String_t* str2)
{
    _STRING_ASSERT(str)
    _STRING_ASSERT(str2)
    return TL_wStrCompare(str->strs,str2->strs);
}

bool TL_StringCompareConstant(TL_String_t* str,const TLChar* str2)
{
    _STRING_ASSERT(str)
    TL_ASSERT(str2,TL_ERROR_NULL_PTR);
    return TL_wStrCompare(str->strs,str2);
}
void TL_StringCopyConstant(TL_String_t *target, const TLChar*str)
{

    wcsncpy(target->strs,str,wcslen(str)>target->len?target->len:wcslen(str));
}