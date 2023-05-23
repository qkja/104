.PHONY:all
all:write read

write:write.cc contacts.pb.cc
	g++ -std=c++11 -o $@ $^ -lprotobuf
read:read.cc contacts.pb.cc
	g++ -std=c++11 -o $@ $^ -lprotobuf

.PHONY:clean
clean:
	rm -f read write