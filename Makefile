# Specify the target file and the install directory
OUTPUTFILE=main

# Default target
.PHONY: all
all: $(OUTPUTFILE)

$(OUTPUTFILE): main.c
	gcc -g -o main main.c

.PHONY: clean 
clean:
	rm $(OUTPUTFILE)
