#pragma once
#include<stdint.h>

typedef struct 
{
    uint32_t capacity;
    uint32_t used;
    uint8_t unit_size;
    char *data;
}TLArray_t;
typedef char TL_ArrayUnitSize;

TLArray_t* TL_ArrayAlloc(TL_ArrayUnitSize usize);

void* TL_ArraySet(TLArray_t* array,void *value);

void* TL_ArrayGet(TLArray_t* array,uint32_t index);

uint32_t TL_ArrayFree(TLArray_t*array);

