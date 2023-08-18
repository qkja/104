.PHONY:all
all:server client

server:./udpServer.cc
	g++ -o $@ $^ -std=c++11
client:./udpClient.cc
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f server client
