#
# A simple makefile for managing build of project composed of C source files.
#
# Ramesh Viswanathan
#

CC = gcc

# The CFLAGS variable sets compile flags for gcc:
#  -g          compile with debug information
#  -Wall       give all diagnostic warnings
#  -pedantic   require compliance with ANSI standard
#  -O0         do not optimize generated code
#  -std=gnu99  use the Gnu C99 standard language definition
#  -m32        emit code for IA32 architecture
CFLAGS = -g -Wall -pedantic -O0 -std=gnu99  -I../../include


# The LDFLAGS variable sets flags for linker
#  -lm    link in libm (math library)
#  -m32	  link with IA32 libraries
LDFLAGS = -lm 

# In this section, you list the files that are part of the project.
# If you add/change names of header/source files, here is where you
# edit the Makefile.
HEADERS =../../include/DLinkedList.h 
 
TARGET_PATH = ./../../../build/linux/out

SOURCES = ../../src/DLinkedList.c \
          ../../src/DLinkedListTest.c

OBJECTS = $(SOURCES:.c=.o)
TARGET = $(TARGET_PATH)/DLinkedListTest


# The first target defined in the makefile is the one
# used when make is invoked with no argument. Given the definitions
# above, this Makefile file will build the one named TARGET and
# assume that it depends on all the named OBJECTS files.

$(TARGET) : $(OBJECTS) Makefile.dependencies
	mkdir -p $(TARGET_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

# In make's default rules, a .o automatically depends on its .c file
# (so editing the .c will cause recompilation into its .o file).
# The line below creates additional dependencies, most notably that it
# will cause the .c to reocmpiled if any included .h file changes.

Makefile.dependencies:: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -MM $(SOURCES) > Makefile.dependencies

-include Makefile.dependencies

# Phony means not a "real" target, it doesn't build anything
# The phony target "clean" that is used to remove all compiled object files.

.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core Makefile.dependencies

