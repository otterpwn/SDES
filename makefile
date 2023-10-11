CC = g++
CFLAGS = 
RM = rm -f

default: all

all: SDES

SDES: sdes.cpp
	$(CC) $(CFLAGS) sdes.cpp functions.cpp -o sdes

TEST: sdes.cpp sampleInput.in sampleOutput.out
	@$(CC) $(CFLAGS) sdes.cpp functions.cpp -o sdes
	@./sdes < sampleInput.in | tail -n1
	@cat sampleOutput.out

clean veryclean:
	$(RM) sdes
