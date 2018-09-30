.PHONY : clean

main : main.c Queue.o
	gcc -o $@ $^

%.o : %.c
	gcc -c $^ -o $@

clean :
	rm -rf main *.o

