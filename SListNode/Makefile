.PHONY : clean

main : SListNode.o main.o
	gcc $^ -o $@

%.o : %.c
	gcc -c $^ -o $@

clean :
	rm -rf *.o main
