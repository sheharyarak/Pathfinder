CC:=g++
EXE:=Pathfinder.exe
MEXE:=MapTest.exe
IEXE:=InventoryTest.exe
CEXE:=CartTest.exe
PEXE:=PathfinderTest.exe
CFLAGS:=-Wall
OBJS:= Cart.o Inventory.o Map.o Pathfinder.o Main.o
MOBJS:= Map.o MapTest.o
IOBJS:= Inventory.o InventoryTest.o
COBJS:= Cart.o CartTest.o
POBJS:= Pathfinder.o PathfinderTest.o Map.o

%.o: %.cpp
	$(CC) $(CFLAGS) $(THREADS) -MD -MP $< -c -g -o $@

$(EXE): $(OBJS)
	$(CC) $^ -o $@
$(MEXE): $(MOBJS)
	$(CC) $^ -o $@
$(IEXE): $(IOBJS)
	$(CC) $^ -o $@
$(CEXE): $(COBJS)
	$(CC) $^ -o $@
$(PEXE): $(POBJS)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJS) $(EXE)

-include $(OBJS:.o=.d)
