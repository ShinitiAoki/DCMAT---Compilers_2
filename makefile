dcmat: lexico.l bison.y
	flex lexico.l
	bison -d bison.y
	gcc *.c -I. -lm -o dcmat


clean:
	rm -f dcmat bison.tab.c bison.tab.h lex.yy.c
