#include <stdio.h>
#include <string.h>
#include "GenericHeap.h"
#include <stdlib.h>
#include <stddef.h>  
#define TRUE 1
#define FALSE 0  

static int FindTheInt(const void *_elem, void * _context);
static int PrintInt(const void *_elem, void * _context);
static int CompareLeftRight(const void *_left, const void *_right);

static void test1HeapBuildVecNull(void);
static void test2HeapBuildPfLessNull(void);
static void Test4HeapBuildHeapify(void);
static void Test1HeapDestroyHeapNull(void);
static void Test2HeapDestroyDubleDystroy(void);
static void Test1HeapInsertHeapNull(void);
static void Test2HeapInsertelementNull(void);
static void Test3HeapInsertSizeIncrease(void);
static void Test5HeapInsertBubbleUpOk(void);
static void Test1HeapPeekHeapNull(void);
static void Test2HeapPeekValueOK(void);
static void Test1HeapExtractHepNull(void);
static void Test2HeapExtractValueOk(void);
static void Test3HeapExtractSizeDecrease(void);
static void Test1HeapSizeNULL0();
static void Test1HeapForEachFindIndex();
static void Test2HeapSizeCorrect();
static void Test2HeapForEachHeapNULL();
static void Test3HeapForEachActNULL();
static void Test4HeapForEachActPrint();

int main()
{

    test1HeapBuildVecNull();
    test2HeapBuildPfLessNull();
    Test4HeapBuildHeapify();
    Test1HeapDestroyHeapNull();
    Test2HeapDestroyDubleDystroy();
    Test1HeapInsertHeapNull();
    Test2HeapInsertelementNull();
    Test3HeapInsertSizeIncrease();
    Test5HeapInsertBubbleUpOk();
    Test1HeapPeekHeapNull();
    Test2HeapPeekValueOK();
    Test1HeapExtractHepNull();
    Test2HeapExtractValueOk();
    Test3HeapExtractSizeDecrease();
    Test1HeapSizeNULL0();
    Test2HeapSizeCorrect();
    Test1HeapForEachFindIndex();
    Test2HeapForEachHeapNULL();
    Test3HeapForEachActNULL();
    Test4HeapForEachActPrint();
  
}
/***************************************************************************/
static int PrintInt(const void *_elem, void * _context)
{
    if (NULL == _elem)
    {
        return FALSE;
    }
    printf("%d \n", *(int*)_elem);	
    return TRUE;
}
/**************************************************************************/
static int FindTheInt(const void *_elem, void * _context)
{
    if (NULL == _elem)
    {
        return FALSE;
    }	
    return (*(int*)_elem != *(int*)_context);
}
/**************************************************************************/
static int CompareLeftRight(const void *_left, const void *_right)
{
    return (*(int*)_left < *(int*)_right); 

}
/****************************************************************************/
/******************************tests****************************************/
/**************************************************************************/
static void test1HeapBuildVecNull(void)
{
    Heap* newHeap = NULL;
    newHeap = HeapBuild(NULL, CompareLeftRight);
    if (newHeap == NULL)
	{
		printf("Test1 HeapBuil VecNull.......Pass\n");
	}
	else
	{	
		printf("Test1 HeapBuild VecNull....... Fail\n");
        HeapDestroy(&newHeap);
	}
}
/**************************************************************************/
static void test2HeapBuildPfLessNull(void)
{
    Heap* newHeap = NULL;
	Vector* newVector=VectorCreate(5,5);
    newHeap = HeapBuild(newVector, NULL);
    if (newHeap == NULL)
	{
		printf("Test2 HeapBuil pfLessNull.......Pass\n");
	}
	else
	{	
		printf("Test2 HeapBuild pfLessNull....... Fail\n");
        HeapDestroy(&newHeap);
	}
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test4HeapBuildHeapify(void) /*add IsHeapCorrect test*/ /*add heap max and min correct*/
{
    Heap* newHeap = NULL;
    int item1 = 1;
    int item2 = 4;
    int item3 = 2;
    int item4 = 3;
    void* value1, *value2, *value3, *value4 ;
	Vector *newVector = VectorCreate(1, 2);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
    VectorAppend (newVector, &item3);
    VectorAppend (newVector, &item4);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    VectorGet(newVector, 0, &value1);
    VectorGet(newVector, 1, &value2);
    VectorGet(newVector, 2, &value3);
    VectorGet(newVector, 3, &value4);
     HeapForEach(newHeap, PrintInt ,NULL);
    if ((*(int*)value1) == 4 && (*(int*)value2) == 3 && (*(int*)value3) == 2 && (*(int*)value4) == 1 )
    {
        printf("Test4 HeapBuild Heapify....... PASS\n");
    }
    else
	{	
		printf("Test4 HeapBuild Heapify....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test1HeapDestroyHeapNull(void)
{
    if (HeapDestroy(NULL) == NULL)
	{
		printf("Test1 HeapBuild HeapNull.......Pass\n");
	}
	else
	{	
		printf("Test1 HeapBuild HeapNull....... Fail\n");
	}
}
/*****************************************************************************/
static void Test2HeapDestroyDubleDystroy(void) /***/
{
    Heap* newHeap = NULL;
    int item1 = 3;
    int item2 = 4;
	Vector *newVector = VectorCreate(1, 2);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    if (newVector != HeapDestroy(&newHeap))
    {
       printf("Test1 ....... Fail\n"); 
    }
    HeapDestroy(&newHeap);
    printf("Test2 HeapDestroy DubleFree.....PASS\n");
    VectorDestroy(&newVector,NULL);
}
/*****************************************************************************/
static void Test1HeapInsertHeapNull(void)
{
    int item1 = 3;
    if ( (HeapInsert (NULL, &item1))== HEAP_NOT_INITIALIZED)
	{
		printf("Test1 HeapInsert HeapNull.......Pass\n");
	}
	else
	{	
		printf("Test1 HeapInsert HeapNull....... Fail\n");
	}
}
/*****************************************************************************/
static void Test2HeapInsertelementNull(void)
{
    Heap* newHeap = NULL;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    if (( HeapInsert (newHeap, NULL))== HEAP_NOT_INITIALIZED)
	{
		printf("Test2 HeapInsert elementNull.......Pass\n");
	}
	else
	{	
		printf("Test2 HeapInsert elementNull....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL); 
}
/*****************************************************************************/
static void Test3HeapInsertSizeIncrease(void) /*add the isheapcorrect to all the insert tests*/
{ 
    Heap* newHeap = NULL;
    int item1 = 3;
    int item2 = 4;
    size_t size1, size2;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    size1 = HeapSize(newHeap);
    HeapInsert (newHeap, &item1);
    HeapInsert (newHeap, &item2);
    size2 = HeapSize(newHeap);
    if (size1 == 0 && size2 == 2)
	{
		printf("Test3 HeapInsert SizeIncrease......Pass\n");
	}
	else
	{	
		printf("Test3 HeapInsert SizeIncrease....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL); 
}
/*****************************************************************************/
static void Test5HeapInsertBubbleUpOk(void)
{
    Heap* newHeap = NULL;
    int item1 = 3;
    int item2 = 4;
    int item3 = 1;
    void* value1, *value2, *value3;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    HeapInsert (newHeap, &item2);
    HeapInsert (newHeap, &item3);
    value1 = HeapExtract(newHeap); 
    value2 = HeapExtract(newHeap);
    value3 = HeapExtract(newHeap);
    if ((*(int*)value1) == 4 && (*(int*)value2) == 3 && (*(int*)value3) == 1)
	{
		printf("Test5 HeapInsert BubbleUpOk......Pass\n");
	}
	else
	{	
		printf("Test5 HeapInsert BubbleUpOk....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL); 
}
/*****************************************************************************/
static void Test1HeapPeekHeapNull(void) /*add a test with an empty heap*/
{
    Heap* newHeap = NULL;
    void* value;
    int item1 = 3;
    size_t size1, size2;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    if (NULL == HeapPeek(NULL))
	{
		printf("Test1 HeapPeek HeapNull......Pass\n");
	}
	else
	{	
		printf("Test1 HeapPeek HeapNull....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test2HeapPeekValueOK(void) /*add inserts and then check*/
{
    Heap* newHeap = NULL;
    const void* value;
    int item1 = 3;
    size_t size1, size2;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    value = HeapPeek(newHeap);
    if ((*(int*)value)==3)
	{
		printf("Test2 HeapPeek ValueOK......Pass\n");
	}
	else
	{	
		printf("Test2 HeapPeek ValueOK....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test1HeapExtractHepNull(void) /*add a test with an empty heap and 1 element*/
{
    Heap* newHeap = NULL;
    void* value;
    int item1 = 3;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    if (NULL == HeapExtract(NULL))
	{
		printf("Test1 HeapExtract HeapNull......Pass\n");
	}
	else
	{	
		printf("Test1 HeapExtract HeapNull....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test2HeapExtractValueOk(void)
{
    Heap* newHeap = NULL;
    void* value;
    int item1 = 3;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    value = HeapExtract(newHeap);
    if ((*(int*)value)==3)
	{
		printf("Test2 HeapExtract ValueOk......Pass\n");
	}
	else
	{	
		printf("Test2 HeapExtract ValueOk....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test3HeapExtractSizeDecrease(void)
{
    Heap* newHeap = NULL;
    void* value;
    int item1 = 3;
    size_t size1, size2;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    size1 = HeapSize(newHeap);
    value = HeapExtract(newHeap);
    size2 = HeapSize(newHeap);
    if (size1>size2 && size2 == 0) /**/
	{
		printf("Test3 HeapExtract SizeDecrease......Pass\n");
	}
	else
	{	
		printf("Test3 HeapExtract SizeDecrease....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test1HeapSizeNULL0()
{
    Heap* newHeap = NULL;
    void* value;
    int item1 = 3;
    int item2 = 4;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    HeapInsert (newHeap, &item2);
    if (0 == HeapSize(NULL))
	{
		printf("Test1 HeapExtract SizeDecrease......Pass\n");
	}
	else
	{	
		printf("Test1 HeapExtract SizeDecrease....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test2HeapSizeCorrect()
{
    Heap* newHeap = NULL;
    void* value;
    int item1 = 3;
    int item2 = 4;
    size_t size;
	Vector *newVector = VectorCreate(1, 2);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    HeapInsert (newHeap, &item2);
    size = HeapSize(newHeap);
    if (size == 2)
	{
		printf("Test2 HeapExtract SizeCorrect......Pass\n");
	}
	else
	{	
		printf("Test2 HeapExtract SizeCorrect....... Fail\n");
	}
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
/*****************************************************************************/
static void Test1HeapForEachFindIndex()
{ 
    Heap* newHeap = NULL;
    size_t index;
    int item1 = 3;
    int item2 = 5;
    int item3 = 4;
    int item4 = 8;
    void* value = &item4;
    Vector *newVector = VectorCreate(1,1);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    HeapInsert (newHeap, &item2);
    HeapInsert (newHeap, &item3);
    HeapInsert (newHeap, &item4);
    index = HeapForEach(newHeap, FindTheInt, value);
    if(3 == index)
    {
        printf("Test1 ForEachFindInt.....PASS\n");
	}
	else
	{
		printf("Test1 ForEachFindInt......Fail\n");
	}	
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);	
}
/*****************************************************************************/
static void Test2HeapForEachHeapNULL(void) /*add check if not found expect to get  the size*/
{
    Heap* newHeap = NULL;
    int item4 = 8;
    void* value = &item4;
    Vector *newVector = VectorCreate(1,1);
    HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item4);
    if(0 == HeapForEach(newHeap, FindTheInt, value))
    {
        printf("Test2 HeapForEach HeapNULL.....PASS\n");
	}
	else
	{
		printf("Test2 HeapForEach HeapNULL......Fail\n");
	}	
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);	 
}
/********************************************************************************************/
static void Test3HeapForEachActNULL(void)
{
    Heap* newHeap = NULL;
    size_t index;
    int item1 = 3;
    int item2 = 5;
    int item3 = 4;
    int item4 = 8;
    void* value = &item4;
    Vector *newVector = VectorCreate(1,1);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    HeapInsert (newHeap, &item1);
    HeapInsert (newHeap, &item2);
    HeapInsert (newHeap, &item3);
    HeapInsert (newHeap, &item4);
    if(0 == HeapForEach(newHeap, NULL, value))
    {
        printf("Test3 HeapForEach ActNULL.....PASS\n");
	}
	else
	{
		printf("Test3 HeapForEach ActNULL......Fail\n");
	}	
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);	 
}
static void Test4HeapForEachActPrint(void)
{
    Heap* newHeap = NULL;
    int item1 = 3;
    int item2 = 4;
    int item3 = 1;
    int item4 = 2;
	Vector *newVector = VectorCreate(1, 2);
    VectorAppend (newVector, &item1);
    VectorAppend (newVector, &item2);
    VectorAppend (newVector, &item3);
    VectorAppend (newVector, &item4);
    newHeap = HeapBuild(newVector, CompareLeftRight);
    printf("Test4 HeapForEachActPrint:\n");
    HeapForEach(newHeap, PrintInt ,NULL);
    HeapDestroy(&newHeap);
    VectorDestroy(&newVector, NULL);
}
    