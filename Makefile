CC = g++
LD = g++

CFLAGS = -c -pedantic -std=c++11 -Wall
LFLAGS = -pedantic -Wall

OBJS = main.o Model.o CLI_controller.o Order.o Order_reader.o Hold.o
PROG = waegyo


default: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $(PROG)

main.o: main.cpp CLI_controller.h
	$(CC) $(CFLAGS) $<

Model.o: Model.cpp Model.h
	$(CC) $(CFLAGS) $<

CLI_controller.o: CLI_controller.cpp CLI_controller.h Model.h Order.h Order_reader.h
	$(CC) $(CFLAGS) $<

Order.o: Order.cpp Order.h
	$(CC) $(CFLAGS) $<

Hold.o: Hold.cpp Hold.h Order.h Model.h Terr.h Piece.h
	$(CC) $(CFLAGS) $<

Order_reader.o: Order_reader.cpp Order_reader.h Order.h Hold.h
	$(CC) $(CFLAGS) $<

Terr.o: Terr.cpp Terr.h
	$(CC) $(CFLAGS) $<

Piece.o: Piece.cpp Piece.h
	$(CC) $(CFLAGS) $<


.PHONY: clean
clean:
	rm -f *.o *.exe $(PROG)
