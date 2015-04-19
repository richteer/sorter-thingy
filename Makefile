#Written by Chris Harding
SHELL   = /bin/bash
TARGET  = sorter
CC      = clang
CFLAGS  = -c -g
LDFLAGS = -lpthread

SRCS := main.c io.c thread.c file.c sort.c
DEPS := $(addprefix dep/,$(patsubst %.c,%.d,$(SRCS)))
OBJS := $(addprefix obj/,$(patsubst %.c,%.o,$(SRCS)))
SRCS := $(addprefix src/,$(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) $(OBJS)  $(LDFLAGS) -o $(TARGET)

obj/%.o: src/%.c
	@ mkdir -p $(@D)
	@ mkdir -p $(subst obj,dep,$(@D))
	$(CC) -MM -MP -MT $@ -MF $(patsubst %.o,%.d,$(subst obj,dep,$@)) $<
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf obj
	rm -rf dep
	rm -f $(TARGET)

-include $(DEPS)
