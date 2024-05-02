CC=gcc
CFLAGS=$(shell pkg-config --cflags gtk+-3.0)
LIBS=$(shell pkg-config --libs gtk+-3.0)
TARGET=analizador
SRC=calculadora_promedio.c

all: check_gtk $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)
	@echo "Compilación completada exitosamente."

check_gtk:
	@pkg-config --exists gtk+-3.0 || { echo "GTK+ 3.0 no está instalado. Instálalo usando: sudo apt-get install libgtk-3-dev"; exit 1; }
	@echo "GTK+ 3.0 está correctamente instalado."

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
