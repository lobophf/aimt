.PHONY: clean

CC := g++
BUILDDIR := ../build
SRCDIR := ../src
ROOTTARGET := ../bin
TESTFLAGS := -lgtest -lgtest_main -lgmock -pthread
TARGET := $(ROOTTARGET)/tests_bin
SRCOBJ := $(BUILDDIR)/dimensionsProduct.o $(BUILDDIR)/errorsHandler.o \
	$(BUILDDIR)/aimt.o

# compile the test 
all: test.out

test.out: $(TARGET) test.o
	$(CC) -std=c++11 -o$(TARGET)/test.out $(BUILDDIR)/test.o $(SRCOBJ) $(TESTFLAGS) 

# build the test 
test.o: $(BUILDDIR) aimt.o
	$(CC) -c -o $(BUILDDIR)/test.o test.cpp

# build the source objects
aimt.o: $(BUILDDIR) errorsHandler.o dimensionsProduct.o
	$(CC) -c -o $(BUILDDIR)/aimt.o $(SRCDIR)/aimt.c

dimensionsProduct.o:
	$(CC) -c -o $(BUILDDIR)/dimensionsProduct.o $(SRCDIR)/dimensionsProduct.c

errorsHandler.o: dimensionsProduct.o
	$(CC) -c -o $(BUILDDIR)/errorsHandler.o $(SRCDIR)/errorsHandler.c

# create the folders
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET):
	mkdir -p $(TARGET)

run:
	../bin/tests_bin/test.out
# remove the binary files
clean:
	rm -rf $(ROOTTARGET)
	rm -rf $(BUILDDIR)
