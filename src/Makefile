CFLAGS = -g
all:tokenize

tokenize: tokenizer.o
	cc -o tokenize tokenizer.o

tokenize.o: tokenizer.c tokenizer.h

run:
	./tokenize

clean:
	rm -r *.o tokenize
