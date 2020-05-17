# Compiler
CC:=g++

# Executable and Test files for each part of the program
# We indivisual tst files to make it easier for ourselves to debug
# It turned out to be a great decision
MEXE:=MapTest.exe
IEXE:=InventoryTest.exe
CEXE:=CartTest.exe
PEXE:=PathfinderTest.exe
EXE:=Pathfinder.exe

# Flags for the compiler
CFLAGS:=-Wall

# Objects required for each test file, first letter matches the test file
MOBJS:=Map.o
IOBJS:=Inventory.o Strings.o
COBJS:=Cart.o
POBJS:=Pathfinder.o $(MOBJS) $(COBJS) $(IOBJS) 
OBJS:= $(POBJS) Main.o

# CGI Files
CGI:=Pathfinder.cgi
MGI:=Map.cgi
IGI:=Inventory.cgi

# Objects required to make the CGI files
CGIOBJS:=cgi_main.o UI.o $(POBJS)
MGIOBJS:=cgi_map.o UI.o
IGIOBJS:=cgi_inventory.o UI.o $(IOBJS)

# % acts as a wild card.
# for every .o file there is a .cpp file of the same prefix.
# This is a quick way to make a build command for every object file
%.o: %.cpp
	$(CC) $(CFLAGS) -MD -MP $< -c -g -o $@

# Commands to make executable files
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

# This command makes a CGI file as well as a file cgi with the .exe suffix
# This allows me to see the output of the cgi file
$(CGI): $(CGIOBJS)
	$(CC) $^ -o $@
	$(CC) $^ -o $@.exe
$(MGI): $(MGIOBJS)
	$(CC) $^ -o $@
	$(CC) $^ -o $@.exe
$(IGI): $(IGIOBJS)
	$(CC) $^ -o $@
	$(CC) $^ -o $@.exe


# Makes the Pathfinder folder in the CGI bin for Linux
InitCGILin:
	mkdir /usr/lib/cgi-bin/Pathfinder

# Makes the Pathfinder folder in the CGI bin for Windows
InitCGIWin:
	mkdir C:\xampp\cgi-bin\Pathfinder

# Makes the Web Application for Windows
WebAppWin:
	# Makes the CGI files
	make Pathfinder.cgi
	make Map.cgi
	make Inventory.cgi
	# Copies the CGI files to the cgi-bin
	cp Pathfinder.cgi Map.cgi Inventory.cgi icon.png C:\xampp\cgi-bin\Pathfinder
	cp Map.tsv Inventory.txt C:\xampp\cgi-bin\Pathfinder
	# Directs output of the %.cgi.exe files to %.html for easy debugging
	./Inventory.cgi.exe > Inventory.html
	./Map.cgi.exe > Map.html
	./Pathfinder.cgi.exe > Path.html

# Makes the Web Application for Linux
WebAppLin:
	make Pathfinder.exe
	make Pathfinder.cgi
	make Map.cgi
	make Inventory.cgi
	cp Pathfinder.cgi Map.cgi Inventory.cgi icon.png /usr/lib/cgi-bin/Pathfinder
	cp Map.tsv Inventory.txt /usr/lib/cgi-bin/Pathfinder
	./Inventory.cgi.exe > Inventory.html
	./Map.cgi.exe > Map.html
	./Pathfinder.cgi.exe > Path.html

# Deletes all objects, dependancies, cgi, and executable files
clean:
	rm -f $(OBJS) $(POBJS) $(IOBJS) $(COBJS) $(MOBJS) $(EXE) $(MEXE) $(IEXE) $(PEXE) $(CGI) $(MGI) $(IGI) $(CGI).exe $(MGI).exe $(IGI).exe $(CGIOBJS) $(MGIOBJS) $(IGIOBJS) *.d

# creates a list of dependancies so of header file is changed it recompiles
-include $(OBJS:.o=.d)
