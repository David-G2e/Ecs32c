CFLAGS = -Wall -Werror 

# target: pre-requisites
# 	actions

# Default
output: selsort.o
	@echo "Generating the output executable"
	gcc ${CFLAGS} selsort.o -o selsort

selsort.o: selsort.c
	@echo "generating the object file for selsort"
	gcc ${CFLAGS} -c selsort.c -o selsort.o

clean: 
	@echo "Cleaning files..."
	rm *.o selsort