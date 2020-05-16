CC:=g++

EXE:=Pathfinder.exe
MEXE:=MapTest.exe
IEXE:=InventoryTest.exe
CEXE:=CartTest.exe
PEXE:=PathfinderTest.exe

CFLAGS:=-Wall

MOBJS:=Map.o
IOBJS:=Inventory.o Strings.o
COBJS:=Cart.o
POBJS:=Pathfinder.o $(MOBJS) $(COBJS) $(IOBJS) 
OBJS:= $(POBJS) Main.o

CGI:=Pathfinder.cgi
MGI:=Map.cgi
IGI:=Inventory.cgi

CGIOBJS:=cgi_main.o UI.o $(POBJS)
MGIOBJS:=cgi_map.o UI.o
IGIOBJS:=cgi_inventory.o UI.o $(IOBJS)


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
$(PEXE): $(POBJS)
	$(CC) $^ -o $@
$(CGI): $(CGIOBJS)
	$(CC) $^ -o $@
	$(CC) $^ -o $@.exe
$(MGI): $(MGIOBJS)
	$(CC) $^ -o $@
	$(CC) $^ -o $@.exe
$(IGI): $(IGIOBJS)
	$(CC) $^ -o $@
	$(CC) $^ -o $@.exe



InitCGILin:
	mkdir /usr/lib/cgi-bin/Pathfinder

InitCGIWin:
	mkdir C:\xampp\cgi-bin\Pathfinder

WebAppWin:
	make Pathfinder.exe
	make Pathfinder.cgi
	make Map.cgi
	make Inventory.cgi
	cp Pathfinder.cgi Map.cgi Inventory.cgi C:\xampp\cgi-bin\Pathfinder
	cp Map.tsv Inventory.txt C:\xampp\cgi-bin\Pathfinder
	./Inventory.cgi.exe > Inventory.html
	./Map.cgi.exe > Map.html
	./Pathfinder.cgi.exe > Path.html

WebAppLin:
	make Pathfinder.exe
	make Pathfinder.cgi
	make Map.cgi
	make Inventory.cgi
	cp Pathfinder.cgi Map.cgi Inventory.cgi /usr/lib/cgi-bin/Pathfinder
	cp Map.tsv Inventory.txt /usr/lib/cgi-bin/Pathfinder
	./Inventory.cgi.exe > Inventory.html
	./Map.cgi.exe > Map.html
	./Pathfinder.cgi.exe > Path.html

clean:
	rm -f $(OBJS) $(POBJS) $(IOBJS) $(COBJS) $(MOBJS) $(EXE) $(MEXE) $(IEXE) $(PEXE) $(CGI) $(MGI) $(IGI) $(CGI).exe $(MGI).exe $(IGI).exe $(CGIOBJS) $(MGIOBJS) $(IGIOBJS) *.d

-include $(OBJS:.o=.d)
