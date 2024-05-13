# Compiler
CC = gcc
# Compiler Flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRCS := $(wildcard *.c) $(wildcard *.h) $(wildcard ../cstdlib/*.c) $(wildcard ../cstdlib/*.h)

# Object files
OBJS := $(SRCS:.c=.o)

# Executable name
EXEC = primes

# Main target
all: $(EXEC)

install: clean all

# Linking
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile C source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f primes $(wildcard *.o) 

run:
	./primes
