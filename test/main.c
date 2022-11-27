#include<stdio.h>
#include<wchar.h>
#include"vmtype/TLString.h"
#include<string.h>
int main()
{
    
    printf("len=%d %ld %ld %d\n",wcslen(L"我是abcd!！"),(L"我是abcd!！")[0],L"我"[0]);
}