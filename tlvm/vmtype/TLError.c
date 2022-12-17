#include"vmtype/TLError.h"
#include"stdio.h"
#include"stdlib.h"
TL_CompileErrorTranslator TL_DefaultCompileError=NULL;
const char* _TL_CONST_ERROR_TEXT[TL_ERROR_NR]={"Unknown Error","Memory Exhaust","Null Pointer","","Unsetted Process Flow Invoke"};

void TL_CompileHardError(TL_HardError err_code)
{
    if(err_code>=TL_ERROR_NR)err_code=0;
    printf("[TLVM][PROGRAM] %s %d\n",_TL_CONST_ERROR_TEXT[err_code],err_code);
    exit(0-err_code);
}
TLChar* TL_CompileErrorTranslate(TL_CompileErrorTranslator translator,TL_CompilingError err_num,TL_Token_t*token)
{
    TL_ASSERT(translator,TL_ERROR_NULL_PTR);
    //printf("[test lexing...%ls]",translator[err_num]);
    TLChar* str=TL_ArrayGet(translator,err_num);
    if(!token)
    {
        TLChar* dupbuf=TL_MEM_ALLOC(sizeof(TLChar)*(wcslen(str)+1));
        TL_ASSERT(dupbuf,TL_ERROR_MEMORY_EXHAUST);
        wcscpy(dupbuf,str);
        return dupbuf;
    }
    int toklen=0;
    if(token)toklen=token->val->len;
    int oldlen=wcslen(str);
    TLChar * buf=TL_MEM_ALLOC(sizeof(TLChar)*(oldlen+toklen+25));
    TL_ASSERT(buf,TL_ERROR_MEMORY_EXHAUST);
    //wcscpy(buf,str);
        //wcscpy(buf,str);
        //return buf;
    TLChar* midbuf=TL_MEM_ALLOC(sizeof(TLChar)*(oldlen+30));
    swprintf(midbuf,oldlen+toklen+25,str,token->val->strs);
    swprintf(buf,oldlen+toklen+25+30,L"AT Row:%d Col:%d :%ls",token->row,token->col, midbuf);
     //TL_ArrayGet(translator,err_num);
    return buf;
}
void TL_ErrorInit()
{
    TL_DefaultCompileError=TL_ArrayAlloc(20);
    TL_ErrorTranslatorSet(TL_DefaultCompileError,0,L"err1:%ls");
    TL_ErrorTranslatorSet(TL_DefaultCompileError,1,L"err2");
}
void TL_PrintfErr(TL_CompilingErrorList list)
{
    for (int i = 0; i <list->used; i++)
    {
        printf("%ls",TL_ArrayGet(list,i));
    }
    
}