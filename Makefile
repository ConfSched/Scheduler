GCC=g++ -g

all: simulated

johnson.o: johnson.cc
	$(GCC) -c johnson.cc

LinkedList.o: LinkedList.cc Node.h
	$(GCC) -c LinkedList.cc

room.o: room.cc room.h
	$(GCC) -c room.cc

session.o: session.cc session.h room.h
	$(GCC) -c session.cc

author.o: author.cc author.h session.h
	$(GCC) -c author.cc

paper.o: paper.cc paper.h
	$(GCC) -c paper.cc

sqlHelpers.o: sqlHelpers.cc sqlHelpers.h
	$(GCC) -c sqlHelpers.cc `/usr/bin/mysql_config --cflags --libs`

functions.o: functions.cc functions.h room.h author.h session.h paper.h sqlHelpers.h
	$(GCC) -c functions.cc `/usr/bin/mysql_config --cflags --libs`

simulated.o: simulated.cc sqlHelpers.h
	$(GCC) -c simulated.cc `/usr/bin/mysql_config --cflags --libs`

simulated: LinkedList.o room.o session.o author.o paper.o functions.o sqlHelpers.o simulated.o
	$(GCC) LinkedList.o room.o session.o author.o paper.o functions.o sqlHelpers.o simulated.o -o simulated `/usr/bin/mysql_config --cflags --libs`

johnson: johnson.o
	$(GCC) johnson.o -o johnson

johnson_backup: johnson_backup.o
	$(GCC) johnson_backup.o -o johnson_backup

clean:
	rm *.o *.h~ simulated johnson johnson_backup *.cc~

refresh:
	touch *.cc

mcRefresh: refresh clean

