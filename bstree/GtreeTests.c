#include <stdio.h>
#include "Gtree.h"
#define SIZE 11
void* GetNodeLeft(BSTree* _tree);
void* GetNodeRight(BSTree* _tree);
void* GetTreeRoot(BSTree* _tree);
void* GetRootFather(BSTree* _tree);
void* GetNodeLeftData(BSTree* _tree);
void* GetData(BSTreeItr* _node);
static void Test1BSTreeCreateOk(void);

static void Test2BSTreeCreateFunNULL(void);
static void Test3BSTreeCreateRootLeft(void);
static void Test4BSTreeCreateRootRight(void);
static void Test5BSTreeCreateRootFather(void);
static void Test6BSTreeDestroyNULL(void);
static void Test7BSTreeDestroyOK(void);
static void Test8BSTreeDestroyDubleFree(void);
static void Test10BSTreeInsertTreeNULL(void);
static void Test11BSTreeInsertItemeNULL(void); 
static void Test13BSTreeInsertRoot(void);
static void Test14BSTreeInsertDuplication(void);
static void Test15BSTreeInsertOk(void);
static void Test16BSTreeItrBeginOK(void);
static void Test17BSTreeItrBeginEmpty(void);
static void Test18BSTreeItrBeginNULL(void);
static void Test19BSTreeItrEndNULL(void);
static void Test20BSTreeItrEndOK(void);
static void Test21BSTreeItrBeginEmpty(void);
static void Test22BSTreeInsertTreeNULL(void);
static void Test22BSTreeInsertItemNULL(void);
static void Test23BSTreeInsertItemDuplicate(void);
static void Test25BSTreeInsertItemOK(void);
static void Test26NextItrNULL(void);
static void Test27NextItrEnd(void);
static void Test28NextItrOK(void);
static void Test29PrevItrNULL(void);
static void Test30PrevItrBegin(void);
static void Test31PrevItrOK(void);
static void Test32BSTreeRemoveLEEF(void);
static void Test33BSTreeRemoveROOT(void);
static void Test34BSTreeRemoveNULL(void);
static void Test35BSTreeItrEqualsTRUE(void); 
static void Test36BSTreeItrEqualsFALSE(void);


int main()
{
    Test1BSTreeCreateOk();
    Test2BSTreeCreateFunNULL();
    Test3BSTreeCreateRootLeft();
    Test4BSTreeCreateRootRight();
    Test5BSTreeCreateRootFather();
    Test6BSTreeDestroyNULL();
    Test7BSTreeDestroyOK();
    Test8BSTreeDestroyDubleFree();
    Test10BSTreeInsertTreeNULL();
    Test11BSTreeInsertItemeNULL(); 
    Test13BSTreeInsertRoot();
    Test14BSTreeInsertDuplication();
    Test15BSTreeInsertOk();
    Test16BSTreeItrBeginOK();
    Test17BSTreeItrBeginEmpty();
    Test18BSTreeItrBeginNULL();
    Test19BSTreeItrEndNULL();
    Test20BSTreeItrEndOK();
    Test21BSTreeItrBeginEmpty();
	Test22BSTreeInsertTreeNULL();
	Test22BSTreeInsertItemNULL();
	Test23BSTreeInsertItemDuplicate();
	Test25BSTreeInsertItemOK();
	Test26NextItrNULL();
	Test27NextItrEnd();
	Test28NextItrOK();
	Test29PrevItrNULL();
	Test30PrevItrBegin();
	Test31PrevItrOK();
	Test32BSTreeRemoveLEEF();
	Test33BSTreeRemoveROOT();
	Test34BSTreeRemoveNULL();
	Test35BSTreeItrEqualsTRUE(); 
	Test36BSTreeItrEqualsFALSE();
}
int LessComparatorInt(void* _left, void* _right)
{
    if(*(int*)_left == *(int*)_right)
    {
        return 0;
    }
    if(*(int*)_left > *(int*)_right)
    {
        return 1;
    }
    if(*(int*)_left < *(int*)_right)
    {
        return -1;
    }
}
/*************************************************/
static void Test1BSTreeCreateOk(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);

	if (NULL != pTree)
	{
		printf("Test1 BSTreeCreateOk........Pass\n");
	}
	else
	{	
		printf("Test1 BSTreeCreateOk........Fail\n");
	}
	BSTreeDestroy(&pTree, NULL);
}
static void Test2BSTreeCreateFunNULL(void)
{
    BSTree *pTree = BSTreeCreate(NULL);

	if (NULL == pTree)
	{
		printf("Test2 BSTreeCreateFunNULL........Pass\n");
	}
	else
	{	
		printf("Test2 BSTreeCreateFunNULL........Fail\n");
        BSTreeDestroy(&pTree, NULL);
	}
}
static void Test3BSTreeCreateRootLeft(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);

	if (GetNodeLeft(pTree)==NULL)
	{
		printf("Test3 BSTreeCreate RootLeft........Pass\n");
	}
	else
	{	
		printf("Test3 BSTreeCreate RootLeft........Fail\n");
	}
    BSTreeDestroy(&pTree, NULL);
}
static void Test4BSTreeCreateRootRight(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);

	if (GetNodeRight(pTree)==NULL)
	{
		printf("Test4 BSTreeCreate RootRight........Pass\n");
	}
	else
	{	
		printf("Test4 BSTreeCreate RootRight........Fail\n");
	}
	BSTreeDestroy(&pTree, NULL);
}
static void Test5BSTreeCreateRootFather(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
	if (GetTreeRoot(pTree)==GetRootFather(pTree))
	{
		printf("Test5 BSTreeCreate RootFather........Pass\n");
	}
	else
	{	
		printf("Test5 BSTreeCreate RootFather........Fail\n");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test6BSTreeDestroyNULL(void)
{
    BSTreeDestroy(NULL, NULL);
    printf("Test6 BSTreeDestroy NULL.....PASS\n");
}
static void Test7BSTreeDestroyOK(void)
{
	BSTree *pTree = BSTreeCreate(LessComparatorInt);
    BSTreeDestroy(&pTree, NULL);
   	if (pTree == NULL)
	{
		printf("Test7 BSTreeDestroy OK.......Pass\n");
	}
	else
	{	
		printf("Test7 BSTreeDestroy OK....... Fail\n");
	}
}
static void Test8BSTreeDestroyDubleFree(void)
{
	BSTree *pTree = BSTreeCreate(LessComparatorInt);
    BSTreeDestroy(&pTree, NULL);
    BSTreeDestroy(&pTree, NULL);
    printf("Test8 BSTreeDestroy DubleFree.....PASS\n");
}
/*static void Test9BSTreeFunc(void)
{
	BSTree *pTree = BSTreeCreate(LessComparatorInt);
    BSTreeDestroy(&pTree, NULL);
    printf("Test8 BSTreeDestroy DubleFree.....PASS\n");
}*/
static void Test10BSTreeInsertTreeNULL(void)
{
    int num = 3;
	if (NULL == BSTreeInsert(NULL, &num))
	{
		printf("Test10 TreeInsertTreeNULL.....PASS\n");
	}
	else
	{	
		printf("Test10 TreeInsertTreeNULL.....FAIL\n");
	}
}
static void Test11BSTreeInsertItemeNULL(void)
{
	BSTree *pTree = BSTreeCreate(LessComparatorInt);
	if (NULL == BSTreeInsert(pTree, NULL))
	{
		printf("Test11 BSTreeInsert ItemeNULL.....PASS\n");
	}
	else
	{	
		printf("Test11 BSTreeInsert ItemeNULL.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 

}
static void Test12BSTreeInsertIndexOK(void)
{/*
    void* itr;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    int num1 = 3;
    int num2 = 4;
    BSTreeInsert(pTree, &num1);
    itr = BSTreeInsert(NUpTreeLL, &num2);
	if ((*(int*)Get(itr)) == num2)
	{
		printf("Test12 BSTreeInsert IndexOK.....PASS\n");
	}
	else
	{	
		printf("Test12 BSTreeInsert IndexOK.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 
*/
}
static void Test13BSTreeInsertRoot(void)
{
	void* itr;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    int num1 = 3;
    itr = BSTreeInsert(pTree, &num1);
	if ( num1 ==(*(int*) GetNodeLeftData(pTree)))
	{
		printf("Test13 BSTreeInsertRoot.....PASS\n");
	}
	else
	{	
		printf("Test13 BSTreeInsertRoot.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 

}
static void Test14BSTreeInsertDuplication(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    int num1 = 3;
    BSTreeInsert(pTree, &num1);
	if ( BSTreeInsert(pTree, &num1)==GetTreeRoot(pTree))
	{
		printf("Test14 BSTreeInsert Duplication.....PASS\n");
	}
	else
	{	
		printf("Test14 BSTreeInsert Duplication.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 

}
static void Test15BSTreeInsertOk(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    int num1 = 3;
    int num2 = 3;
    int num3 = 3;
    BSTreeInsert(pTree, &num1);
    BSTreeInsert(pTree, &num2);
	if (NULL != BSTreeInsert(pTree, &num3) )
	{
		printf("Test15 BSTreeInsert OK.....PASS\n");
	}
	else
	{	
		printf("Test15 BSTreeInsert OK.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 

}
static void Test16BSTreeItrBeginOK(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    void* itr;
    int num1 = 3;
    int num2 = 4;
    int num3 = 8;
    BSTreeInsert(pTree, &num1);
    BSTreeInsert(pTree, &num2);
    BSTreeInsert(pTree, &num3);
    itr = BSTreeItrBegin(pTree);
    if( GetData(itr)==&num1)
    {
		printf("Test16 BSTreeItrBegin OK.....PASS\n");
	}
	else
	{	
		printf("Test16 BSTreeItrBegin OK.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test17BSTreeItrBeginEmpty(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    void* itr;
    int num1 = 3;
    int num2 = 4;
    int num3 = 8;
    if(GetTreeRoot(pTree) == BSTreeItrBegin(pTree))
    {
		printf("Test17 BSTreeItrBegin Empty.....PASS\n");
	}
	else
	{	
		printf("Test17 BSTreeItrBegin Empty.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test18BSTreeItrBeginNULL(void)
{ 
    if( NULL == BSTreeItrBegin(NULL))
    {
		printf("Test18 BSTreeItrBegin NULL.....PASS\n");
	}
	else
	{	
		printf("Test18 BSTreeItrBegin NULL.....FAIL\n");
	}
}
static void Test19BSTreeItrEndNULL(void)
{ 
    if( NULL == BSTreeItrEnd(NULL))
    {
		printf("Test19 BSTreeItrEnd NULL.....PASS\n");
	}
	else
	{	
		printf("Test19 BSTreeItrEnd NULL.....FAIL\n");
	}
}
static void Test20BSTreeItrEndOK(void)
{ 
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    void* itr;
    int num1 = 3;
    int num2 = 4;
    int num3 = 8;
    BSTreeInsert(pTree, &num1);
    BSTreeInsert(pTree, &num2);
    BSTreeInsert(pTree, &num3);
    if( BSTreeItrEnd(pTree)==GetTreeRoot(pTree))
    {
		printf("Test20 BSTreeItrEnd OK.....PASS\n");
	}
	else
	{	
		printf("Test20 BSTreeItrEnd OK.....FAIL\n");
	}
}
static void Test21BSTreeItrBeginEmpty(void)
{
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    void* itr;
    int num1 = 3;
    int num2 = 4;
    int num3 = 8;
    if( BSTreeItrEnd(pTree)==GetTreeRoot(pTree))
    {
		printf("Test21 BSTreeItrEnd Empty.....PASS\n");
	}
	else
	{	
		printf("Test21 BSTreeItrEnd Empty.....FAIL\n");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test22BSTreeInsertTreeNULL(void)
{
    BSTreeItr itr;
	int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    itr = BSTreeInsert(NULL, &arr[0]);
	if (itr == NULL)
	{
		printf("%-40s %s\n", "Test22Insert TreeNULL", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test22Insert TreeNULL", "FAIL");
	}
}
static void Test22BSTreeInsertItemNULL(void)
{
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    itr = BSTreeInsert(pTree, NULL);
	if (itr == NULL)
	{
		printf("%-40s %s\n", "Test1Insert ItemNULL", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test1Insert ItemNULL", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test23BSTreeInsertItemDuplicate(void)
{
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
	BSTreeInsert(pTree, &arr[0]);
    itr = BSTreeInsert(pTree, &arr[0]);
	if (itr == GetTreeRoot(pTree))
	{
		printf("%-40s %s\n", "Test23BSTreeInsert Duplicate", "PASS");
	} 
    else 
	{
		printf("%-40s %s\n", "Test23BSTreeInsert Duplicate", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test25BSTreeInsertItemOK(void)
{
	size_t i;
	void* value;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 1; i < SIZE; ++i)
    {
        itr = BSTreeInsert(pTree, &arr[i]);
    }
	value = BSTreeItrGet(itr);
	if (*(int*)value == 40)
	{
		printf("%-40s %s\n", "Test25BSTreeInsert OK", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test25BSTreeInsert OK", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test26NextItrNULL(void)
{
    int i = 0;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr1, itr2, itr3;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
    itr3 = BSTreeItrNext(NULL);
	if (itr3 == NULL)
	{
		printf("%-40s %s\n", "Test26BSTreeNext ItrNULL", "PASS");
	} 
	else {
		printf("%-40s %s\n", "Test26BSTreeNext ItrNULL", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test27NextItrEnd(void)
{
    int i = 0;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr1, itr2, itr3;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
    itr1 = BSTreeItrBegin(pTree);
    itr2 = BSTreeItrEnd(pTree);
	itr3 = BSTreeItrNext(itr2);
    if (itr3 == itr2)
	{
		printf("%-40s %s\n", "Test27BSTreeNext End", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test27BSTreeNext End", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test28NextItrOK(void)
{
    int i = 0;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr1, itr2, itr3;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
    itr1 = BSTreeItrBegin(pTree);/*40*/
	itr2 = BSTreeItrNext(itr1);
	if (*(int*)BSTreeItrGet(itr2) == 50)
	{
		printf("%-40s %s\n", "Test28BSTreeNext OK", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test28BSTreeNext OK", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test29PrevItrNULL(void)
{
    int i = 0;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr1;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
    itr1 = BSTreeItrPrev(NULL);
    if (itr1 == NULL)
	{
		printf("%-40s %s\n", "Test29BSTreePrevItr NULL", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test29BSTreePrevItr NULL", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
}
static void Test30PrevItrBegin(void)
{
	int i = 0;
	void* value;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr1, itr2, itr3;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
    itr1 = BSTreeItrBegin(pTree); /*40*/
	itr2 = BSTreeItrPrev(itr1);
    if (itr2 == itr1)
	{
		printf("%-40s %s\n", "Test30BSTreePrev Begin", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test30BSTreePrev Begin", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL); 
} 

static void Test31PrevItrOK(void)
{
	BSTree *pTree = BSTreeCreate(LessComparatorInt);
	int item1 = 80;
	int item2 = 90;
	int item3 = 95;
	int item4 = 85;
	int item5 = 100;
	void* itr1 = BSTreeInsert(pTree, &item1);
	void* itr2 = BSTreeInsert(pTree, &item2);
	void* itr3 = BSTreeInsert(pTree, &item3);
	void* itr4 = BSTreeInsert(pTree, &item4);
	void* itr5 = BSTreeInsert(pTree, &item5);
	if(BSTreeItrPrev(itr4) == itr1)
	{
		printf("%-40s %s\n", "Test31BSTreePrev OK", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test31BSTreePrev OK", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL);
}
/*	value = BSTreeItrGet(itr2);
	printf("%d",(*(int*)value));*/
static void Test32BSTreeRemoveLEEF(void)
{
	int i = 0;
	void* value, *value2;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 30};
    BSTreeItr itr1, itr2;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
	itr1 = BSTreeItrBegin(pTree);
	value = BSTreeItrRemove(itr1);
	itr2=BSTreeItrBegin(pTree);
	value2 = BSTreeItrGet(itr2);
	if (*(int*)value == 30 &&  (*(int*)value2 )== 50 )
	{
		printf("%-40s %s\n", "Test32BSTreeRemove LEEF", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test32BSTreeRemove LEEF", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL);
}
static void Test33BSTreeRemoveROOT(void)
{
	int i = 0;
	void* value;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr1;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
	if (BSTreeItrRemove(pTree) == NULL)
	{
		printf("%-40s %s\n", "Test33BSTreeRemove ROOT", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test33BSTreeRemove ROOT", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL);
}
static void Test34BSTreeRemoveNULL(void)
{
	int i = 0;
	void* value;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 40};
    BSTreeItr itr1;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
	if (BSTreeItrRemove(NULL) == NULL)
	{
		printf("%-40s %s\n", "Test34BSTreeRemove NULL", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test34BSTreeRemove NULL", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL);
}
static void Test35BSTreeItrEqualsTRUE(void) 
{
	BSTree *ptrTree = BSTreeCreate(LessComparatorInt);
	int item1 = 5;
	if(1 == BSTreeItrEquals(&item1, &item1))
	{
		printf("%-40s %s", "Test35BSTreeItrEquals TRUE","PASS");
	}
	else
	{
		printf("%-40s %s","Test35BSTreeItrEquals TRUE","FAIL");
	}
	BSTreeDestroy(&ptrTree , NULL);
	printf("\n");
}

static void Test36BSTreeItrEqualsFALSE(void)
{
	BSTree *ptrTree = BSTreeCreate(LessComparatorInt);
	int item1 = 4;
	int item2 = 10;
	if( 0 == BSTreeItrEquals(&item1, &item2))
	{
		printf("%-40s %s", "Test36BSTreeItrEquals FALSE","PASS");
	}
	else
	{
		printf("%-40s %s","Test36BSTreeItrEquals FALSE","FAIL");
	}
	BSTreeDestroy(&ptrTree , NULL);
	printf("\n");
}
/*
static void Test37BSTreeRemoveTWOCHILD(void)
{
	int i = 0;
	void* value, *value2;
    int arr[SIZE] = {80, 90, 95, 110, 107, 75, 50, 79, 65, 60, 30};
    BSTreeItr itr1, itr2;
    BSTree *pTree = BSTreeCreate(LessComparatorInt);
    for (i = 0; i < SIZE; ++i)
    {
        itr1 = BSTreeInsert(pTree, &arr[i]);
    }
	itr1 = BSTreeItrBegin(pTree);
	value = BSTreeItrRemove(itr1);
	itr2=BSTreeItrBegin(pTree);
	value2 = BSTreeItrGet(itr2);
	if (*(int*)value == 30 &&  (*(int*)value2 )== 50 )
	{
		printf("%-40s %s\n", "Test37BSTreeRemove TWOCHILD", "PASS");
	} 
    else {
		printf("%-40s %s\n", "Test37BSTreeRemove TWOCHILD", "FAIL");
	}
	BSTreeDestroy(&pTree, NULL);
}*/