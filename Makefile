TARGET  = 256to
LNK1  = 10to
LNK2  = loop
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: clean $(TARGET) link

clean:
	rm -rf $(TARGET) *.o $(LNK1) $(LNK2)

$(TARGET): $(OBJS)
	cc -o $@ $(OBJS) $(LDFLAGS)

link:
	ln -sf $(TARGET) $(LNK1)
	ln -sf $(TARGET) $(LNK2)

check:
	bash check.sh

.PHONY : all clean link check
