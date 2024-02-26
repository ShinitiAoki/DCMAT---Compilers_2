out: lexico.l bison.y
	flex lexico.l
	bison -d bison.y
	gcc *.c -I. -lm -o out

clean:
	rm -f out