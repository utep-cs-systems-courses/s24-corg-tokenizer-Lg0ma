//use UI
tokenize: tokenizer.o
	gcc -o tokenize tokenizer.o

tokenizer:history.o tokenizer.o
	gcc -o tokenizer history.o tokenizer.o

tokenize.o: tokenizer.c tokenizer.h

history.h: history.c history.h

tokenizer: 
	./tokenizer

test:
	./tokenize

clean:
	rm -r *.o tokenize
