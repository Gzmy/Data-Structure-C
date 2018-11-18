.PHONY:clean

main:main.c Sort.o
	gcc -o $@ $^

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm *.o main

