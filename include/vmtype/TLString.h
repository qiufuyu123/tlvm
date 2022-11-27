#pragma once
#include<wchar.h>
#include<string.h>
typedef wchar_t TLChar;
#define TL_StrCompare(s1,s2) wcscmp(s1,s2)
#define TL_StrLen(s1) wcslen(s1)
#define TL_CharConstCompare(wc1,c2) (wc1==L##c2)
typedef struct TLString
{
    /* data */
};
