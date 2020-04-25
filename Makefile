CC:=g++
EXE:=Pathfinder.exe
MEXE:=MapTest.exe
IEXE:=InventoryTest.exe
CEXE:=CartTest.exe
PEXE:=PathFinderTest.exe
CFLAGS:=-Wall
OBJS:= Cart.o Inventory.o Map.o Pathfinder.o Main.o
MOBJS:= Map.o MapTest.o
IOBJS:= Inventory.o InventoryTest.o
COBJS:= Cart.o CartTest.o
POBJS:= Pathfinder.o PathfinderTest.o

%.o: %.cpp
	$(CC) $(CFLAGS) $(THREADS) -MD -MP $< -c -o $@

$(EXE): $(OBJS)
	$(CC) $^ $(THREADS) $(MAGICK) -o $@
$(MEXE): $(MOBJS)
	$(CC) $^ $(THREADS) $(MAGICK) -o $@
$(IEXE): $(IOBJS)
	$(CC) $^ $(THREADS) $(MAGICK) -o $@
$(CEXE): $(COBJS)
	$(CC) $^ $(THREADS) $(MAGICK) -o $@
$(PEXE): $(POBJS)
	$(CC) $^ $(THREADS) $(MAGICK) -o $@

clean:
	rm -f $(OBJS) $(EXE)

-include $(OBJS:.o=.d)
