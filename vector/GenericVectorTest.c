#include <stdio.h>
#include <string.h>
#include "GenericVector.h"
#include <stdlib.h>
#include <stddef.h> 
#define FALSE 0
#define TRUE 1
void Test1VectorDestroyDubleFree(void);
void Test2VectorDestroyVectorNull(void);
void Test4CreateInput0(void);
void Test3CreateInitialCapacity0(void);
void Test2CreateBlockSize0(void);
void Test1CreatePossitiveInput(void);
void Test5Createmalloccheck(void);
void Test1VectorAppendVectorNull(void);
void Test2VectorAppendItemNull(void);
void Test3VectorAppendReallocFail(void);
void Test4VectorAppendOK(void);
void Test1VectorRemoveVecNull(void);
void Test2VectorRemoveValueNULL(void);
void Test3VectorNumOfItems0(void);
void Test4VectorRemoveOK(void);
void Test5VectorRemoveReallocDecrease(void);
void Test1VectorGetWrongIndex(void);
void Test2VectorGetVectorIsEmpty(void);
void Test3VectorGetVecNull(void);
void Test4VectorGetValueNull(void);
void Test5VectorGetOK(void);
void Test1VectorSetVecNull(void);
void Test2VectorSetValueNull(void);
void Test3VectorSetWrongIndex(void);
void Test4VectorSetOK(void);
void Test1VectorForEachPrintInt(void);
void Test2TestVectorForEachFindInt(void);
void Test3VectorForEachVecNULL(void);
void Test4VectorForEachActionNULL(void);

static int printInt(void* _element, size_t _index, void* _context);
static int FindInt(void* _element, size_t _index, void* _context);
int main()
{
    VectorElementAction funcPtr;
    Test1CreatePossitiveInput();
    Test2CreateBlockSize0();
    Test3CreateInitialCapacity0();
    Test4CreateInput0();
    Test1VectorDestroyDubleFree();
    Test2VectorDestroyVectorNull();
    Test1VectorAppendVectorNull();
    Test2VectorAppendItemNull();
    Test3VectorAppendReallocFail();
    Test4VectorAppendOK();
    Test1VectorRemoveVecNull();
    Test2VectorRemoveValueNULL();
    Test3VectorNumOfItems0();
    Test4VectorRemoveOK();
    Test5VectorRemoveReallocDecrease();
    Test1VectorGetWrongIndex();
    Test3VectorGetVecNull();
    Test4VectorGetValueNull();
    Test5VectorGetOK();
    Test1VectorSetVecNull();
    Test1VectorSetVecNull();
    Test2VectorSetValueNull();
    Test3VectorSetWrongIndex();
    Test4VectorSetOK();
    funcPtr = printInt;
    Test1VectorForEachPrintInt();
    funcPtr = FindInt;
    Test2TestVectorForEachFindInt();
    Test3VectorForEachVecNULL();
    Test4VectorForEachActionNULL();
    
}
/*********************************************************************************************/
static int printInt(void* _element, size_t _index, void* _context) /*run until it sends 0*/
{
    if (NULL == _element)
    {
        return FALSE;
    }
    printf("%d \n", *(int*)_element);	
    return TRUE;
}
/* * * * * * * *  * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * **/
static int FindInt(void* _element, size_t _index, void* _context) /*run until it sends 0*/
{
    if (NULL == _element)
    {
        return FALSE;
    }	
    return (*(int*)_element != *(int*)_context);
}
/*********************************************************************************************/
void Test1CreatePossitiveInput(void)
{
	Vector *newVector = VectorCreate(5, 2);
	if (NULL != newVector)
	{
	    printf("Test1 VectorCreate PossitiveNums.....PASS\n");
	}
	else
	{
		printf("Test1 VectorCreate PossitiveNums.....FAIL\n");
	}

	VectorDestroy(&newVector,NULL);
}
/*********************************************************************************************/
void Test2CreateBlockSize0(void)
{
	Vector *newVector = VectorCreate(4, 0);
	if (NULL != newVector)
	{
	    printf("Test2 VectorCreate BlockSize0.....PASS\n");
	}
	else
	{
		printf("Test2 VectorCreate BlockSize0.....FAIL\n");
	}

	VectorDestroy(&newVector,NULL);
}
/*********************************************************************************************/
void Test3CreateInitialCapacity0(void)
{
	Vector *newVector = VectorCreate(0, 2);
	if (NULL != newVector)
	{
	    printf("Test3 VectorCreate InitialCapacity0.....PASS\n");
	}
	else
	{
		printf("Test3 VectorCreate InitialCapacity0.....FAIL\n");
	}

	VectorDestroy(&newVector,NULL);
}
/********************************************************************************************/
void Test4CreateInput0(void)
{
	Vector *newVector = VectorCreate(0, 0);
	if (NULL == newVector)
	{
	    printf("Test4 VectorCreate Input0.....PASS\n");
	}
	else
	{
		printf("Test4 VectorCreate Input0.....FAIL\n");
	}

	VectorDestroy(&newVector,NULL);
}
/********************************************************************************************/
void Test5Createmalloccheck(void) /*?????????????????????*/
{
	Vector *newVector = VectorCreate(-2, 2);
	if (NULL == newVector)
	{
	    printf("Test5 VectorCreate malloccheck  check malloc fail.....PASS\n");
	}
	else
	{
		printf("Test5 VectorCreate malloccheck   check malloc fail.....FAIL\n");
	}

	VectorDestroy(&newVector,NULL);
}
/********************************************************************************************/
void Test1VectorDestroyDubleFree(void)
{
    Vector *newVector = VectorCreate(2, 2);
    VectorDestroy(&newVector,NULL);
    VectorDestroy(&newVector,NULL);
    printf("Test1 VectorDestroy DubleFree.....PASS\n");
}
/********************************************************************************************/
void Test2VectorDestroyVectorNull(void) /*****/
{
    Vector *newVector = NULL;
    VectorDestroy(&newVector,NULL);
    printf("Test2 VectorDestroy VectorNull.....PASS\n");
}
/********************************************************************************************/
void Test1VectorAppendVectorNull(void)
{
	int item = 3;
	Vector *newVector = NULL;
	if ( VectorAppend (newVector, &item) == VECTOR_UNITIALIZED_ERROR)
	{
		printf("Test1 VectorAppend VectorNull.....PASS\n");
	}
	else
	{
		printf("Test1 VectorAppend VectorNull.....FAIL\n");
	}
}
/********************************************************************************************/
void Test2VectorAppendItemNull(void)
{
	Vector *newVector = VectorCreate(2, 2);
	if ( VectorAppend (newVector, NULL) == VECTOR_UNITIALIZED_ERROR)
	{
		printf("Test2 VectorAppend ItemNull.....PASS\n");
	}
	else
	{
		printf("Test2 VectorAppend ItemNull.....FAIL\n");
	}
	VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test3VectorAppendReallocFail(void)
{
	int item1 = 3;
    int item2 = 4;
	Vector *newVector = VectorCreate(1, 0);
    VectorAppend (newVector, &item1);
	if ( VectorAppend (newVector, &item2) == VECTOR_ALLOCATION_ERROR)
	{
		printf("Test3 VectorAppend ReallocFail.....PASS\n");
	}
	else
	{
		printf("Test3 VectorAppend ReallocFail.....FAIL\n");
	}
	VectorDestroy(&newVector, NULL);
}
/********************************************************************************************/
void Test4VectorAppendOK(void)
{
	int item1 = 3;
    int item2 = 4;
	Vector *newVector = VectorCreate(0, 2);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
	if ( VectorSize(newVector) == 2)
	{
		printf("Test4 VectorAppend OK.....PASS\n");
	}
	else
	{
		printf("Test4 VectorAppend OK.....FAIL\n");
	}
	VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test1VectorRemoveVecNull(void)
{
	int item1 = 3, item2 = 4;
    void* value;
	Vector *newVector = VectorCreate(1, 2);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
	if ( VECTOR_UNITIALIZED_ERROR == VectorRemove(NULL, &value))
	{
		printf("Test1 VectorRemove vectorNULL.....PASS\n");
	}
	else
	{
		printf("Test1 VectorRemove vectorNULL.....FAIL\n");
	}
	VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test2VectorRemoveValueNULL(void)
{
	int item1 = 3;
    int item2 = 4;
	Vector *newVector = VectorCreate(1, 2);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
	if ( VECTOR_UNITIALIZED_ERROR == VectorRemove(newVector, NULL))
	{
		printf("Test2 VectorRemove ValueNULL.....PASS\n");
	}
	else
	{
		printf("Test2 VectorRemove ValueNULL.....FAIL\n");
	}
	VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test3VectorNumOfItems0(void)
{
	Vector *newVector = VectorCreate(0, 2);
    void* value;
	if ( VECTOR_UNDERFLOW == VectorRemove(newVector, &value))
	{
		printf("Test3 VectorRemove VECTOR_UNDERFLOW.....PASS\n");
	}
	else
	{
		printf("Test3 VectorRemove VECTOR_UNDERFLOW.....FAIL\n");
	}
	VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test4VectorRemoveOK(void)
{
	int item1 = 3;
    void* value;
    size_t size1;
	Vector *newVector = VectorCreate(1, 2);
	size1 = VectorSize(newVector);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
	size1 = VectorSize(newVector);
    VectorRemove(newVector, &value);
    VectorRemove(newVector, &value);
    
	if ( (size1 = VectorSize(newVector)) == 0)
	{
		printf("Test4 VectorRemove RemoveOK.....PASS\n");
	}
	else
	{
		printf("Test4 VectorRemove RemoveOK.....FAIL\n");
	}
	VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test5VectorRemoveReallocDecrease(void)
{
	int item1 = 3;
    void* value;
    size_t size1, size2;
	Vector *newVector = VectorCreate(1,1);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
    size1 = VectorCapacity(newVector);
    VectorRemove(newVector, &value);
    VectorRemove(newVector, &value);
    size2 = VectorCapacity(newVector);
	if (size2 < size1)
	{
		printf("Test5 VectorRemove ReallocDecrease.....PASS\n");
	}
	else
	{
		printf("Test5 VectorRemove ReallocDecrease.....FAIL\n");
	}
    printf("%ld", size1);
    printf("%ld", size2);
	VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test1VectorGetWrongIndex(void)
{
	int item1 = 3;
    void* value;
	Vector *newVector = VectorCreate(1,1);
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
	if ( VectorGet(newVector,8, &value) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
	{
		printf("Test1 VectorGetIndexBigThennItems.....PASS\n");
	}
	else
	{
		printf("Test1 VectorGetIndexBigThennItems......Fail\n");
	}	
	VectorDestroy(&newVector, NULL);			
}
/********************************************************************************************/
void Test3VectorGetVecNull(void)
{
	int item1 = 3;
    void* value;
	Vector *newVector = NULL;
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
	if ( VectorGet(newVector,1, &value) == VECTOR_UNITIALIZED_ERROR)
	{
		printf("Test3 VectorGet VECTOR_NULL.....PASS\n");
	}
	else
	{
		printf("Test3 VectorGet VECTOR_NULL......Fail\n");
	}				
}
/********************************************************************************************/
void Test4VectorGetValueNull(void)
{
	int item1 = 3;
	Vector *newVector = VectorCreate(1,1);
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
	if ( VectorGet(newVector,1, NULL) == VECTOR_UNITIALIZED_ERROR)
	{
		printf("Test4 VectorGet Value_NULL.....PASS\n");
	}
	else
	{
		printf("Test4 VectorGet VValue_NULL......Fail\n");
	}	
	VectorDestroy(&newVector, NULL);			
}
/********************************************************************************************/
void Test5VectorGetOK(void) /******/
{
	int item1 = 3;
    int item2 = 5;
	int item3 = 8;
    void* value;
	Vector *newVector = VectorCreate(1,1);
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
	if (VectorGet(newVector,1, &value)== VECTOR_SUCCESS && (*(int*)value)==5)
	{
		printf("Test5 VectorGet OK.....PASS\n");
	}
	else
	{
		printf("Test5 VectorGet OK......Fail\n");
	}	
	VectorDestroy(&newVector, NULL);			
}
/********************************************************************************************/
void Test1VectorSetVecNull(void)
{
	int item1 = 3;
    void* value;
	Vector *newVector = NULL;
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
	if ( VectorSet(newVector,1, &value) == VECTOR_UNITIALIZED_ERROR)
	{
		printf("Test1 VectorSet VECTOR_NULL.....PASS\n");
	}
	else
	{
		printf("Test1 VectorSet VECTOR_NULL......Fail\n");
	}				
}
/********************************************************************************************/
void Test2VectorSetValueNull(void)
{
	int item1 = 3;
	Vector *newVector = VectorCreate(1,1);
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
	if ( VectorSet(newVector,1, NULL) == VECTOR_UNITIALIZED_ERROR)
	{
		printf("Test2 VectorSet Value_NULL.....PASS\n");
	}
	else
	{
		printf("Test2 VectorSet Value_NULL......Fail\n");
	}	
	VectorDestroy(&newVector, NULL);			
}
/********************************************************************************************/
void Test3VectorSetWrongIndex(void)
{
	int item1 = 3;
    void* value;
	Vector *newVector = VectorCreate(1,1);
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item1);
	if ( VectorSet(newVector,8, &value) == VECTOR_INDEX_OUT_OF_BOUNDS_ERROR)
	{
		printf("Test3 VectorSet IndexBigThennItems.....PASS\n");
	}
	else
	{
		printf("Test3 VectorSet IndexBigThennItems......Fail\n");
	}	
	VectorDestroy(&newVector, NULL);			
}
/********************************************************************************************/
void Test4VectorSetOK(void) /*****************/
{
	int item1 = 3;
    int item2 = 5;
	int item3 = 8;
    void* value;
	Vector *newVector = VectorCreate(1,1);
	VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
	VectorSet(newVector,1, &item3);
	VectorGet(newVector,1, &value);
	if (VectorSet(newVector,1, &item3) == VECTOR_SUCCESS && (*(int*)value)==8)
	{
		printf("Test4 VectorSet OK.....PASS\n");
	}
	else
	{
		printf("Test4 VectorSet OK......Fail\n");
	}	
	VectorDestroy(&newVector, NULL);			
}
/********************************************************************************************/
void Test1VectorForEachPrintInt(void)
{
    int item1 = 3;
    int item2 = 5;
    int item3 = 3;
    int item4 = 5;
    Vector *newVector = VectorCreate(1,1);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
    VectorAppend (newVector, &item3);
    VectorAppend (newVector, &item4);
    VectorForEach(newVector, printInt, NULL);
    VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test2TestVectorForEachFindInt(void)
{ 
    size_t index;
    int item1 = 3;
    int item2 = 5;
    int item3 = 4;
    int item4 = 8;
    void* value = &item4;
    Vector *newVector = VectorCreate(1,1);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
    VectorAppend (newVector, &item3);
    VectorAppend (newVector, &item4);
    index = VectorForEach(newVector, FindInt, value);
    if(index == 3)
    {
        printf("Test2 ForEachFindInt.....PASS\n");
	}
	else
	{
		printf("Test2 ForEachFindInt......Fail\n");
	}	
    VectorDestroy(&newVector, NULL);	
}
/********************************************************************************************/
void Test3VectorForEachVecNULL(void)
{
    int item4 = 8;
    void* value = &item4;
    Vector *newVector = NULL;
    if(0 == VectorForEach(newVector, FindInt, value))
    {
        printf("Test3 VectorForEachVecNULL.....PASS\n");
	}
	else
	{
		printf("Test3 VectorForEachVecNULL......Fail\n");
	}		 
}
/********************************************************************************************/
void Test4VectorForEachActionNULL(void)
{
   size_t index;
    int item1 = 3;
    int item2 = 5;
    int item3 = 4;
    int item4 = 8;
    void* value = &item4;
    Vector *newVector = VectorCreate(1,1);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
    VectorAppend (newVector, &item3);
    VectorAppend (newVector, &item4);
    if(0 == VectorForEach(newVector, NULL, value))
    {
        printf("Test4 VectorForEachActionNULL.....PASS\n");
	}
	else
	{
		printf("Test4 VectorForEachActionNULL......Fail\n");
	}	
    VectorDestroy(&newVector, NULL);	 
}