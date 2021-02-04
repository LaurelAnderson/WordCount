output: 
	gcc -g -o wordpairs main.c hash_helper.c hash.c getWord/getWord.o dict/crc64.o
	
clean:
	rm wordpairs

test1: wordpairs
	./wordpairs -5 mobydick.txt
	
test2: wordpairs
	./wordpairs dracula.txt frankenstein.txt mobydick.txt
	
test3: wordpairs
	./wordpairs -10 dracula.txt frankenstein.txt mobydick.txt gettysburg.txt
	
test: 
	valgrind --leak-check=yes ./wordpairs -5 mobydick.txt

gdb: 	
	gdb ./wordpairs
	
