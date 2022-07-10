CC      = g++
CFLAGS  = -Wall -Wextra -Wcast-qual -Wshadow -DNDEBUG -ansi -pedantic -std=c++11 -O3 -flto
LDFLAGS = -lpthread
OBJS    = bbinit.o board.o common.o eval.o hash.o search.o moveorder.o syzygy/tbprobe.o
EXE     = Engine

ifeq ($(USE_STATIC), true)
	LDFLAGS += -static -static-libgcc -static-libstdc++
endif

ifneq ($(NOPOPCNT), true)
	CFLAGS += -msse3 -mpopcnt
endif

ifeq ($(BMI2), true)
	CFLAGS += -march=haswell
endif

all: uci

uci: $(OBJS) uci.o
	$(CC) -O3 -flto -o $(EXE)$(EXT) $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) -x c++ $< -o $@

clean:
	rm -f *.o syzygy/*.o $(EXE)$(EXT).exe $(EXE)$(EXT)
