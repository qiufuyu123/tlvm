#include<stdio.h>
#include<wchar.h>
#include"vmtype/TLString.h"
#include<string.h>
#include"vmtype/TLError.h"

int main()
{
    TL_SETLOCALE
    printf("len=%d %lc %lc\n",wcslen(L"我是abcd!！"),(L"我是abcd!！")[0],L"我"[0]);
    TLString_t *s1=TL_StringAlloc(5);
    TL_StringCopyConstant(s1,L"我是");
    printf("%ls",s1->strs);
    printf("compare %d",TL_StringCompareConstant(s1,L"我是"));
}