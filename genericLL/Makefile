CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = primitive_types_functions.o genericLL.o main.o 
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~