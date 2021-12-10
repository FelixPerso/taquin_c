but : taquin



OFILES = settings.o\
         taqui_dogmeme.o



CC = gcc

CFLAGS = -Wall -lgraph


#option.o : 'option.c ' 'option.h '

#BML.o : personne.h lire.h

#affchage.o : repertoire.h personne.h

main.o : settings.h affichage.h #end_screen.h count.h


taquin : $(OFILES)
    $(CC) $(CFLAGS) -o taquin $(OFILES)


clean :
    -rm -f $(OFILES) taquin
run :
    -./taquin



.PHONY : but clean
