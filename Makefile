output: 
	gcc -g -o output main.c getWord/getWord.o
	
clean:
	rm output

run: output
	./output text.txt
	
test: 
	valgrind --leak-check=yes ./output text.txt
	
