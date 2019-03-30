CC=/opt/gcc6/bin/g++
CFLAGS=-Wall -Wextra -std=c++14 -g

SOURCES =\
	src/test_driver.cpp\
	src/ValueTraversableQueue.cpp

.PHONY: all
all: build/test_driver

build/test_driver: $(SOURCES) | build
	$(CC) $(CFLAGS) src/test_driver.cpp -o build/test_driver

build:
	@mkdir -p $@

.PHONY: documentation
documentation: $(SOURCES)
	doxygen

.PHONY: test
test: build/test_driver
	LD_LIBRARY_PATH=/opt/gcc6/lib64 ./build/test_driver

.PHONY: clean
clean:
	-rm -rf build
	-rm -rf docs

.PHONY: submit
submit:
	make clean
	~schwesin/bin/submit.bash csc237
