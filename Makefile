
CC=clang
CFLAGS=-Os -Wall -Werror

.PHONY: profile

all: for.elf switch.elf profile

profile: for.elf switch.elf

%.elf: %.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

profile:
	time ./for.elf >/dev/null
	time ./switch.elf >/dev/null
	nm -print-size for.elf|grep loop
	nm -print-size switch.elf|grep loop

