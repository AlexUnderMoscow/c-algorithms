
LINK_TARGET = class.exe
CXX = gcc -std=c99
CXXFLAGS = -g -gdwarf

OBJS =  \
	main.o \
	list.o \
	stack.o \
	dynamicarray.o \
	mergesort.o \
	bubble.o \
	selection.o \
	heapsort.o \
	quicksort.o \
	linkedlist.o \
	expressionsolver.o
REBUILDABLES = $(OBJS) $(LINK_TARGET)

all : $(LINK_TARGET)
	echo All done

$(LINK_TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.c
	$(CXX) $(CXXFLAGS) -o $@ -c $<


clean :
	rm -f $(REBUILDABLES)
	rm -f *.o
	echo clean done

#-strip-local-absolute -traditional-format -march=i386
#-f win32 -F dwarf -g
#-f win32
#coff
