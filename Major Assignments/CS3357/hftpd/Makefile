CC	= gcc
CFLAGS	= -g -O0 -Wall -Werror -std=gnu11

all: hftpd

hftpd.o: hftpd.c
	$(CC) $(CFLAGS) -c hftpd.c -o hftpd.o

tcp_connect.o: tcp_connect.c
	$(CC) $(CFLAGS) -c tcp_connect.c -o tcp_connect.o

udp_connect.o: udp_connect.c
	$(CC) $(CFLAGS) -c udp_connect.c -o udp_connect.o

hftpd: hftpd.o ../common/tcp_connect.o ../common/udp_connect.o
	$(CC) hftpd.o ../common/tcp_connect.o ../common/udp_connect.o -o hftpd


clean:
	rm *.o ../common/*.o hftpd
