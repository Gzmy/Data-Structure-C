.PHONY:clean

main:Interview.o main.o Stack.o Queue.o
	gcc -o $@ $^

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -rf main *.o
