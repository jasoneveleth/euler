# C compiler
CLANGFLAGS = -fsyntax-only -Ofast -std=c99 -Werror -Weverything -Wno-poison-system-directories

CFLAGS = -std=c99
CFLAGS += -Wall -Wextra -Wpedantic -Wconversion -Wdouble-promotion -Wnull-dereference -Wignored-attributes -Wattributes -Wswitch-default -Wfloat-equal -Wshadow -Wunused-macros -Wdangling-else -Wstrict-prototypes -Wpadded -Wredundant-decls -Wnested-externs -Winline -Werror
CFLAGS += -Ofast
# CFLAGS += -g -O0

EXECS = prob627 prob067
EXECS += prob009 prob010 prob011 prob012 prob013 prob014 prob017 prob018 
EXECS += prob019 prob022

.PHONY: all clean run debug

all: $(EXECS)

% :: %.c
	clang $(CLANGFLAGS) $<
	gcc $< $(CFLAGS) -o $@

clean:
	rm -vf $(EXECS)
	rm -rvf *.dSYM

run:
	./.utilities/run_curr_binary
