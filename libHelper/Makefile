# Header files
INCDIR = include

# Source files
SRCDIR = src

# Output files 
OUTDIR = build

# Object files
OBJDIR = build/intermediate

# Compiler 
CXX = g++

# Compile options
CFLAGS = -c -fdiagnostics-color=always -std=c++11 -Wall -I$(INCDIR)

# Linking options
LDFLAGS =

# Archiver
AR = ar

# Archiving options
ARFLAGS = ru

# Output library directory
OUTLIBDIR = lib

# Executables 
TARGET = libHelper.a

#-- Do not edit below this line, except change .c to .cpp, if C++ is being used instead of C -- 

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS := $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(patsubst %.cpp, %.o, $(SOURCES)))

all: $(OUTDIR)/$(TARGET) 

$(OUTDIR)/$(TARGET): $(OBJECTS)
	@echo "Building" $(TARGET) "..."
	$(BLDCMD)

#BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS)
BLDCMD = @$(AR) $(ARFLAGS) $(OUTLIBDIR)/$(TARGET) $(OBJECTS)

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCLUDES)
	-@mkdir -p $(OBJDIR)	
	@echo "Compiling" $< "..."  
	$(CXX) $(CFLAGS) -c $< -o $@ 

.PHONY: clean

clean: 
	@echo Cleaning $(TARGET) "..."
	-@rm -f $(OUTDIR)/$(TARGET)
	-@rm -f $(OUTLIBDIR)/$(TARGET)
	-@rm -f $(OBJDIR)/*.o
	-@rm -rf $(OBJDIR)
	-@rm -f *.bin


