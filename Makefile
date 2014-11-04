CXX=gcc
CXXFLAGS= -O3 -Wall -std=gnu99

INCLUDES=
LIBS=

MV=mv
MKDIR=mkdir -p
RM=rm -rf

SRC_FILES := $(wildcard src/*.c)
OBJ_FILES := $(addprefix obj/, $(notdir $(SRC_FILES:.c=.o)))

all: $(OBJ_FILES)
	$(MKDIR) bin
	$(CXX) $(CXXFLAGS) $(LIBS) -o bin/cointoss obj/*.o

obj/%.o: src/%.c
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) obj/*.o

cleanall: clean
	$(RM) bin
