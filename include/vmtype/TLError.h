#pragma once
#include<stdint.h>
#include"config.h"
#include"vmtype/TLString.h"
#include"vmtype/TLArray.h"
#include"vmtype/TLToken.h"
#include"string.h"
typedef uint8_t TL_HardError;
typedef uint16_t TL_CompilingError;
typedef TLChar** TL_CompileErrorTranslator;
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
    TL_ERROR_NR
};
void TL_CompileHardError(TL_HardError err_code);
TLChar* TL_CompileErrorTranslate(TL_CompileErrorTranslator translator, TL_CompilingError err_num);
#define TL_ASSERT(expr,err) if(!(expr))TL_CompileHardError(err)
#define TL_ASSERT_WITH_EXPR(expr,act,err) if(!(expr)){act;TL_CompileHardError(err);}
#define TL_ErrorListAlloc(name)  TL_CompilingErrorList name=TL_ArrayAlloc(20)
#define TL_ErrorListPush(list,text) TL_ArrayPush(va_list,text)
#define TL_ErrorListGet(list,idx) TL_ArrayGet(list,idx)
#define TL_AllocErrorTranslatorBuffer(translator) TL_CompileErrorTranslator  __err_translator__=translator; TLChar* __tl_err_buf__=TL_MEM_ALLOC(sizeof(TLChar)*80); TL_ASSERT(__tl_err_buf__,TL_ERROR_MEMORY_EXHAUST);
#define TL_FreeErrorTranslatorBuffer TL_MEM_FREE(__tl_err_buf__);
#define TL_GetErrorTranslatioLexer(err_num,token)swprintf()