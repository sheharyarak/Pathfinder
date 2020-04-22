CC:=g++
EXE:=Pathfinder.exe
CFLAGS:=-Wall
OBJS:= Cart.o Inventory.o Map.o Pathfinder.o Main.o
OBJS:= Cart.o Inventory.o Map.o Pathfinder.o MapTest.o
OBJS:= Cart.o Inventory.o Map.o Pathfinder.o InventoryTest.o
OBJS:= Cart.o Inventory.o Map.o Pathfinder.o CartTest.o
OBJS:= Cart.o Inventory.o Map.o Pathfinder.o PathfinderTest.o

%.o: %.cpp
	$(CC) $(CFLAGS) $(THREADS) -MD -MP $< -c -o $@

$(EXE): $(OBJS)
	$(CC) $^ $(THREADS) $(MAGICK) -o $@

clean:
	rm -f $(OBJS) $(EXE)

-include $(OBJS:.o=.d)
