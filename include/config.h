#pragma once
#include<malloc.h>
typedef void* TL_Ptr;
#define TL_MEM_ALLOC(sz) malloc(sz)
#define TL_MEM_FREE(addr) free(addr) 
#define TL_MEM_REALLOC(addr,s) realloc(addr,s)
#define TL_RESOUCE_NEW(type,name) type *name =  TL_MEM_ALLOC(sizeof(type))
#define TL_LINT_SIZE sizeof(size_t)
#if SIZE_MAX == 18446744073709551615ull
#define TL_BITS 64
#elif SIZE_MAX == 4294967295
#define TL_BITS 32
#else
#error "UNKNOWN BITS ERROR"
#endif

#define TL_MAX_TOKEN_TYPE short

#define TL_MAX_ERR_TRANSLATION_TEXT 20

typedef size_t TL_LInteger;
typedef double TL_LDouble;
typedef float TL_LFloat;