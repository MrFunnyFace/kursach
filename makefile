
#COMPILE
CC = g++
#PROJECT NAME
TARGET = KURSACH
#sfml libers
SFMLL = /home/anton/Libraries/SFML-2.6.0/lib
SFMLI = /home/anton/Libraries/SFML-2.6.0/include 
SFMLLIBS = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
CFLAGS= -L $(SFMLL) $(SFMLLIBS)
#lib obj and sourc files
SRC_PREF = ./src/
OBJ_PREF = ./obj/
UI_PREF = ./UI/
NO_RE = ./notrebute/

SRC = $(wildcard $(SRC_PREF)*.cpp) 
UI = $(wildcard $(UI_PREF)*.cpp)
OBJ = $(patsubst $(SRC_PREF)%.cpp, $(OBJ_PREF)%.o, $(SRC)) $(patsubst $(UI_PREF)%.cpp, $(OBJ_PREF)%.o, $(UI)) 

do:
	$(OBJ)


#OPTIONS COMPILE
$(TARGET): $(OBJ)
	$(CC) -g $(OBJ) -o $(TARGET) $(CFLAGS)

$(OBJ_PREF)%.o: $(SRC_PREF)%.cpp
	$(CC) -g -c $< -o $@ -I $(SFMLI)

$(OBJ_PREF)%.o : $(UI_PREF)%.cpp
	$(CC) -g -c $< -o $@ -I $(SFMLI)
#clean
clean :
	rm $(OBJ_PREF)*.o $(TARGET) 

run: $(TARGET)
	export LD_LIBRARY_PATH=$(SFMLL) && ./$(TARGET)

debug: $(TARGET)
	export LD_LIBRARY_PATH=$(SFMLL) && gdb $(TARGET)

	
