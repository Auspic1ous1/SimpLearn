# Fixed Makefile for Yacc/Lex Compiler (No library dependencies)

# Compiler and tools
CC = gcc
YACC = yacc
LEX = lex
CFLAGS = -Wall -g

# File names
PARSER = parser.y
LEXER = lexer.l
TARGET = compiler
YACC_OUTPUT = y.tab.c
YACC_HEADER = y.tab.h
LEX_OUTPUT = lex.yy.c

# Default target
all: $(TARGET)

# Build the final executable (without -ly -ll)
$(TARGET): $(YACC_OUTPUT) $(LEX_OUTPUT)
	$(CC) $(CFLAGS) -o $(TARGET) $(YACC_OUTPUT) $(LEX_OUTPUT)

# Generate C code from yacc file
$(YACC_OUTPUT) $(YACC_HEADER): $(PARSER)
	$(YACC) -d $(PARSER)

# Generate C code from lex file (depends on yacc header)
$(LEX_OUTPUT): $(LEXER) $(YACC_HEADER)
	$(LEX) $(LEXER)

# Clean up generated files
clean:
	rm -f $(TARGET) $(YACC_OUTPUT) $(YACC_HEADER) $(LEX_OUTPUT) *.o a.c

# Test with a sample program
test: $(TARGET)
	@echo "Creating sample test program..."
	@echo "program test;" > test_program.txt
	@echo "var" >> test_program.txt
	@echo "  x, y: int;" >> test_program.txt
	@echo "begin" >> test_program.txt
	@echo "  read(x);" >> test_program.txt
	@echo "  y := x + 5;" >> test_program.txt
	@echo "  print(y);" >> test_program.txt
	@echo "end" >> test_program.txt
	@echo "Running compiler on test program..."
	./$(TARGET) test_program.txt
	@if [ -f a.c ]; then echo "Generated C code:"; cat a.c; fi

# Force rebuild
rebuild: clean all

# Help target
help:
	@echo "Available targets:"
	@echo "  all         - Build the compiler (default)"
	@echo "  clean       - Remove all generated files"
	@echo "  test        - Build and test with sample program"
	@echo "  rebuild     - Clean and rebuild"
	@echo "  help        - Show this help message"

# Declare phony targets
.PHONY: all clean test rebuild help