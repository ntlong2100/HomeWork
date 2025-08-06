main.o: main.c
	@echo cmp main.
	gcc -c $< -o $@

staticCMP: bstructils.c main.o
	@echo -----STATIC COMP START!!!
	gcc -c $< -o stacticBstructils.o
	ar src libstrutils.a stacticBstructils.o
	gcc -o staticMain main.o libstrutils.a
	@echo -----END!!!

sharedCMP: bstructils.c main.o
	@echo -----SHARED COMP START!!!
	gcc -c -fPIC -Wall $< -o sharedBstrutils.o
	gcc -shared -o libstrutils.so sharedBstrutils.o
	gcc -o sharedMain main.o libstrutils.so
	@echo -----END!!!

all: sharedCMP staticCMP
	@echo ALL!

clean:
	@echo CLEAN!!!
	rm -f *.o *.so *a *Main 