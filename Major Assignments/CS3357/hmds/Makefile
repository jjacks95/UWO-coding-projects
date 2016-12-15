CC	= gcc
CFLAGS	= -g -O0 -Wall -Werror -std=gnu11 

all: hmds

hmds.o: hmds.c
	$(CC) $(CFLAGS) -c hmds.c -o hmds.o

tcp_connects.o: tcp_connects.c
	$(CC) $(CFLAGS) -c tcp_connects.c -o tcp_connects.o 

hmds: hmds.o ../common/tcp_connects.o
	$(CC) hmds.o ../common/tcp_connects.o -o hmds -lhfs -lhdb -lhiredis


clean:
	rm *.o hmds
