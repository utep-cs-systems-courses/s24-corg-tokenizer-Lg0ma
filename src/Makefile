CFLAGS = -g
all:tokenize

tokenize: tokenizer.o
	cc -o tokenize tokenizer.o

tokenize.o: tokenizer.c

clean:
	rm -r *.o tokenize

run:
	./tokenize
