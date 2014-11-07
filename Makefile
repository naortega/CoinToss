CXX=gcc
CXXFLAGS= -O3 -Wall -std=gnu99

MKDIR=mkdir -p
RM=rm -rf

LBITS := $(shell getconf LONG_BIT)

ifeq ($(LBITS),32)
all: compile32bit
else
all: compile64bit
endif

compile32bit:
	$(MKDIR) bin/lin32/
	$(CXX) $(CXXFLAGS) -m32 -o bin/lin32/cointoss src/main.c

compile64bit:
	$(MKDIR) bin/lin64/
	$(CXX) $(CXXFLAGS) -m64 -o bin/lin64/cointoss src/main.c

clean:
	$(RM) bin
