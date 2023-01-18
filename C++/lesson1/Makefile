cc=g++
src=test.cc
dest=mytest

$(dest):$(src)
	$(cc) -std=c++11 -o $@ $^
.PHONY:clean
clean:
	rm -f $(dest)
