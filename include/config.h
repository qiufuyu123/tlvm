#pragma once
#include<malloc.h>
#define TL_MEM_ALLOC(sz) malloc(sz)
#define TL_MEM_FREE(addr) free(addr) 

#define TL_RESOUCE_NEW(type,name) type *name =  TL_MEM_ALLOC(sizeof(type))