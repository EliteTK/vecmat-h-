CC = gcc

CFLAGS = -c -O2 -Wall -Werror -fPIC -I $(INCLL)
LDFLAGS = -lm

BASENAME = vecmat
SOOUT = lib$(BASENAME).so

SOVER = 
SONAME = $(SOOUT)$(SOVER)

DESTDIR = /usr
DESTINCL = $(DESTDIR)/include
DESTLIB = $(DESTDIR)/lib

BUILDDIR = .
INCL = $(BUILDDIR)/include
INCLL = $(INCL)/$(BASENAME)
SRC = $(BUILDDIR)/src
BUILD = $(BUILDDIR)/build
LIB = $(BUILDDIR)/lib

SOURCES = vec.c
INCLUDES = $(addprefix vecmat/, $(SOURCES:.c=.h)) $(BASENAME).h
OBJECTS = $(addprefix $(BUILD)/, $(SOURCES:.c=.o))

make : $(LIB)/$(SONAME)
	

$(LIB)/$(SONAME) : $(OBJECTS)
	$(CC) $(LDFLAGS) -shared -o $@ $^

$(BUILD)/%.o : $(SRC)/%.c $(INCLL)/%.h 
	$(CC) $(CFLAGS) -o $@ $<

install : $(DESTLIB)/$(SONAME) $(addprefix $(DESTINCL)/, $(INCLUDES))
	

$(DESTLIB)/$(SONAME) : $(LIB)/$(SONAME)
	cp $< $@

$(DESTINCL)/%.h : $(INCL)/%.h $(DESTINCL)/$(BASENAME)
	cp $< $@

$(DESTINCL)/$(BASENAME) :
	mkdir -p $@

uninstall :
	rm -f $(DESTLIB)/$(SONAME) $(DESTINCL)/$(BASENAME).h $(DESTINCL)/$(BASENAME)/*
	rm -fd $(DESTINCL)/$(BASENAME)/

clean :
	rm -f $(BUILD)/* $(LIB)/*
	rm -fd $(BUILD) $(LIB)

git-prepare :
	mkdir -p $(LIB) $(BUILD)
