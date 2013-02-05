CC = gcc
CCFLAGS = -m64 -march=core2 -Wall -std=c99 -O3 -pedantic
LD = ld
LDFLAGS =

OBJS = telxcc.o
EXEC = telxcc

all : $(EXEC)

strip : $(EXEC)
	-strip $<

.PHONY : clean
clean :
	-rm -f $(OBJS) $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) 

%.o : %.c
	$(CC) -c $(CCFLAGS) -o $@ $<

profiled :
	make CCFLAGS="$(CCFLAGS) -fprofile-generate" LDFLAGS="$(LDFLAGS) -fprofile-generate" $(EXEC)
	find . -type f -iname \*.ts -exec sh -c './telxcc -1 -c -v -p 888 < "{}" > /dev/null 2>> profile.log' \;
	find . -type f -iname \*.ts -exec sh -c './telxcc -s -v -p 888 < "{}" > /dev/null 2>> profile.log' \;
	find . -type f -iname \*.ts -exec sh -c './telxcc -1 -v -t 8192 -p 777 < "{}" > /dev/null 2>> profile.log' \;
	find . -type f -iname \*.ts -exec sh -c './telxcc < "{}" > /dev/null 2>> profile.log' \;
	make clean
	make CCFLAGS="$(CCFLAGS) -fprofile-use" LDFLAGS="$(LDFLAGS) -fprofile-use" $(EXEC)
	-rm -f $(OBJS) *.gcda *.gcno *.dyn pgopti.dpi pgopti.dpi.lock
