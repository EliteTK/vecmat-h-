CC = gcc

CFLAGS = -c -O2 -Wall -Werror -fPIC -I $(INCLL)

SOOUT = libvecmat.so

SOVER = 
SONAME = $(SOOUT)$(SOVER)

DESTDIR = /usr
DESTINCL = $(DESTDIR)/include
DESTLIB = $(DESTDIR)/lib

BUILDDIR = .
INCL = $(BUILDDIR)/include
INCLL = $(INCL)/vecmat
SRC = $(BUILDDIR)/src
BUILD = $(BUILDDIR)/build
LIB = $(BUILDDIR)/lib

SOURCES = vec.c
OBJECTS = $(addprefix $(BUILD), $(SOURCES:.c=.o))

build : $(LIB)/$(SONAME)
	

$(LIB)/$(SONAME) : $(OBJECTS)
	mkdir -p $(LIB)
	$(CC) -shared -o $@ $^

$(OBJECTS)/%.o : %.c %.h
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $@ $<

install : $(DESTDIR)/$(SONAME)
	

$(INSLIB)/$(SONAME) : $(LIB)/$(SONAME)
	cp $(LIB)/$(SONAME) $(INSLIB)/$(SONAME)
	cp -r $(INCL)/* $(INSINCL)/

uninstall :
	rm -f $(INSLIB)/$(SONAME) $(INSINCL)/vecmat.h $(INSINCL)/vecmat/*
	rm -fd $(INSINCL)/vecmat/

clean :
	rm -f $(BUILD)/* $(LIB)/*
	rm -fd $(BUILD) $(LIB)
