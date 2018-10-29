SRCEXTS	 := .c .cpp

CPPFLAGS := 
CFLAGS	 := 
CFLAGS	 += 
CXXFLAGS := 
CXXFLAGS += 
LDFLAGS	 := 
LDFLAGS	 += 

# The C program compiler. Uncomment it to specify yours explicitly. 
#CC		= gcc 

# The C++ program compiler. Uncomment it to specify yours explicitly. 
#CXX	  = g++ 

# Uncomment the 2 lines to compile C programs as C++ ones. 
#CC		= $(CXX) 
#CFLAGS  = $(CXXFLAGS) 

# The command used to delete file. 
RM 		= rm -f 

.PHONY : clean

%.o : %.c 
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< 

%.o : %.C 
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

%.o : %.cc 
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

%.o : %.cpp
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

%.o : %.CPP 
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< 

%.out : %.o
ifeq ($(strip $(SRCEXTS)), .c)  # C file 
	$(CC) -o $*.out $*.o $(LDFLAGS) 
else									 # C++ file 
	$(CXX) -o $*.out $*.o $(LDFLAGS) 
endif 
	./$*.out

clean : 
	$(RM) *.o *.out
