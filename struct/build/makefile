all:bank

.PHONY:all

VPATH = ./..

objects = main.o queue.o linklist.o func.o bank.o

bank : $(objects)
		cc -o bank $(objects)

main.o : HEAD.h linklist.h
queue.o : HEAD.h
linklist.o : HEAD.h linklist.h
func.o : HEAD.h
bank.o : HEAD.h linklist.h

.PHONY : clean
clean :
	rm bank $(objects)