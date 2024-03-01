tokenizer: history.o tokenizer.o UImain.o
	gcc -o tokenizer history.o tokenizer.o UImain.o

history.o: history.h history.c

tokenizer.o: tokenizer.h tokenizer.c

UImain.o: UImain.c

run: 
	./tokenizer

clean:
	rm -f *.o tokenizer

debugger: history.o tokenizer.o UImain.o
	gcc -Wall -o debug history.o tokenizer.o UImain.o

debug:
	./debugger

