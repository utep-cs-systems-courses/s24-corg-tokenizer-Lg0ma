tokenizer: history.o tokenizer.o
	gcc -o tokenizer history.o tokenizer.o

history.h: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c

run: 
	./tokenizer

clean:
	rm -f *.o tokenizer
