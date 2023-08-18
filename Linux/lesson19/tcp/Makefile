.PHONY:all
all:server client

server:./TCPServer.cc
	g++ -o $@ $^ -std=c++11
client:./TCPClient.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f server client
