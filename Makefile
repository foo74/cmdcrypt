all: cmdcrypt

cmdcrypt: cmdcrypt.c cmdcrypt.h
	gcc cmdcrypt.c -Wall -o cmdcrypt

run:
	./cmdcrypt

debug:
	gcc cmdcrypt.c -Wall -g -o cmdcrypt

edit:
	vim cmdcrypt.c

clean:
	rm cmdcrypt 
