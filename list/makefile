# makefile sample

TARGET= ListItrTest.out
CC= gcc
CFLAGS= -ansi -g -pedantic
OBJS= ListItrTest.o ListItr.o GenericDoubleLinkedList.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

ListItrTest.o: ListItrTest.c  ListItr.h 
	$(CC) $(CFLAGS) -c ListItrTest.c
		
ListItr.o: ListItr.c ListItr.h 
	$(CC) $(CFLAGS) -c ListItr.c
	
GenericDoubleLinkedList.o: GenericDoubleLinkedList.c GenericDoubleLinkedList.h
	$(CC) $(CFLAGS) -c GenericDoubleLinkedList.c
	
clean:
	rm -f $(TARGET) $(OBJS)

