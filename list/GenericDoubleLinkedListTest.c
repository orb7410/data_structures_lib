#include <stdio.h> /*for the print*/
#include "GenericDoubleLinkedList.h"
#include <stdlib.h> /*for malloc*/

Node* GetHeadNext(List *_list);
Node* GetTailPrev(List *_list);
Node* GetHeadPrev(List *_list);
Node* GetTailNext(List *_list);


static void Test5ListCreateMallocOK(void);
static void Test1ListCreateHeadNext(void);
static void Test2ListCreateTailPrev(void);
static void Test3ListCreateTailNext(void);
static void Test4ListCreateHeadPrev(void);
static void Test2ListDestroyDouble(void);
static void Test1ListDestroyOK(void);
static void Test1ListPushHeadListNull(void);
static void Test2ListPushHeadItemNull(void);
static void Test3ListPushHeadOK(void);
static void Test1ListPushTailListNull(void);
static void Test2ListPushTailItemNull(void);
static void Test3ListPushTailOK(void);
static void Test1ListSizeOK(void);
static void Test1ListPopTailOK(void);
static void Test2ListPopTailSizeDecrease(void);
static void Test3ListPopTailListNull(void);
static void Test4ListPopTailValueNull(void);
static void Test1ListPopHeadOK(void);
static void Test2ListPopHeadSizeDecrease(void);
static void Test3ListPopHeadListNull(void);
static void Test4ListPopHeadValueNull(void);
static void Test5ListPopHeadListIsEmpty(void);
static void Test5ListPopTailListIsEmpty(void);
int main()
{
    
    /*Test1ListCreateHeadNext();
    Test2ListCreateTailPrev();
    Test3ListCreateTailNext();
    Test4ListCreateHeadPrev();*/
    Test5ListCreateMallocOK();
    Test1ListDestroyOK();
    Test2ListDestroyDouble();
    Test1ListPushHeadListNull();
    Test2ListPushHeadItemNull();
    Test3ListPushHeadOK();
    Test1ListPushTailListNull();
    Test2ListPushTailItemNull();
    Test3ListPushTailOK();
    Test1ListSizeOK();
    Test1ListPopTailOK();
    Test2ListPopTailSizeDecrease();
    Test3ListPopTailListNull();
    Test4ListPopTailValueNull();
    Test5ListPopTailListIsEmpty();
    Test1ListPopHeadOK();
    Test2ListPopHeadSizeDecrease();
    Test3ListPopHeadListNull();
    Test4ListPopHeadValueNull();
    Test5ListPopHeadListIsEmpty();
}

static void Test5ListCreateMallocOK(void)
{
	List *ptrList = ListCreate();
	if(ptrList != NULL)
	{
		printf("Test5 ListCreate MallocOK ..... PASS\n");
	}
	else
	{
		printf("Test5 ListCreate MallocOK......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test1ListCreateHeadNext(void)
{
    List *ptrList = ListCreate();
	void* head = GetHeadNext(ptrList);
	if(GetTailPrev(ptrList) == head)
	{
		printf("Test1 ListCreateHeadNext ..... PASS\n");
	}
	else
	{
		printf("Test1 ListCreateHeadNext......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test2ListCreateTailPrev(void)
{
	List *ptrList = ListCreate();
	void* tail = GetTailPrev(ptrList);
	if(GetHeadNext(ptrList) == tail)
	{
		printf("Test2 ListCreateTailPrev ..... PASS\n");
	}
	else
	{
		printf("Test2 ListCreateTailPrev......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test3ListCreateTailNext(void)
{
    List *pList = ListCreate();
	if(GetTailNext(pList) == NULL)
	{
		printf("Test3ListCreateTailNext ..... PASS\n");
	}
	else
	{
		printf("Test3ListCreateTailNext......FAIL\n");
    }
    ListDestroy(&pList,NULL);
}

/*********************************************************/
static void Test4ListCreateHeadPrev(void)
{
    List *pList = ListCreate();
	if(GetHeadPrev(pList) == NULL)
	{
		printf("Test4ListCreateList CreateHeadPrev ..... PASS\n");
	}
	else
	{
		printf("Test4ListCreate ListCreateHeadPrev......FAIL\n");
    }
    ListDestroy(&pList,NULL);
}
/*********************************************************/
static void Test1ListDestroyOK(void)
{
	List *ptrList = ListCreate();
	ListDestroy(&ptrList, NULL);
	if(ptrList == NULL)
	{
		printf("Test1 ListDestroyOK ..... PASS\n");
	}
	else
	{
		printf("Test1 ListDestroyOK......FAIL\n");
	}
}
/*********************************************************/
static void Test2ListDestroyDouble(void)
{
	List *ptrList = ListCreate();
	ListDestroy(&ptrList, NULL);
    ListDestroy(&ptrList, NULL);
	printf("Test2 ListDestroy DubleFree.....PASS\n");
}
/*********************************************************/
static void Test1ListPushHeadListNull(void)
{
    int item1 = 20;
    List *ptrList = ListCreate();
	if(ListPushHead(NULL, &item1) == LIST_UNINITIALIZED_ERROR)
	{
		printf("Test1ListPushHead ListNull..... PASS\n");
	}
	else
	{
		printf("Test1ListPushHead ListNull......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}

/*********************************************************/
static void Test2ListPushHeadItemNull(void)
{
    List *ptrList = ListCreate();
	if(ListPushHead(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("Test2ListPushHead ItemNull..... PASS\n");
	}
	else
	{
		printf("Test2ListPushHead ItemNull......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test3ListPushHeadOK(void)
{
    size_t size;
    void* value;
    int item1 = 3;
    int item2 = 8;
    int item3 = 9;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item1);
    ListPushHead(ptrList, &item2);
    ListPushHead(ptrList, &item3);
    ListPopHead(ptrList, &value);
    size = ListSize(ptrList);
	if(size == 2&& (*(int*)value) == 9)
	{
		printf("Test3ListPushHead OK..... PASS\n");
	}
	else
	{
		printf("Test3ListPushHead OK......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test1ListPushTailListNull(void)
{
    int item = 3;
    List *ptrList = ListCreate();
	if(ListPushTail(NULL, &item) == LIST_UNINITIALIZED_ERROR)
	{
		printf("Test1ListPushTail ListNull..... PASS\n");
	}
	else
	{
		printf("Test1ListPushTail ListNull......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test2ListPushTailItemNull(void)
{
    List *ptrList = ListCreate();
	if(ListPushTail(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("Test2ListPushTail ItemNull..... PASS\n");
	}
	else
	{
		printf("Test2ListPushTailItemNull......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test3ListPushTailOK(void)
{
    size_t size;
    int item1 = 3;
    int item2 = 8;
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    ListPushTail(ptrList, &item1);
    ListPushTail(ptrList, &item2);
    ListPushTail(ptrList, &item3);
    ListPopTail(ptrList, &value);
    size = ListSize(ptrList);
	if(size == 2 && (*(int*)value) == 9)
	{
		printf("Test3ListPushTail OK..... PASS\n");
	}
	else
	{
		printf("Test3ListPushTail OK......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test1ListSizeOK(void)
{
    size_t size1, size2;
    int item1 = 3;
    int item2 = 8;
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    size1 = ListSize(ptrList);
    ListPushTail(ptrList, &item1);
    ListPushTail(ptrList, &item2);
    ListPushTail(ptrList, &item3);
    size2 = ListSize(ptrList);
	if(size1 == 0 && size2 == 3)
	{
		printf("Test3 ListSize OK..... PASS\n");
	}
	else
	{
		printf("Test3 ListSize OK......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test1ListPopTailOK(void)
{
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    ListPushTail(ptrList, &item3);
    ListPopTail(ptrList, &value);
	if( (*(int*)value) == 9)
	{
		printf("Test3 ListPopTail OK..... PASS\n");
	}
	else
	{
		printf("Test3 ListPopTail OK......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test2ListPopTailSizeDecrease(void)
{
    size_t size1, size2;
    int item1 = 3;
    int item2 = 8;
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    ListPushTail(ptrList, &item1);
    ListPushTail(ptrList, &item2);
    ListPushTail(ptrList, &item3);
    size1 = ListSize(ptrList);
    ListPopTail(ptrList, &value);
    size2 = ListSize(ptrList);
	if(size1 == 3 && size2 == 2)
	{
		printf("Test2 ListPopTail SizeDecrease..... PASS\n");
	}
	else
	{
		printf("Test2 ListPopTail SizeDecrease......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test3ListPopTailListNull(void)
{
	void* value;
    if(ListPopTail(NULL, &value) == LIST_UNINITIALIZED_ERROR)
	{
		printf("Test3ListPopTail OK..... PASS\n");
	}
	else
	{
		printf("Test3ListPopTail OK......FAIL\n");
	}
}
/*********************************************************/
static void Test4ListPopTailValueNull(void)
{
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    ListPushTail(ptrList, &item3);
	if(  ListPopTail(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("Test4ListPopTail ValueNull..... PASS\n");
	}
	else
	{
		printf("Test4ListPopTail ValueNull......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test5ListPopTailListIsEmpty(void)
{
    void* value;
    List *ptrList = ListCreate();
	if(LIST_IS_EMPTY_ERROR == (ListPopTail(ptrList, &value)))
	{
		printf("Test5 ListPopTail ListIsEmpty..... PASS\n");
	}
	else
	{
		printf("Test5 ListPopTail ListIsEmpty......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test1ListPopHeadOK(void)
{
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item3);
    ListPopHead(ptrList, &value);
	if( (*(int*)value) == 9)
	{
		printf("Test3 ListPopHead OK..... PASS\n");
	}
	else
	{
		printf("Test3 ListPopHead OK......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test2ListPopHeadSizeDecrease(void)
{
    size_t size1, size2;
    int item1 = 3;
    int item2 = 8;
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item1);
    ListPushHead(ptrList, &item2);
    ListPushHead(ptrList, &item3);
    size1 = ListSize(ptrList);
    ListPopHead(ptrList, &value);
    size2 = ListSize(ptrList);
	if(size1 == 3 && size2 == 2)
	{
		printf("Test2 ListPopHead SizeDecrease..... PASS\n");
	}
	else
	{
		printf("Test2 ListPopHead SizeDecrease......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test3ListPopHeadListNull(void)
{
	void* value;
    if(ListPopHead(NULL, &value) == LIST_UNINITIALIZED_ERROR)
	{
		printf("Test3ListPopHead OK..... PASS\n");
	}
	else
	{
		printf("Test3ListPopHead OK......FAIL\n");
	}
}
/*********************************************************/
static void Test4ListPopHeadValueNull(void)
{
    int item3 = 9;
    void* value;
    List *ptrList = ListCreate();
    ListPushHead(ptrList, &item3);
	if(  ListPopHead(ptrList, NULL) == LIST_NULL_ELEMENT_ERROR)
	{
		printf("Test4ListPopHead ValueNull..... PASS\n");
	}
	else
	{
		printf("Test4ListPopHead ValueNull......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}
/*********************************************************/
static void Test5ListPopHeadListIsEmpty(void)
{
    void* value;
    List *ptrList = ListCreate();
	if(LIST_IS_EMPTY_ERROR == (ListPopHead(ptrList, &value)))
	{
		printf("Test5 ListPopHead ListIsEmpty..... PASS\n");
	}
	else
	{
		printf("Test5 ListPopHead ListIsEmpty......FAIL\n");
	}
	ListDestroy(&ptrList, NULL);
}