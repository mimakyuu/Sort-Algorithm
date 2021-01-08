CC 	= gcc
TARGET	= main
OBJS 	= sort-main.o sort-funcs.o sort-all.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

.c.o:
	$(CC) $(INCLUDES) -c $<


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
