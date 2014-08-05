CC = g++
LD = g++

CFLAGS = -c -pedantic -std=c++11 -Wall -g
LFLAGS = -pedantic -Wall

OBJS = main.o Model.o CLI_controller.o Order.o Order_reader.o Hold.o jsoncpp.o
OBJS += JSON_util.o Terr.o Piece.o Sea.o Landlock.o Coastal.o
PROG = waegyo


default: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $(PROG)

main.o: main.cpp CLI_controller.h
	$(CC) $(CFLAGS) $<

Model.o: Model.cpp Model.h JSON_util.h json/json/json.h
	$(CC) $(CFLAGS) $<

CLI_controller.o: CLI_controller.cpp CLI_controller.h Model.h Order.h Order_reader.h
	$(CC) $(CFLAGS) $<

Order.o: Order.cpp Order.h
	$(CC) $(CFLAGS) $<

Hold.o: Hold.cpp Hold.h Order.h Model.h Terr.h Piece.h
	$(CC) $(CFLAGS) $<

Order_reader.o: Order_reader.cpp Order_reader.h Order.h Hold.h
	$(CC) $(CFLAGS) $<

Terr.o: Terr.cpp Terr.h JSON_util.h json/json/json.h Piece.h
	$(CC) $(CFLAGS) $<

Sea.o: Sea.cpp Sea.h Terr.h Piece.h
	$(CC) $(CFLAGS) $<

Landlock.o: Landlock.cpp Landlock.h Terr.h Piece.h
	$(CC) $(CFLAGS) $<

Coastal.o: Coastal.cpp Coastal.h Terr.h Piece.h json/json/json.h JSON_util.h Model.h
	$(CC) $(CFLAGS) $<

# # TODO delete
# Reg_terr.o: Reg_terr.cpp Reg_terr.h Terr.h
# 	$(CC) $(CFLAGS) $<

# # TODO delete
# Two_coast_terr.o: Two_coast_terr.cpp Two_coast_terr.h Terr.h
# 	$(CC) $(CFLAGS) $<

Piece.o: Piece.cpp Piece.h
	$(CC) $(CFLAGS) $<

jsoncpp.o: json/jsoncpp.cpp json/json/json.h
	$(CC) $(CFLAGS) -w $<

JSON_util.o: JSON_util.cpp JSON_util.h Terr.h Sea.h Landlock.h Coastal.h
	$(CC) $(CFLAGS) -w $<


.PHONY: clean
clean:
	rm -f *.o *.exe $(PROG)
