output: 
	gcc -g -o output main.c hash_helper.c hash.c getWord/getWord.o
	
clean:
	rm output

test1: output
	./output text.txt
	
test2: output
	./output text.txt text2.txt text3.txt
	
test3: output
	./output 45 text.txt text2.txt text3.txt
	
test: 
	valgrind --leak-check=yes ./output text.txt

gdb: 	
	gdb ./output
	
