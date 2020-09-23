.PHONY: clean

CC := cc 
BUILDDIR := ../build
SRCDIR := ../src
ROOTTARGET := ../bin
TARGET := $(ROOTTARGET)/demos_bin
SRCOBJ := $(BUILDDIR)/dimensionsProduct.o $(BUILDDIR)/errorsHandler.o \
	$(BUILDDIR)/aimt.o

# compile the demo apps
all: demo_ind2sub.out demo_sub2ind.out

demo_ind2sub.out: $(TARGET) demo_ind2sub.o
	$(CC) -o $(TARGET)/demo_ind2sub.out $(BUILDDIR)/demo_ind2sub.o $(SRCOBJ) 

demo_sub2ind.out: $(TARGET) demo_sub2ind.o
	$(CC) -o $(TARGET)/demo_sub2ind.out $(BUILDDIR)/demo_sub2ind.o $(SRCOBJ) 


# build the app objects
demo_ind2sub.o: $(BUILDDIR) aimt.o
	$(CC) -c -o $(BUILDDIR)/demo_ind2sub.o demo_ind2sub.c

demo_sub2ind.o: $(BUILDDIR) aimt.o
	$(CC) -c -o $(BUILDDIR)/demo_sub2ind.o demo_sub2ind.c


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

# remove the binary files
clean:
	rm -rf $(ROOTTARGET)
	rm -rf $(BUILDDIR)
