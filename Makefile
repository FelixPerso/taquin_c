taquin : principal.o menus.o taquin.o
	gcc -Wall -ansi -o taquin.out principal.o menus.o taquin.o -lgraph

principal.o : principal.c principal.h
	gcc -c principal.c

taquin.o : taquin.c taquin.h
	gcc -c taquin.c

menus.o : menus.c menus.h
	gcc -c menus.c

run : 
	-./taquin.out

clean :
	-rm -f *.o