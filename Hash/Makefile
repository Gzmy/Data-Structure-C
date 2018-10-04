.PHONY:clean

main:main.o Hash.o
	gcc -o $@ $^

%.o:%c
	gcc $^ -c -o $@

clean:
	rm -rf *.o main
