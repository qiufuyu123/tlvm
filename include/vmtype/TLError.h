#pragma once
#include<stdint.h>
typedef uint8_t TL_HardError;
enum{
    TL_ERROR_UNKNOWN,
    TL_ERROR_MEMORY_EXHAUST,
    TL_ERROR_NULL_PTR,
    TL_ERROR_NULL_VALUE,
    TL_ERROR_NR
};
void TL_CompileHardError(TL_HardError err_code);
#define TL_ASSERT(expr,err) if(!(expr))TL_CompileHardError(err)
#define TL_ASSERT_WITH_EXPR(expr,act,err) if(!(expr)){act;TL_CompileHardError(err);}