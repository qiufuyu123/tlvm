#pragma once
#include<wchar.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<locale.h>

typedef wchar_t TLChar;
typedef uint32_t TLStringLength;
#define TL_wStrCompare(s1,s2) (!wcscmp(s1,s2))
#define TL_wStrLen(s1) wcslen(s1)
#define TL_wCharConstCompare(wc1,c2) (wc1==L##c2)
#define TL_SETLOCALE setlocale(LC_ALL, "");
typedef struct 
{
    TLChar *strs;
    TLStringLength len;
}TLString_t;

TLString_t* TL_StringAlloc(TLStringLength len);

void TL_StringFree(TLString_t* str);

bool TL_StringCompare(TLString_t* str,TLString_t* str2);

bool TL_StringCompareConstant(TLString_t* str,const TLChar* str2);

void TL_StringCopyConstant(TLString_t *target, const TLChar*str);