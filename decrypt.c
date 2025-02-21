#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "log.txt"
#define XOR_KEY 0xAA  // Clave usada en el cifrado

int main() {
    FILE *file = fopen(LOG_FILE, "rb"); // Modo binario para evitar errores
    if (!file) {
        perror("Error al abrir el archivo de log");
        return 1;
    }

    printf("Texto descifrado:\n");

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch ^ XOR_KEY);  // Aplicar XOR inverso y mostrar el carácter
    }

    printf("\n");
    fclose(file);
    return 0;
}