.PHONY:clean

main:BSTree.o main.o
	gcc $^ -o $@

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -rf *.o main
