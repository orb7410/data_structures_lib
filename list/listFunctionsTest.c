#include <stdio.h> /*printf*/
#include <stddef.h> /*size_t*/
#include <stdlib.h>
#include "listFanctions.h"
#include "ListItr2.h" 
int ActionFunc(void* _element, void* _context);
int PredicateFuncForInt(void * _element, void* _context);
void DeleteNode(void* _element);

static void Test1ListItrFindFirstBeginNull(void);
static void Test2ListItrFindFirstEndNull(void);
static void Test3ListItrFindFirstPredicateNull(void);
static void Test0ListItrFindFirstOK(void);
static void Test4ListItrCountIfBeginNull(void);
static void Test5ListItrCountIfEndNull(void);
static void Test6ListItrCountIfPredicateNull(void);
static void Test7ListItrCountIfOK(void);
static void Test8ListItrForEachBeginNull(void);
static void Test9ListItrForEachEndNull(void);
static void Test10ListItrForEachPredicateNull(void);
static void Test11ListItrForEachOK(void);
static void Test12ListItrCountIfZiro(void);
static void Test13ListItrForEachEmpty(void);
static void Test14ListItrForEachstopInB(void);
int main()
{
    Test0ListItrFindFirstOK();
    Test1ListItrFindFirstBeginNull();
    Test2ListItrFindFirstEndNull(); 
    Test3ListItrFindFirstPredicateNull(); 
    Test4ListItrCountIfBeginNull();
    Test5ListItrCountIfEndNull();
    Test6ListItrCountIfPredicateNull();
    Test7ListItrCountIfOK();
    Test8ListItrForEachBeginNull();
    Test9ListItrForEachEndNull();
    Test10ListItrForEachPredicateNull();
    Test11ListItrForEachOK();
    Test12ListItrCountIfZiro();
    Test13ListItrForEachEmpty();
    Test14ListItrForEachstopInB();
    return 0;
}
void DeleteNode(void* _element)
{
	free(_element);
}
int PredicateFuncForInt(void * _element, void* _context)
{
    if(*(int*)_element == *(int*)_context)
    {
        return 1;
    }
    return 0;
}
 
int ActionFunc(void* _element, void* _context)
{
    if (_element == _context)
    {
        printf("%d ", *(int*)_element);
        return 0;
    }
    printf("%d ", *(int*)_element);
    return 1;
}
/****************************************tests*******/
/*********************tests*************************/
/*********tests************************************/
/********************************tests************/
/*tests******************************************/
static void Test1ListItrFindFirstBeginNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(NULL ==  ListItrFindFirst(NULL, ListItrEnd(list), PredicateFuncForInt, NULL))
    {
    printf("Test1 ListItrFindFirst BeginNull ..... PASS\n");
    }
    else
    {
    printf("Test1 ListItrFindFirst BeginNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/************************************************************/
static void Test2ListItrFindFirstEndNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(NULL ==  ListItrFindFirst(ListItrBegin(list), NULL, PredicateFuncForInt, NULL))
    {
    printf("Test2 ListItrFindFirst endNull ..... PASS\n");
    }
    else
    {
    printf("Test2 ListItrFindFirst endNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/************************************************************/
static void Test3ListItrFindFirstPredicateNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(NULL ==  ListItrFindFirst(ListItrBegin(list),  ListItrEnd(list), NULL, NULL))
    {
    printf("Test3 ListItrFindFirst PredicateNull ..... PASS\n");
    }
    else
    {
    printf("Test3 ListItrFindFirst PredicateNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/************************************************************/
static void Test0ListItrFindFirstOK(void)
{
    List *ptrList = ListCreate();
    int *a, *b;
    void* result;
    int item = 4;
    a = (int*)malloc(sizeof(int) * 1);
    *a = 4;
    b = (int*)malloc(sizeof(int) * 1);
    *b = 7;
    ListPushHead(ptrList, a);
    ListPushHead(ptrList, b);
    result = ListItrFindFirst(ListItrBegin(ptrList), ListItrEnd(ptrList) , PredicateFuncForInt ,&item); 
    if(*(int*)ListItrGet(result) == item )
    {
        printf("Test0 ListItrFindFirstOK.....PASS\n");
    }
    else
    {
        printf("Test0 ListItrFindFirstOK.......FAIL\n");
    }
    ListDestroy(&ptrList, NULL);
}
/************************************************************/
static void Test4ListItrCountIfBeginNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(0 ==  ListItrCountIf(NULL, ListItrEnd(list), PredicateFuncForInt, NULL))
    {
    printf("Test4 ListItrCountIf BeginNull ..... PASS\n");
    }
    else
    {
    printf("Test4 ListItrCountIf BeginNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/************************************************************/
static void Test5ListItrCountIfEndNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(0 ==  ListItrCountIf(ListItrBegin(list), NULL, PredicateFuncForInt, NULL))
    {
    printf("Test5 ListItrCountIf EndNull ..... PASS\n");
    }
    else
    {
    printf("Test5 ListItrCountIf EndNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/********************************************************/
static void Test6ListItrCountIfPredicateNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(0 ==  ListItrCountIf(ListItrBegin(list), ListItrEnd(list), NULL, NULL))
    {
    printf("Test6 ListItrCountIf PredicateNull ..... PASS\n");
    }
    else
    {
    printf("Test6 ListItrCountIf PredicateNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/*****************************************************/
static void Test7ListItrCountIfOK(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(1 ==  ListItrCountIf(ListItrBegin(list), ListItrEnd(list), PredicateFuncForInt, b))
    {
    printf("Test7 ListItrCountIf OK ..... PASS\n");
    }
    else
    {
    printf("Test7 ListItrCountIf OK......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/****************************************************/
static void Test12ListItrCountIfZiro(void)
{
    List* list;
    int* a;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	list = ListCreate();
    if(0 ==  ListItrCountIf(ListItrBegin(list), ListItrEnd(list), PredicateFuncForInt, a))
    {
    printf("Test12 ListItrCountIf Ziro ..... PASS\n");
    }
    else
    {
    printf("Test12 ListItrCountIf Ziro......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/***************************************************/
static void Test8ListItrForEachBeginNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(NULL ==  ListItrForEach(NULL ,  ListItrEnd(list),ActionFunc, NULL))
    {
    printf("Test8 ListItrFindFirst BeginNull ..... PASS\n");
    }
    else
    {
    printf("Test8 ListItrFindFirst BeginNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/************************************************/
static void Test9ListItrForEachEndNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(NULL ==  ListItrForEach(ListItrBegin(list),  NULL, ActionFunc, NULL))
    {
    printf("Test9 ListItrFindFirst EndNull ..... PASS\n");
    }
    else
    {
    printf("Test9 ListItrFindFirst EndNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/*************************************************************/
static void Test10ListItrForEachPredicateNull(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    if(NULL ==  ListItrForEach(ListItrBegin(list),  ListItrEnd(list), NULL, NULL))
    {
    printf("Test10 ListItrFindFirst PredicateNull ..... PASS\n");
    }
    else
    {
    printf("Test10 ListItrFindFirst PredicateNull......FAIL\n");
    }
    ListDestroy(&list, DeleteNode);
}
/*****************************************************************/
static void Test11ListItrForEachOK(void)
{
    List* list;
	int* a, *b;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
    printf("Test11 ListItrForEach Print: \n");
    ListItrForEach(ListItrBegin(list),  ListItrEnd(list), ActionFunc, NULL);
    ListDestroy(&list, DeleteNode);
    printf("\n");
}
/*****************************************************************/
static void Test13ListItrForEachEmpty(void)
{
    List* list;
	list = ListCreate();
    printf("Test13 ListItrForEachEmpty Print: \n");
    ListItrForEach(ListItrBegin(list),  ListItrEnd(list), ActionFunc, NULL);
    ListDestroy(&list, DeleteNode);
    printf("\n");
}
/*****************************************************************/
static void Test14ListItrForEachstopInB(void)
{
    List* list;
    int* a, *b, *c;
	a = (int*)malloc(sizeof(int) * 1);
	*a = 5;
	b = (int*)malloc(sizeof(int) * 1);
	*b = 10;
    c = (int*)malloc(sizeof(int) * 1);
	*c = 3;
    list = ListCreate();
	list = ListCreate();
	ListPushTail(list, a);
	ListPushTail(list, b);
	ListPushTail(list, c);
    printf("Test14 ListItrForEach stopInB: \n");
    ListItrForEach(ListItrBegin(list),  ListItrEnd(list), ActionFunc, b);
    ListDestroy(&list, DeleteNode);
    printf("\n");
}