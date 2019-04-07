CC = gcc
CFlags = -W -Wall
TARGET = accountSystem
OBJECTS = main.o menu.o user.o
D_OBJECTS = main_d.o menu_d.o user_d.o

all : $(TARGET)

accountSystem_debug : $(D_OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^

$(TARGET) : $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^

user_d.o : user.c
		$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

main_d.o : main.c
		$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

menu_d.o : menu.c
		$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

clean :
		rm *.o accountSystem accountSystem_debug

