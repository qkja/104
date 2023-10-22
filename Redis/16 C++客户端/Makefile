.PHONY:all
all:hello genenic string list set hash zset
zset:zset.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib64/libredis++.a -pthread -lhiredis
hash:hash.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib64/libredis++.a -pthread -lhiredis
set:set.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib64/libredis++.a -pthread -lhiredis

list:list.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib64/libredis++.a -pthread -lhiredis

genenic:genenic.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib64/libredis++.a -pthread -lhiredis

hello:hello.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib64/libredis++.a -pthread -lhiredis

string:string.cc
	g++ -std=c++17 -o $@ $^ /usr/local/lib64/libredis++.a -pthread -lhiredis

.PHONY:clean
clean:
	rm -f hello genenic string list set hash zset