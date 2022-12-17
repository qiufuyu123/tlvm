#pragma once
#include<stdint.h>
#include"config.h"
#include"vmtype/TLString.h"
#include"vmtype/TLArray.h"
#include"vmtype/TLToken.h"
#include"string.h"
typedef uint8_t TL_HardError;
typedef uint16_t TL_CompilingError;
typedef TL_Array_t* TL_CompileErrorTranslator;
typedef TL_Array_t* TL_CompilingErrorList;
enum{
    TL_COMP_ERR_LEXER_UNKNWON_SYM=1,
    TL_COMP_ERR_LEXER_NOT_MATCH
};
extern TL_CompileErrorTranslator TL_DefaultCompileError; 
enum{
    TL_ERROR_UNKNOWN,
    TL_ERROR_MEMORY_EXHAUST,
    TL_ERROR_NULL_PTR,
    TL_ERROR_NULL_VALUE,
    TL_ERROR_ANALYSIS_FLOW_NULL_INVOKE,
    TL_ERROR_NR
};
void TL_CompileHardError(TL_HardError err_code);
TLChar* TL_CompileErrorTranslate(TL_CompileErrorTranslator translator, TL_CompilingError err_num,TL_Token_t *token);
void TL_ErrorInit();
void TL_PrintfErr(TL_CompilingErrorList list);
#define TL_ASSERT(expr,err) if(!(expr))TL_CompileHardError(err)
#define TL_ASSERT_WITH_EXPR(expr,act,err) if(!(expr)){act;TL_CompileHardError(err);}
#define TL_ErrorListAlloc(name)  TL_CompilingErrorList name=TL_ArrayAlloc(20)
#define TL_ErrorListPush(list,text) TL_ArrayPush(list,text)
#define TL_ErrorListGet(list,idx) TL_ArrayGet(list,idx)
#define TL_ErrorTranslatorAlloc(name) TL_CompileErrorTranslator name=TL_ArrayAlloc(20)
#define TL_ErrorTranslatorAdd(trans,value_wch) TL_ArrayPush(trans,value_wch)
#define TL_ErrorTranslatorSet(trans,idx,value_wch) TL_ArraySet(trans,value_wch,idx)