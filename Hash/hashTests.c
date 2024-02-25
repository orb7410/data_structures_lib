#include <stdio.h>
#include <stddef.h>
#include "hash.h"
#define TRUE 1
#define FALSE 2
size_t FinfdPrime (size_t _size);
size_t GetNewSize(Hash *_hash);
size_t HashGetnRealSize(Hash *_hash);
size_t HashGetNumOfItems(Hash *_hash);
size_t GetInsertionsCount(Hash *_hash);
size_t GetMaxOfRehash(Hash *_hash);
size_t GetAllRehash(Hash *_hash);

static void Test1_HashCreateSizeIsZero(void);
static void Test2_HashCreateHushFuncIsNull(void);
static void Test3_HashCreateEqualityFunIsNull(void);
static void Test4_HashCreateIfOK(void);
static void Test5_HashCreateIfSizeAndRealSizeIsOK(void);
static void Test6_HashCreateIfItemNumIsOK(void);
static void Test7_HashCreateIfCountAndMaxOfRehashAndAllRehashIsOK(void);
static void Test1HashDestroyNULL(void);
static void Test2HashDestroyOK(void);
static void Test3HashDestroyDubleFree(void);
static void Test4HashDestroyOK(void);
static void Test1HashInsertHashNULL(void);
static void Test2HashInsertDataNULL(void);
static void Test3HashInsertDuplicat(void);
static void Test4HashInsertOverFlow(void);
static void Test5HashInsertInsertedOK(void);
static void Test6HashInsertInsertedSizeIncreas(void);
static void Test1_HashRemoveIfHashIsNull(void);
static void Test2_HashRemoveIfKeyIsNull(void);
static void Test3_HashRemoveIfHashIsEmpty(void);
static void Test4_HashRemoveIfHashSucces(void);
static void Test5_HashRemoveIfHashKeyNotFound(void);
static void Test6_HashRemoveNumOfItems(void);
static void Test7_HashRemoveDataOK(void);
static void Test1_HashNumOfItems_hashNull();
static void Test2_HashNumOfItems_working();
static void Test1_HashCapacity_hashNull();
static void Test2_HashCapacity_working();
static void Test1_HashAverageRehashes_hashNull();
static void Test2_HashAverageRehashes_working();
static void Test1_HashMaxReHash_hashNull();
static void Test2_HashMaxReHash_working();
static void Test1_HashPrint_working();

int main()
{
    Test1_HashCreateSizeIsZero();
	Test2_HashCreateHushFuncIsNull();
	Test3_HashCreateEqualityFunIsNull();
	Test4_HashCreateIfOK();
	Test5_HashCreateIfSizeAndRealSizeIsOK();
	Test6_HashCreateIfItemNumIsOK();
	Test7_HashCreateIfCountAndMaxOfRehashAndAllRehashIsOK();
    Test1HashDestroyNULL();
    Test2HashDestroyOK();
    Test3HashDestroyDubleFree();
    Test4HashDestroyOK();
    Test1HashInsertHashNULL();
    Test2HashInsertDataNULL();
    Test3HashInsertDuplicat();
    Test4HashInsertOverFlow();
    Test5HashInsertInsertedOK();
    Test6HashInsertInsertedSizeIncreas();
	Test1_HashRemoveIfHashIsNull();
	Test2_HashRemoveIfKeyIsNull();
	Test3_HashRemoveIfHashIsEmpty();
	Test4_HashRemoveIfHashSucces();
	Test5_HashRemoveIfHashKeyNotFound();
	Test6_HashRemoveNumOfItems();
	Test7_HashRemoveDataOK();
     Test1_HashNumOfItems_hashNull();
    Test2_HashNumOfItems_working();
    Test1_HashCapacity_hashNull();
    Test2_HashCapacity_working();
    Test1_HashAverageRehashes_hashNull();
    Test2_HashAverageRehashes_working();
    Test1_HashMaxReHash_hashNull();
    Test2_HashMaxReHash_working();
    Test1_HashPrint_working();


}
size_t HashFunc(void* _data)
{
    return ((size_t)((*(int*)_data)*2));
}
int EqualityFuncInt(void* _firstData, void* _secondData)
{
    return(*(int*)_firstData == *(int*)_secondData);
}
void PrintKeyInt(void* _data)
{
   printf("%d ", (*(int*)_data)); 
}

static void Test1_HashCreateSizeIsZero(void)
{
	Hash *ptrHash;
	ptrHash = HashCreate( 0 , HashFunc,EqualityFuncInt);
	if(NULL == ptrHash)
	{
		printf("Test1 HashCreate SizeIsZero.....PASS\n");
	}
	else
	{
		printf("Test1 HashCreate SizeIsZero....... Fail\n");
        HashDestroy(&ptrHash, NULL);
	}
	
}

static void Test2_HashCreateHushFuncIsNull(void)
{
	Hash *ptrHash;
	ptrHash = HashCreate( 5 , NULL,EqualityFuncInt);
	if(NULL == ptrHash)
	{
		printf("Test2 HashCreate HushFuncIsNull.....PASS\n");
	}
	else
	{
		printf("Test2 HashCreate HushFuncIsNull....... Fail\n");
        HashDestroy(&ptrHash, NULL);
	}
}

static void Test3_HashCreateEqualityFunIsNull(void)
{
	Hash *ptrHash;
	ptrHash = HashCreate( 5 , HashFunc, NULL);
	if(NULL == ptrHash)
	{
		printf("Test3 HashCreate EqualityFunIsNull.....PASS\n");
	}
	else
	{
		printf("Test3 HashCreate EqualityFunIsNull....... Fail\n");
        HashDestroy(&ptrHash, NULL);
	}
	
}

static void Test4_HashCreateIfOK(void)
{
	Hash *ptrHash;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	if(NULL != ptrHash)
	{
		printf("Test4 HashCreate OK.....PASS\n");
	}
	else
	{
		printf("Test4 HashCreate OK....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test5_HashCreateIfSizeAndRealSizeIsOK(void)
{
	Hash *ptrHash;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	if(GetNewSize(ptrHash) == FinfdPrime(5*1.3) && HashGetnRealSize(ptrHash) == 5)
	{
		printf("Test5 HashCreate SizeAndRealSizeIsOK.....PASS\n");
	}
	else
	{
		printf("Test5 HashCreate SizeAndRealSizeIsOK....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test6_HashCreateIfItemNumIsOK(void)
{
	Hash *ptrHash;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	if(HashGetNumOfItems(ptrHash) == 0)
	{
		printf("Test6 HashCreate ItemNumOK.....PASS\n");
	}
	else
	{
		printf("Test6 HashCreate ItemNumOK....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test7_HashCreateIfCountAndMaxOfRehashAndAllRehashIsOK(void)
{
	Hash *ptrHash;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	if(GetInsertionsCount(ptrHash) == 0 && GetMaxOfRehash(ptrHash) == 0 && GetAllRehash(ptrHash) == 0 )
	{
		printf("Test7 HashCreate CountAndMaxOfRehashAndAllRehashIsOK.....PASS\n");
	}
	else
	{
		printf("Test7_HashCreate CountAndMaxOfRehashAndAllRehashIsOK....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test1HashDestroyNULL(void)
{
    HashDestroy(NULL, NULL);
    printf("Test1 HashDestroy NULL.....PASS\n");
}
static void Test2HashDestroyOK(void)
{
	Hash *ptrHash = HashCreate(5,HashFunc,EqualityFuncInt );
    HashDestroy(&ptrHash, NULL);
   	if (ptrHash == NULL)
	{
		printf("Test2 HashDestroy OK.......Pass\n");
	}
	else
	{	
		printf("Test2 HashDestroy OK....... Fail\n");
	}
}
static void Test3HashDestroyDubleFree(void)
{
    Hash *ptrHash = HashCreate(5,HashFunc,EqualityFuncInt );
    HashDestroy(&ptrHash, NULL);
    HashDestroy(&ptrHash, NULL);
    printf("Test3 HashDestroy DubleFree.....PASS\n");
}
static void Test4HashDestroyOK(void)
{
	Hash *ptrHash = HashCreate(5,HashFunc,EqualityFuncInt );
    HashDestroy(&ptrHash, NULL);
   	if (ptrHash == NULL)
	{
		printf("Test4 HashDestroy OK.......Pass\n");
	}
	else
	{	
		printf("Test4 HashDestroy OK....... Fail\n");
	}
}
static void Test1HashInsertHashNULL(void)
{
    int num1 = 3;
    if (SET_UNINITIALIZED == HashInsert(NULL, &num1))
	{
		printf("Test1 HashInsert HashNULL.......Pass\n");
	}
	else
	{	
		printf("Test1 HashInsert HashNULL....... Fail\n");
	}
}
static void Test2HashInsertDataNULL(void)
{
    Hash *ptrHash = HashCreate(5,HashFunc,EqualityFuncInt);
    if (SET_UNINITIALIZED == HashInsert(ptrHash, NULL))
	{
		printf("Test2 HashInsert DataNULL.......Pass\n");
	}
	else
	{	
		printf("Test2 HashInsert DataNULL....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);
}
static void Test3HashInsertDuplicat(void)
{
    Hash *ptrHash = HashCreate(5,HashFunc,EqualityFuncInt);
    int num1 = 3;
    int num2 = 3;
    HashInsert(ptrHash, &num1);
    if (SET_KEY_DUPLICATE == HashInsert(ptrHash, &num2))
	{
		printf("Test3 HashInsert DUPLICATE.......Pass\n");
	}
	else
	{	
		printf("Test3 HashInsert DUPLICATE....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);
}
static void Test4HashInsertOverFlow(void)
{
    Hash *ptrHash = HashCreate(3,HashFunc,EqualityFuncInt);
    int num1 = 3;
    int num2 = 5;
    int num3 = 8;
    int num4 = 10;
    HashInsert(ptrHash, &num1);
    HashInsert(ptrHash, &num2);
    HashInsert(ptrHash, &num3);
    if (SET_OVERFLOW == HashInsert(ptrHash, &num4))
	{
		printf("Test4 HashInsert OverFlow.......Pass\n");
	}
	else
	{	
		printf("Test4 HashInsertOverFlow....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);
}
static void Test5HashInsertInsertedOK(void)
{
    Hash *ptrHash = HashCreate(5,HashFunc,EqualityFuncInt);
    int num1 = 3;
    int num2 = 2;
    int num3 = 8;
    int num4 = 10;
    HashInsert(ptrHash, &num1);
    HashInsert(ptrHash, &num2);
    if (HashIsFound(ptrHash, &num2) == TRUE && HashIsFound(ptrHash, &num1) == TRUE)
	{
		printf("Test5 HashInsert Inserted.......Pass\n");
	}
	else
	{	
		printf("Test5 HashInsert Inserted....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);
}
static void Test6HashInsertInsertedSizeIncreas(void)
{
    Hash *ptrHash = HashCreate(5,HashFunc,EqualityFuncInt);
    int num1 = 3;
    int num2 = 2;
    HashInsert(ptrHash, &num1);
    HashInsert(ptrHash, &num2);
    if (HashGetNumOfItems(ptrHash) == 2)
	{
		printf("Test6 HashInsert SizeIncreas.......Pass\n");
	}
	else
	{	
		printf("Test6 HashInsert SizeIncreas....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);
}
static void Test1_HashRemoveIfHashIsNull(void)
{
	Hash *ptrHash;
	void* data;
	int num = 5;
	ptrHash = HashCreate( 5 ,HashFunc,EqualityFuncInt);

	if(HashRemove(NULL, &num, &data) == SET_UNINITIALIZED)
	{
		printf("Test1 HashRemove HashIsNull.....PASS\n");
	}
	else
	{
		printf("Test1 HashRemove HashIsNull....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test2_HashRemoveIfKeyIsNull(void)
{
	Hash *ptrHash;
	void* data;
	int num = 5;
	ptrHash = HashCreate( 5 ,HashFunc,EqualityFuncInt);
	if(HashRemove(ptrHash, NULL, &data) == SET_UNINITIALIZED)
	{
		printf("Test2 HashRemove KeyIsNull.....PASS\n");
	}
	else
	{
		printf("Test2 HashRemove KeyIsNull....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test3_HashRemoveIfHashIsEmpty(void)
{
	Hash *ptrHash;
	void* data;
	int num = 5;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	if(HashRemove(ptrHash, &num, &data) == SET_UNDERFLOW)
	{
		printf("Test3 HashRemove HashIsEmpty.....PASS\n");
	}
	else
	{
		printf("Test3 HashRemove HashIsEmpty....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test4_HashRemoveIfHashSucces(void)
{
	Hash *ptrHash;
	void* data;
	int num1 = 5, num2 = 4, num3 = 8, num4 = 6, num5 = 9 ;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	HashInsert(ptrHash, &num1);
	HashInsert(ptrHash, &num2);
	HashRemove(ptrHash, &num1, &data);
	if(HashIsFound(ptrHash, &num1) == FALSE)
	{
		printf("Test4 HashRemove HashSucces.....PASS\n");
	}
	else
	{
		printf("Test4 HashRemove HashSucces....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test5_HashRemoveIfHashKeyNotFound(void)
{
	Hash *ptrHash;
	void* data;
	int num1 = 5, num2 = 4, num3 = 8, num4 = 6, num5 = 9 ;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	HashInsert(ptrHash, &num1);
	HashInsert(ptrHash, &num2);
	HashInsert(ptrHash, &num3);
	if(HashRemove(ptrHash, &num4, &data) == SET_KEY_NOT_FOUND)
	{
		printf("Test5 HashRemove HashKeyNotFound.....PASS\n");
	}
	else
	{
		printf("Test5 HashRemove HashKeyNotFound....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test6_HashRemoveNumOfItems(void)
{
	Hash *ptrHash;
	void* data;
	int num1 = 5, num2 = 4, num3 = 8, num4 = 6, num5 = 9 ;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	HashInsert(ptrHash, &num1);
	HashInsert(ptrHash, &num2);
	HashInsert(ptrHash, &num3);
	HashRemove(ptrHash, &num1, &data);
	if(HashGetNumOfItems(ptrHash) == 2) 
	{
		printf("Test6 HashRemove NumOfItems.....PASS\n");
	}
	else
	{
		printf("Test6 HashRemove NumOfItems....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}

static void Test7_HashRemoveDataOK(void)
{
	Hash *ptrHash;
	void* data;
	int num1 = 5, num2 = 4, num3 = 8, num4 = 6, num5 = 9 ;
	ptrHash = HashCreate( 5 , HashFunc,EqualityFuncInt);
	HashInsert(ptrHash, &num1);
	HashInsert(ptrHash, &num2);
	HashInsert(ptrHash, &num3);
	HashRemove(ptrHash, &num1, &data);
	if(data == &num1)
	{
		printf("Test7 HashRemove DataOK.....PASS\n");
	}
	else
	{
		printf("Test7 HashRemove DataOK....... Fail\n");
	}
	HashDestroy(&ptrHash, NULL);
}
static void Test1_HashNumOfItems_hashNull()
{
	if(HashNumOfItems(NULL) == 0)
	{
		printf("Test1 HashNumOfItems hashNull.....PASS\n");
	}
	else 
	{
		printf("Test1 HashNumOfItems hashNull....... Fail\n");
	}
}

static void Test2_HashNumOfItems_working()
{
	Hash* ptrHash = HashCreate(10,  HashFunc,EqualityFuncInt);
    int data1 = 3;
    int data2 = 8;
    int data3 = 14;
    HashInsert(ptrHash, &data1);
    HashInsert(ptrHash, &data2);
    HashInsert(ptrHash, &data3);
    if(HashNumOfItems(ptrHash) == HashGetNumOfItems(ptrHash))
	{
		printf("Test1 HashNumOfItems hashNull.....PASS\n");
	}
	else 
	{
		printf("Test1 HashNumOfItems hashNull....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);
}

static void Test1_HashCapacity_hashNull()
{
    if(HashCapacity(NULL) == 0)
	{
		printf("Test1 HashCapacity hashNull.....PASS\n");
	}
	else 
	{
		printf("Test1 HashCapacity hashNull....... Fail\n");
	}
}

static void Test2_HashCapacity_working()
{
	Hash* ptrHash = HashCreate(10,  HashFunc,EqualityFuncInt);
    if(HashCapacity(ptrHash) == 10)
	{
		printf("Test2 HashCapacity working.....PASS\n");
	}
	else 
	{
		printf("Test2 HashCapacity working....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);
}

static void Test1_HashAverageRehashes_hashNull()
{
    if(HashAverageRehashes(NULL) == 0)
	{
		printf("Test1 HashAverageRehashes hashNull.....PASS\n");
	}
	else 
	{
		printf("Test1 HashAverageRehashes hashNull....... Fail\n");
	}
}


static void Test2_HashAverageRehashes_working()
{
    Hash* ptrHash = HashCreate(10,  HashFunc,EqualityFuncInt);
    int data1 = 3;
    int data2 = 8;
    int data3 = 14;
    size_t allRehash, counterInseration;
    double result;
    HashInsert(ptrHash, &data1);
    HashInsert(ptrHash, &data2);
    HashInsert(ptrHash, &data3);
    allRehash = GetAllRehash(ptrHash);
    result = (allRehash/counterInseration);
    counterInseration = GetInsertionsCount(ptrHash);
    if(HashAverageRehashes(ptrHash) == result)
	{
		printf("Test2 HashAverageRehashes working.....PASS\n");
	}
	else 
	{
		printf("Test2 HashAverageRehashes working....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);

}

static void Test1_HashMaxReHash_hashNull()
{
    if(HashAverageRehashes(NULL) == 0)
	{
		printf("Test1 HashMaxReHash hashNull.....PASS\n");
	}
	else 
	{
		printf("Test1 HashMaxReHash hashNull....... Fail\n");
	}
}

static void Test2_HashMaxReHash_working()
{
    Hash* ptrHash = HashCreate(10, HashFunc,EqualityFuncInt);
    int data1 = 3;
    int data2 = 8;
    int data3 = 14;
    HashInsert(ptrHash, &data1);
    HashInsert(ptrHash, &data2);
    HashInsert(ptrHash, &data3);
    if(HashMaxReHash(ptrHash) == GetMaxOfRehash(ptrHash))
	{
		printf("Test2 HashMaxReHash working.....PASS\n");
	}
	else 
	{
		printf("Test2 HashMaxReHash working....... Fail\n");
	}
    HashDestroy(&ptrHash, NULL);

}   

static void Test1_HashPrint_working()
{
    Hash* ptrHash = HashCreate(10,  HashFunc,EqualityFuncInt);
    int data1 = 3;
    int data2 = 8;
    int data3 = 14;
    HashInsert(ptrHash, &data1);
    HashInsert(ptrHash, &data2);
    HashInsert(ptrHash, &data3);
	printf("Test1 HashPrint working: \n");
    HashPrint(ptrHash, PrintKeyInt);
    printf("\n");

}
