
LINK_TARGET = class.exe
CXX = gcc -std=c99
CXXFLAGS = -g -gdwarf


#-f win32 -F dwarf -g
#-f win32
#coff

OBJS =  \
	main.o \
	object1.o object2.o list.o
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
