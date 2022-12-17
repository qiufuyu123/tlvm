#include<stdio.h>
#include<wchar.h>
#include"vmtype/TLString.h"
#include<string.h>
#include"vmtype/TLError.h"
#include"vmtype/TLArray.h"
#include"vmtype/TLToken.h"
#include"lexer/Lexer.h"
int main()
{
    TL_SETLOCALE
    TL_ErrorInit();
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
    printf("%ls\n",TL_CompileErrorTranslate(TL_DefaultCompileError,0,NULL));
    printf("%ls\n",TL_CompileErrorTranslate(TL_DefaultCompileError,0, TL_TokenAlloc(1,1,TL_StringAllocConst(L"TEST TOKEN!"),1,2)));
    //TL_GetErrorTranslatioLexer(TL_COMP_ERR_LEXER_NOT_MATCH,tt,e);
    TL_LexerInitDefault();
    TL_Lexer_t*lex= TL_LexerAlloc(TL_C2S(L"test.q"),TL_C2S(L"a = 333;b=  \"str1\";c=2.906"),TL_DefaultLexerFlow,TL_DefaultCompileError);
    TL_ErrorListAlloc(e);
    TL_LexerStart(lex,e);
    TL_PrintfErr(e);
}