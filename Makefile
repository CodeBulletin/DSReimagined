CXX=g++
objs=main.o
dobjs=main.do
tests=Tests/Test.do
FLAGS=-std=c++23
BFLAGS=-Ofast
CFLAGS=-Ofast
CDFLAGS=-g -Wall
DFLAGS=-g -Wall
TFLAGS=-g
LIBS=-lm
OUT=main.out
TestName=test.test
DebugName=main.debug

run: build
	clear
	./build/exec/$(OUT)

build: $(objs)
	mkdir -p build/exec
	cd build/obj; $(CXX) $(FLAGS) $(BFLAGS) $^ -o $(OUT) $(LIBS); mv $(OUT) ../exec/

test: build_test
	clear
	./build/test/$(TestName)

build_test: $(tests)
	mkdir -p build/test
	cd build/obj; $(CXX) $(FLAGS) $(TFLAGS) $^ -o $(TestName) $(LIBS); mv $(TestName) ../test/

debug: build_debug
	clear
	gdb ./build/debug/$(DebugName)

build_debug: $(dobjs)
	mkdir -p build/debug
	cd build/obj; $(CXX) $(FLAGS) $(DFLAGS) $^ -o $(DebugName) $(LIBS); mv $(DebugName) ../debug/

%.o: %.cpp 
	mkdir -p build
	mkdir -p build/obj
	$(CXX) $(FLAGS) $(CFLAGS) -c $*.cpp -o build/obj/$*.o

%.do: %.cpp 
	mkdir -p build
	mkdir -p build/obj
	mkdir -p build/obj/Tests
	$(CXX) $(FLAGS) $(CDFLAGS) -c $*.cpp -o build/obj/$*.do

clean:
	rm -rf build
