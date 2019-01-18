.PHONY:clean

main: main.o sort.cc
	g++ -o $@ $^
main.o:main.cc
	g++ -c $^ -o $@

clean:
	rm main main.o
