CC:=g++

EXE:=Pathfinder.exe
MEXE:=MapTest.exe
IEXE:=InventoryTest.exe
CEXE:=CartTest.exe
PEXE:=PathfinderTest.exe

CFLAGS:=-Wall

OBJS:=Cart.o Inventory.o Map.o Pathfinder.o Main.o Strings.o
MOBJS:=Map.o MapTest.o
IOBJS:=Inventory.o InventoryTest.o Strings.o
COBJS:=Cart.o CartTest.o
POBJS:=Pathfinder.o PathfinderTest.o Map.o Strings.o

CGI:=Pathfinder.cgi
MGI:=Map.cgi
IGI:=Inventory.cgi

CGIOBJS:=Cart.o Inventory.o Map.o Pathfinder.o cgi_main.o Strings.o UI.o
MGIOBJS:=cgi_map.o UI.o
IGIOBJS:=Inventory.o cgi_inventory.o Strings.o UI.o


%.o: %.cpp
	$(CC) $(CFLAGS) -MD -MP $< -c -g -o $@

$(EXE): $(OBJS)
	$(CC) $^ -o $@
$(MEXE): $(MOBJS)
	$(CC) $^ -o $@
$(IEXE): $(IOBJS)
	$(CC) $^ -o $@
$(CEXE): $(COBJS)
	$(CC) $^ -o $@
$(PEXE): $(OBJS)
	$(CC) $^ -o $@
$(CGI): $(CGIOBJS)
	$(CC) $^ -o $@
$(MGI): $(MGIOBJS)
	$(CC) $^ -o $@
$(IGI): $(IGIOBJS)
	$(CC) $^ -o $@


clean:
	rm -f $(OBJS) $(EXE)

-include $(OBJS:.o=.d)
