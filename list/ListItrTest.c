#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc*/
#include <stddef.h> /*size_t*/
#include "ListItr2.h" 
#include "ListItr.h" 
#define TRUE 1
#define FALSE 0


Node* GetTailNext(List *_list);
void DeleteNode(void* _element);
static void Test1ListItrBeginNULL(void);
static void Test2ListItrBeginGetFirst(void);
static void Test1ListItrEndNULL(void);
static void Test2ListItrEndGetlast(void);
static void Test1ListItrEqualsTRUE(void);
static void Test2ListItrEqualsFALSE(void);
static void Test2ListItrNextNULL(void);
static void Test3ListItrNextTailNext(void);
static void Test1ListItrPrevOK(void);
static void Test2ListItrPrevNULL(void);
static void Test3ListItrPrevHeadPrev(void);
static void Test1ListItrGetNULL(void);
static void Test2ListItrGetOk(void);
void Test4ListBeginUninitialized(void);
void Test3ListBeginEndEmpty(void);
void Test6ListNextMiddle(void);
void Test4ListNextToEnd(void);
void Test5ListNextOverEnd(void);
void Test3ListGetEnd(void);
void Test1ListSetHead(void);
void Test2ListSetListUninitialized(void);
void Test3ListSetEleUninitialized(void);
void Test4ListSetEnd(void);
void Test1ListInsertBeforeBegin(void);
void Test2ListInsertBeforeListUninitialized(void);
void Test3ListInsertBeforeEleNull(void);
void Test1ListRemoveBegin(void);
void Test2ListRemoveListUninitialized(void);
void Test3ListRemoveEnd(void);

void DeleteNode(void* _element)
{
	free(_element);
}

int main()
{
    Test1ListItrBeginNULL();
    Test2ListItrBeginGetFirst();
      Test3ListBeginEndEmpty();
    Test4ListBeginUninitialized();
    Test1ListItrEndNULL();
   Test2ListItrEndGetlast();
    Test1ListItrEqualsTRUE();
    Test2ListItrEqualsFALSE();
    Test2ListItrNextNULL();
    Test3ListItrNextTailNext();
  Test4ListNextToEnd();
    Test5ListNextOverEnd();
    Test6ListNextMiddle();
    Test3ListItrPrevHeadPrev();
    Test1ListItrPrevOK();
    Test2ListItrPrevNULL();
    Test1ListItrGetNULL();
    Test2ListItrGetOk();
    Test3ListGetEnd();
    Test1ListSetHead();
  Test2ListSetListUninitialized();
  Test3ListSetEleUninitialized();   
  Test4ListSetEnd();
  Test1ListInsertBeforeBegin();
  Test2ListInsertBeforeListUninitialized();
  Test3ListInsertBeforeEleNull();
  Test1ListRemoveBegin();
  Test2ListRemoveListUninitialized();
  Test3ListRemoveEnd();
    
    

}
/*******************************************************************/
static void Test1ListItrBeginNULL(void)
{
    if(NULL == ListItrBegin(NULL))
    {
		printf("Test1 ListItrBegin NULL ..... PASS\n");
	}
	else
	{
		printf("Test2 ListItrBegin NULL......FAIL\n");
	}
}
/*******************************************************************/
static void Test2ListItrBeginGetFirst(void)
{
    int item1 = 3, item2 = 8, item3 = 9;
    void* dataPulled = NULL;
    ListItr data1, data2, data3;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item1); 
    ListPushHead(ptrList, &item2); 
    ListPushHead(ptrList, &item3);      
    data1 = ListItrBegin(ptrList); 
    dataPulled = ListItrGet(data1);
    if(*(int*)dataPulled == 9)
    {
		printf("Test2 ListItrBegin GetFirst ..... PASS\n");
	}
	else
	{
		printf("Test2 ListItrBegin GetFirst......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/********************************************************************/
void Test4ListBeginUninitialized(void)
{
	if(ListItrBegin(NULL) == NULL)
	{
		printf("%-50s %s\n" ,"Test 4 ListBegin UNINITIALIZED", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 4 ListBegin UNINITIALIZED", "FAIL");
	}
}
/*..........................................................................*/
void Test3ListBeginEndEmpty(void)
{
	List* pList = ListCreate();
	if(ListItrBegin(pList) == ListItrEnd(pList))
	{
		printf("%-50s %s\n" ,"Test 3 ListBeginEnd EMPTY", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 3 ListBeginEnd EMPTY", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*******************************************************************/
static void Test1ListItrEndNULL(void)
{
    if(NULL == ListItrEnd(NULL))
    {
		printf("Test1 ListItrEnd NULL ..... PASS\n");
	}
	else
	{
		printf("Test1 ListItrEnd NULL......FAIL\n");
	}

}
/*******************************************************************/
static void Test2ListItrEndGetlast(void)  
{
	int item1 = 1, item2 = 2, item3 = 3;
	List* pList = ListCreate();
	ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
	if(ListItrEnd(pList) == GetTailNext(pList))
	{
		printf("%-50s %s\n" ,"Test 1 ListEnd Getlast", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 1 ListEnd Getlast", "FAIL");
	}
    ListDestroy(&pList, NULL);
} 
/*******************************************************************/
static void Test1ListItrEqualsTRUE(void)  
{
    int item1 = 3, item2 = 8, item3 = 9;
    ListItr data1, data2, data3;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item1);
    ListPushHead(ptrList, &item2);
    ListPushHead(ptrList, &item3);
    data1 = ListItrBegin(ptrList);
    data2 = ListItrNext(data1);
    data3 = ListItrPrev(data2);
    if(ListItrEquals(data1, data3) == 1)
    {
		printf("Test1 ListItrEquals TRUE ..... PASS\n");
	}
	else
	{
		printf("Test1 ListItrEquals TRUE......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);

}
/*******************************************************************/
static void Test2ListItrEqualsFALSE(void)  
{
      int item1 = 3, item2 = 8, item3 = 9;
    ListItr data1, data2, data3;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item1);
    ListPushHead(ptrList, &item2);
    ListPushHead(ptrList, &item3);
    data1 = ListItrBegin(ptrList);
    data2 = ListItrNext(data1);
    data3 = ListItrPrev(data2);
    if(ListItrEquals(data1, data2) == 0)
    {
		printf("Test2 ListItrEquals FALSE ..... PASS\n");
	}
	else
	{
		printf("Test2 ListItrEquals FALSE......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*..........................................................................*/
void Test4ListNextToEnd(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
	List* pList = ListCreate();
    void* itr, *headNext, *tail;
    headNext = ListItrBegin(pList);
    tail = ListItrEnd(pList);
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    itr = ListItrNext(headNext);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
	if(itr == tail)
	{
		printf("%-50s %s\n" ,"Test 4 ListNext TO END", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 4 ListNext TO END", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test5ListNextOverEnd(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
	List* pList = ListCreate();
    void* itr, *headNext, *tail;
    headNext = ListItrBegin(pList);
    tail = ListItrEnd(pList);
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    itr = ListItrNext(headNext);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
    itr = ListItrNext(itr);
	if(itr == tail)
	{
		printf("%-50s %s\n" ,"Test 5 ListNext OVER END", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 5 ListNext OVER END", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test6ListNextMiddle(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
	List* pList = ListCreate();
    void* itr, *headNext, *tail;
    ListPushHead(pList, &item1);
	ListPushHead(pList, &item2);
	ListPushHead(pList, &item3);
    headNext = ListItrBegin(pList);
    itr = ListItrNext(headNext);
	if(*(int*)ListItrGet(itr) == item2)
	{
		printf("%-50s %s\n" ,"Test 6 ListNext MIDDLE", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 6 ListNext MIDDLE", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
static void Test2ListItrNextNULL(void) 
{
    if(NULL == ListItrNext(NULL))
    {
		printf("Test2 ListItrNext NULL ..... PASS\n");
	}
	else
	{
		printf("Test2 ListItrNext NULL......FAIL\n");

	}
} 
/*******************************************************/
static void Test3ListItrNextTailNext(void)
{
    int item1 = 3, item2 = 8, item3 = 9;
    void* dataPulled = NULL;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item1); 
    ListPushHead(ptrList, &item2); 
    ListPushHead(ptrList, &item3);    
    dataPulled = ListItrEnd(ptrList); 
    if(GetTailNext(ptrList) == ListItrNext(dataPulled))
    {
		printf("Test3 ListItrNext TailNext ..... PASS\n");
	}
	else
	{
		printf("Test3 ListItrNext TailNext......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
} 
/*******************************************************/
static void Test1ListItrPrevOK(void) 
{
    int item1 = 1, item2 = 2, item3 = 3;
	List* pList = ListCreate();
    void* itr, *headNext, *tail;
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    headNext = ListItrBegin(pList);
    tail = ListItrEnd(pList);
    itr = ListItrPrev(tail);
    itr = ListItrPrev(itr);
	if(*(int*)ListItrGet(itr) == item2)
	{
		printf("%-50s %s\n" ,"Test 1 ListPrev MIDDLE", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 1 ListPrev MIDDLE", "FAIL");
	}
    ListDestroy(&pList, NULL);
} 
/********************************************************/
static void Test2ListItrPrevNULL(void) 
{
   if(NULL == ListItrPrev(NULL))
    {
		printf("Test2 ListItrPrev NULL ..... PASS\n");
	}
	else
	{
		printf("Test2 ListItrPrev NULL......FAIL\n");

	}
} 
/********************************************************/
static void Test3ListItrPrevHeadPrev(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
	List* pList = ListCreate();
	ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
	if(*(int*)ListItrGet(ListItrBegin(pList)) == item1)
	{
		printf("%-50s %s\n" ,"Test 3 ListGet Head", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 3 ListGet Head", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/********************************************************/
static void Test1ListItrGetNULL(void) 
{
    if(NULL == ListItrGet(NULL))
    {
		printf("Test1 ListItrGet NULL ..... PASS\n");
	}
	else
	{
		printf("Test1 ListItrGet NULL......FAIL\n");
	}
} 
/********************************************************/
static void Test2ListItrGetOk(void) 
{
    int item1 = 3, item2 = 8, item3 = 9;
    void* dataPulled = NULL;
    ListItr data1, data2, data3;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item1); 
    ListPushHead(ptrList, &item2); 
    ListPushHead(ptrList, &item3);      
    data1 = ListItrBegin(ptrList); 
    dataPulled = ListItrGet(data1);
    if(*(int*)dataPulled == 9)
    {
		printf("Test2 ListItrGet Ok ..... PASS\n");
	}
	else
	{
		printf("Test2 ListItrGet Ok ......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/********************************************************/   
void Test3ListGetEnd(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
    List* pList = ListCreate();
    void* tail;
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    tail = ListItrEnd(pList);
	if(ListItrGet(tail) == NULL)
	{
		printf("%-50s %s\n" ,"Test 3 ListGet END", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 2 ListGet END", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test1ListSetHead(void)
{
    int item1 = 1, item2 = 2, item3 = 3, item4 = 4;
    List* pList = ListCreate();
    void* save;
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    save = ListItrGet(ListItrBegin(pList));
    ListItrSet(ListItrBegin(pList), &item4);
	if(*(int*)ListItrGet(ListItrBegin(pList)) == item4 && *(int*)save == item1)
	{
		printf("%-50s %s\n" ,"Test 1 ListSet HEAD", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 1 ListSet HEAD", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test2ListSetListUninitialized(void)
{
    int item4 = 4;
	if(ListItrSet(NULL, &item4) == NULL)
	{
		printf("%-50s %s\n" ,"Test 2 ListSet LIST UNINITIALIZED", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 2 ListSet LIST UNINITIALIZED", "FAIL");
	}
}
/*..........................................................................*/
void Test3ListSetEleUninitialized(void)
{
    int item1 = 1, item2 = 2, item3 = 3, item4 = 4;
    List* pList = ListCreate();
    void* result;
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    result = ListItrSet(ListItrBegin(pList), NULL);
	if(ListItrGet(ListItrBegin(pList)) == NULL && result != NULL)
	{
		printf("%-50s %s\n" ,"Test 3 ListSet ELEMENT UNINITIALIZED", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 3 ListSet ELEMENT UNINITIALIZED", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test4ListSetEnd(void)
{
    int item1 = 1, item2 = 2, item3 = 3, item4 = 4;
    List* pList = ListCreate();
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
	if(ListItrSet(ListItrEnd(pList), &item4) == NULL)
	{
		printf("%-50s %s\n" ,"Test 4 ListSet END", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 4 ListSet END", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test1ListInsertBeforeBegin(void)
{
    int item1 = 1, item2 = 2, item3 = 3, item4 = 4;
    List* pList = ListCreate();
    void* result;
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    result = ListItrInsertBefore(ListItrBegin(pList), &item4);
	if(result != NULL && *(int*)ListItrGet(result) == 4 && ListSize(pList) == 4)
	{
		printf("%-50s %s\n" ,"Test 1 InsertBefore BEGIN", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 1 InsertBefore BEGIN", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test2ListInsertBeforeListUninitialized(void)
{
    int item4 = 4;
	if(ListItrInsertBefore(NULL, &item4) == NULL)
	{
		printf("%-50s %s\n" ,"Test 2 InsertBefore LIST UNINITIALIZED", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 1 InsertBefore LIST UNINITIALIZED", "FAIL");
	}
}
/*..........................................................................*/
void Test3ListInsertBeforeEleNull(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
    List* pList = ListCreate();
    void* result;
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    result = ListItrInsertBefore(ListItrBegin(pList), NULL);
	if(result != NULL && ListItrGet(ListItrBegin(pList)) == NULL && ListSize(pList) == 4)
	{
		printf("%-50s %s\n" ,"Test 3 InsertBefore ELEMENT UNINITIALIZED", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 3 InsertBefore ELEMENT UNINITIALIZED", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test1ListRemoveBegin(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
    List* pList = ListCreate();
    void* result;
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
    result = ListItrRemove(ListItrBegin(pList));
	if(*(int*)result == 1 && ListSize(pList) == 2)
	{
		printf("%-50s %s\n" ,"Test 1 ListRemove BEGIN", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 1 ListRemove BEGIN", "FAIL");
	}
    ListDestroy(&pList, NULL);
}
/*..........................................................................*/
void Test2ListRemoveListUninitialized(void)
{
    int item4 = 4;
	if(ListItrRemove(NULL) == NULL)
	{
		printf("%-50s %s\n" ,"Test 2 ListRemove LIST UNINITIALIZED", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 2 ListRemove LIST UNINITIALIZED", "FAIL");
	}
}
/*..........................................................................*/
void Test3ListRemoveEnd(void)
{
    int item1 = 1, item2 = 2, item3 = 3;
    List* pList = ListCreate();
    ListPushTail(pList, &item1);
	ListPushTail(pList, &item2);
	ListPushTail(pList, &item3);
	if(ListItrRemove(ListItrEnd(pList)) == NULL)
	{
		printf("%-50s %s\n" ,"Test 3 ListRemove END", "PASS");
	}
	else
	{
		printf("%-50s %s\n" ,"Test 3 ListRemove END", "FAIL");
	}
    ListDestroy(&pList, NULL);
}