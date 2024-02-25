# makefile sample

TARGET= tree.out
CC= gcc
CFLAGS= -ansi -g -pedantic
OBJS= Gtree.o GtreeTests.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

Gtree.o: Gtree.c  Gtree.h 
	$(CC) $(CFLAGS) -c Gtree.c
		
GtreeTests.o: GtreeTests.c Gtree.h 
	$(CC) $(CFLAGS) -c GtreeTests.c
	
clean:
	rm -f $(TARGET) $(OBJS)

