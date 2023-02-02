CC=g++
SRC=mytest.cc
DEST=test

$(DEST):$(SRC)
	$(CC) -std=c++11 -o $@ $^

.PHONY:clean
clean:
	rm -f $(DEST)