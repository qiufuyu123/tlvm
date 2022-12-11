#include<stdio.h>
#include<wchar.h>
#include"vmtype/TLString.h"
#include<string.h>
#include"vmtype/TLError.h"
#include"vmtype/TLArray.h"
int main()
{
    TL_SETLOCALE
    printf("len=%d %lc %lc\n",wcslen(L"我是abcd!！"),(L"我是abcd!！")[0],L"我"[0]);
    TL_String_t *s1=TL_StringAlloc(5);
    TL_StringCopyConstant(s1,L"我是");
    printf("%ls",s1->strs);
    printf("compare %d",TL_StringCompareConstant(s1,L"我是"));
    TL_Array_t *r=TL_ArrayAlloc(2);
    for (int i = 0; i < 10; i++)
    {
        TL_ArrayPush(r,0);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("get array[%d]:[%d]\n",i,(int)TL_ArrayGet(r,i));
    }
    
    
}