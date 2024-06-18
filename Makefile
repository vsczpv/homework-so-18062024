INCLUDE = include
SOURCE  = source
BUILD   = build

CC    = cc
CARGS = -Wall -Wextra -g -O0 -I$(INCLUDE)

OBJS    = $(shell find $(SOURCE) -type f -name '*.c' | sed 's/\.c*$$/\.o/; s/$(SOURCE)\//$(BUILD)\//')
HEADERS = $(shell find $(INCLUDE) -type f -name '*.h')

NAME = obese16

.PHONY: builddir

all: $(NAME)

builddir:
	@if [ ! -d "build" ] ; then mkdir build ; fi

$(OBJS): $(BUILD)/%.o: $(SOURCE)/%.c $(HEADERS)
	$(CC) -c $(CARGS) $< -o $@

clean:
	rm -vf $(NAME) $(UBJS) $(OBJS)

$(NAME): builddir $(OBJS)
	$(CC) $(CARGS) $(OBJS) -o $@
