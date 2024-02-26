out: lexico.l bison.y
	flex lexico.l
	bison -d bison.y
	gcc *.c -I. -lm -o out


# # Define the compiler
# CC = gcc
# # Define flags for the compiler
# CFLAGS = -Wall -g -lm
# # Define the output file name
# OUTPUT = dcmat
# # Define all the source files
# SOURCES = hashtable.c matriz.c varTypes.c lexico.l bison.y
# # Define the object files
# OBJECTS = $(SOURCES:.c=.o) $(SOURCES:.l=.yy.c) $(SOURCES:.y=.tab.c)
# # Define the dependency for bison.tab.c
# bison.tab.c: bison.y
# 	bison -d bison.y

# # Define the dependency for lex.yy.c
# lex.yy.c: lexico.l
# 	flex lexico.l

# # All rule - builds the program
# all: $(OUTPUT)

# # Define how to build the program
# $(OUTPUT): $(OBJECTS)
# $(CC) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)
