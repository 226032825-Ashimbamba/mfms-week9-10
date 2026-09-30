CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic
OBJS=main.o employees.o budget.o utilities.o reports.o suppliers.o assets.o

mfms: $(OBJS)
	$(CC) $(OBJS) -o mfms

main.o: main.c main.h employees.h budget.h reports.h utilities.h
employees.o: employees.c employees.h utilities.h mfms.h
budget.o: budget.c budget.h utilities.h mfms.h
utilities.o: utilities.c utilities.h
reports.o: reports.c reports.h employees.h budget.h
suppliers.o: suppliers.c suppliers.h utilities.h mfms.h
assets.o: assets.c assets.h utilities.h mfms.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) mfms
