#pragma once
/**
 * Support List for editable functions in 
 * a process flow(such as  tokenize  parse  or compile)
 * (based on tlarray)
*/
#include"vmtype/TLArray.h"
typedef TL_Array_t TL_FuncList;
typedef void*(*TL_Func_v1)(void*v1);
typedef void* (*TL_Func_v2)(void*v1,void*v2);
typedef void* (*TL_Func_v3)(void*v1,void*v2,void*v3);
#define TL_FuncListAllocOri TL_ArrayAlloc(20);
#define TL_FuncListAlloc(name) TL_Array_t* name=TL_ArrayAlloc(20);
#define TL_FuncListAdd(list,idx,func)TL_ArraySet(list,func,idx)
void *TL_FuncListInvoke(TL_FuncList*lst,int idx);
#define TL_FlowInvoke(lst,idx,type) ((type)TL_FuncListInvoke(lst,idx))