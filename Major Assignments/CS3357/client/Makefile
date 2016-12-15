CC	= gcc
CFLAGS	= -g -O0 -Wall -Werror -std=gnu11

all: client

client.o: client.c
	$(CC) $(CFLAGS) -c client.c -o client.o

tcp_connect.o: tcp_connect.c
	$(CC) $(CFLAGS) -c tcp_connect.c -o tcp_connect.o

udp_connect.o: udp_connect.c
	$(CC) $(CFLAGS) -c udp_connect.c -o udp_connect.o

client: client.o ../common/tcp_connect.o ../common/udp_connect.o
	$(CC) client.o ../common/tcp_connect.o ../common/udp_connect.o -o client


clean:
	rm *.o ../common/*.o client
