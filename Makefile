###############################################################################
# Water-it makefile
# Automated flower watering
# @author: Tom Svoboda
###############################################################################

# Tools settings
CXX=g++
CXXFLAGS=-Wextra -Wall -pedantic
LDLIBS=#-l/usr/include/mysql++ -lmysqlpp -lmysqlclient

MKDIR=mkdir -p
RM=rm -rf

# Compile settings
SRCDIR=src
BUILDDIR=build
TARGETDIR=bin

APPNAME=water-it

###############################################################################
# OBJ files

OBJECTFILES=$(BUILDDIR)/gpio/GpioBase.o\
$(BUILDDIR)/gpio/Input.o\
$(BUILDDIR)/gpio/Output.o\
$(BUILDDIR)/control/SimpleMotor.o\
$(BUILDDIR)/log/FileLogger.o\
$(BUILDDIR)/scheduling/Schedule.o\
$(BUILDDIR)/scheduling/StaticScheduler.o\


###############################################################################
# Main rules
###############################################################################

default: all
.PHONY: all remake

remake: clean all
all: $(APPNAME)

# General rule
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) ${CXXFLAGS} -c -o $@ $<

.PHONY: $(APPNAME)
$(APPNAME)_target: $(BUILDDIR)/main.o $(OBJECTFILES)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGETDIR)/$(APPNAME) $(LDLIBS)

$(APPNAME): directories $(APPNAME)_target

.PHONY: debug

debug: $(APPNAME)
	gdb --tui ./$(TARGETDIR)/$(APPNAME)

###############################################################################
# Helpers
###############################################################################
.PHONY: clean

clean:
	@$(RM) $(BUILDDIR) $(TARGETDIR)

directories:
	@$(MKDIR) $(BUILDDIR)
	@$(MKDIR) $(TARGETDIR)
	@$(MKDIR) $(BUILDDIR)/gpio
	@$(MKDIR) $(BUILDDIR)/control
	@$(MKDIR) $(BUILDDIR)/log
	@$(MKDIR) $(BUILDDIR)/scheduling
