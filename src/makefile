# Using GCC as the compiler
CC = gcc

# Compiler flags 
# -Wall: Show warnings, -g: Enable debugging
# -I../include: Tell compiler to look for .h files in the ../include directory
CFLAGS = -Wall -g -I../include

# Name of the final executable program
TARGET = hospital_system

# Automatically find all .c files in the current directory (which is src)
SRCS = $(wildcard *.c)

# Generate the names of the corresponding .o (Object) files
OBJS = $(SRCS:.c=.o)

# Default target to run when 'make' is executed
all: $(TARGET)

# Link all object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each .c file individually into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target to clean up old compiled files (Windows version)
clean:
	del /Q /F *.o $(TARGET).exe $(TARGET)