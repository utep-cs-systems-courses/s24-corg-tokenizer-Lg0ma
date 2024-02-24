#tokenize: tokenizer.o
#	gcc -o tokenize tokenizer.o

tokenizer:history.o tokenizer.o
	gcc -o tokenizer history.o tokenizer.o

tokenizer.o:
	tokenizer.h tokenizer.c

history.h:
	history.h history.c

run: 
	./tokenizer

#test:
#	./tokenize

clean:
	rm -r *.o tokenizer
