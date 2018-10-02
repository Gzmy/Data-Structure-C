.PHONY:clean

main:main.o Heap.o
	gcc -o $@ $^

%o:%c
	gcc -c $^ -o $@

clean:
	rm -rf *.o main
