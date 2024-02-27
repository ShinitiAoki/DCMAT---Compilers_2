out: lexico.l bison.y
	flex lexico.l
	bison -d bison.y
	gcc *.c -I. -lm -o out

clean:
	rm -f out

# FLEX=flex
# BISON=bison
# BISON-FLAGS= -d -t
# CC=gcc
# CFLAGS= -lm -I.

# SINTATICO = bison.tab.c
# LEXICO = lex.yy.c

# C_FILES = $(wildcard *.c)
# OBJ_FILES = $(C_FILES:.c=.o)

# PROGRAMA = dcmat

# all: projeto

# projeto: $(SINTATICO) $(OBJ_FILES)
# 	$(CC) $(LEXICO) $(SINTATICO) $(OBJ_FILES) $(CFLAGS) -o $(PROGRAMA)

# $(SINTATICO): bison.y $(LEXICO)
# 	$(BISON) $(BISON-FLAGS) bison.y

# $(LEXICO): lexico.l
# 	$(FLEX) lexico.l

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $<

# clean:
# 	rm -f lex.yy.c bison.tab.c bison.tab.h
# 	rm -f *.o
# 	rm -f $(PROGRAMA)