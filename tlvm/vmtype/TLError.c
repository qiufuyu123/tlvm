#include"vmtype/TLError.h"
#include"stdio.h"
#include"stdlib.h"
TL_CompileErrorTranslator TL_DefaultCompileError={
    "Unknown symbol -->%ls",
    "Unmatched symbol around %ls"
};
const char* _TL_CONST_ERROR_TEXT[TL_ERROR_NR]={"Unknown Error","Memory Exhaust","Null Pointer"};
void TL_CompileHardError(TL_HardError err_code)
{
    if(err_code>=TL_ERROR_NR)err_code=0;
    printf("[TLVM][PROGRAM] %s",_TL_CONST_ERROR_TEXT[err_code]);
    exit(0-err_code);
}
TLChar* TL_CompileErrorTranslate(TL_CompileErrorTranslator translator,TL_CompilingError err_num)
{
    TL_ASSERT(translator,TL_ERROR_NULL_PTR);
    return translator[err_num];
}