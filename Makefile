CC = g++
CFLAGS = -std=c++11

# Исходные файлы
SRC = main.cpp Board.cpp Fruits.cpp GameEngine.cpp Snake.cpp

# Заголовочные файлы
HEADERS = Board.h Fruits.h GameEngine.h Snake.h defines.h

# Библиотеки
LIBS = libBoard.a libFruits.a libGameEngine.a libSnake.a

# Цель по умолчанию
all: $(LIBS) game

# Создание библиотек
libBoard.a: Board.o
	ar rcs $@ $^

libFruits.a: Fruits.o
	ar rcs $@ $^

libGameEngine.a: GameEngine.o
	ar rcs $@ $^

libSnake.a: Snake.o
	ar rcs $@ $^

# Сборка основной программы
game: $(SRC) $(HEADERS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(SRC) -L. -lBoard -lFruits -lGameEngine -lSnake

# Очистка
clean:
	rm -f *.o *.a game
