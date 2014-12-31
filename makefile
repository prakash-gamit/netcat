CC= gcc
CFLAGS= -Wall
BINARY= netcat

default:	netcat_core.o netcat_client.o netcat_listen.o netcat_main.o
	$(CC) $(CFLAGS) -o $(BINARY) $^

.o.c:
	$(CC) $(CFLAGS) -c $<

clean:
	-rm -f *.o
	-rm -f netcat
