.PHONY : clean

main : main.o BTree.o
	gcc $^ -o $@

%.o : %.c
	gcc -c $^ -o $@

clean:
	rm -rf *.o main
