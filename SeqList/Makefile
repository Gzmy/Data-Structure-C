.PHONY : clean

main : main.o SeqList.o
	gcc $^ -o $@

%.o : %.c
	gcc -c $^ -o $@

clean :
	rm -rf *.o main
