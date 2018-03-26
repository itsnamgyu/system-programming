ASSIGNMENT = sp20161662_proj1

default: 
	cd src && $(MAKE) && cp a.out .. && $(MAKE) clean

clean:
	-rm a.out
	-rm -r $(ASSIGNMENT)

assignment:
	-rm -r $(ASSIGNMENT)
	mkdir .t
	cp README.md .t/README
	cp opcode.txt .t
	cp src/* .t
	mv .t/main.c .t/20161662.c
	echo 'MAINC = 20161662.c\n' | cat - .t/Makefile > .temp
	mv .temp .t/Makefile
	echo 'TARGET = 20161662.out' | cat - .t/Makefile > .temp
	mv .temp .t/Makefile
	mv .t $(ASSIGNMENT)
	
.DEFAULT :
	cd src && $(MAKE) $@