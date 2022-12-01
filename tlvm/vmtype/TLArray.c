#include"vmtype/TLArray.h"
#include"config.h"
#include"vmtype/TLError.h"
#define TL_ARRAY_ASSERT(ptr) TL_ASSERT(ptr,TL_ERROR_NULL_PTR);TL_ASSERT(ptr->data,TL_ERROR_NULL_PTR);
TLArray_t* TL_ArrayAlloc(TL_ArrayUnitSize usize)
{
    TL_RESOUCE_NEW(TLArray_t,re);
    TL_ASSERT(re,TL_ERROR_MEMORY_EXHAUST);
    re->used=0;
    re->capacity=re->unit_size=usize;
    re->data=TL_MEM_ALLOC(usize*sizeof(char*));
    TL_ASSERT_WITH_EXPR(re->data,TL_MEM_FREE(re->data),TL_ERROR_MEMORY_EXHAUST);  
    return re;
}

void* TL_ArraySet(TLArray_t* array,void *value)
{
    TL_ARRAY_ASSERT(array);
}

void* TL_ArrayGet(TLArray_t* array,uint32_t index)
{

}

uint32_t TL_ArrayFree(TLArray_t*array)
{

}