.PHONY:clean

main:main.o trans.o
	gcc -o $@ $^

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm *.o main
