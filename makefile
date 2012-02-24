CPPFLAGS ?= -Wall
CFLAGS   ?= -pipe -O2

DESTDIR  ?= /
PREFIX   ?= usr/local

CPPFLAGS += -std=c99

errno: errno.c

%: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

.c:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $>

bin    := $(DESTDIR)$(PREFIX)/bin/

install: $(bin)errno

$(bin)errno: errno $(bin)
	cp -p $(@F) $(@D)

$(bin):
	mkdir -p $@

.PHONY: install
