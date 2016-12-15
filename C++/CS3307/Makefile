OBJS = account.o user.o main.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o p1

account.o : account.h account.cpp user.h
    $(CC) $(CFLAGS) account.cpp

user.o : user.h user.cpp account.h
    $(CC) $(CFLAGS) user.cpp

main.o : account.h main.cpp user.h 
    $(CC) $(CFLAGS) main.cpp

clean:
    \rm *.o *~ p1
