
🔐 Keylogger en C para Termux

Captura de teclas con cifrado XOR y ejecución en segundo plano

Este proyecto es un keylogger básico en C diseñado para ejecutarse en Termux (Android/Linux). Captura pulsaciones de teclas en tiempo real y las almacena en un archivo cifrado con XOR para evitar detección fácil. Además, puede ejecutarse en segundo plano sin interferir con otras aplicaciones.


---

📌 Características

✅ Captura teclas sin necesidad de presionar Enter.

✅ Guarda las teclas en un archivo de log (log.txt).

✅ Cifra los datos usando XOR (0xAA) para evitar lectura directa.

✅ Corre en segundo plano usando nohup y disown.

✅ Descifrado de datos con un programa en C.

✅ Filtra caracteres no imprimibles para evitar datos corruptos.


---

🔧 Instalación y Uso

1️⃣ Clonar el repositorio

git clone https://github.com/V1nt3r4/keylogger_tool.git
cd keylogger_tool

2️⃣ Compilar el keylogger

clang keylogger.c -o keylogger

3️⃣ Ejecutar el keylogger

./keylogger

🔹 Para ejecutarlo en segundo plano:

nohup ./keylogger > /dev/null 2>&1 &
disown

🔹 Para detenerlo:

pkill keylogger

4️⃣ Ver el contenido del log (cifrado)

cat log.txt

5️⃣ Descifrar el log

clang decrypt.c -o decrypt
./decrypt


---

📜 Explicación del Código

🔹 1️⃣ Captura de teclas (get_key())

📌 Lógica:

1. Modifica la terminal para desactivar el buffer de línea y eco de caracteres.


2. Captura una tecla en tiempo real.


3. Restaura la configuración original de la terminal.




---

🔹 2️⃣ Escritura segura en el archivo (log.txt)

📌 Lógica:

1. Filtra caracteres imprimibles para evitar datos corruptos.


2. Cifra cada tecla con XOR (^ 0xAA) antes de escribirla en log.txt.


3. fflush(file); asegura que los datos se guarden inmediatamente.




---

🔹 3️⃣ Manejo de señales (CTRL+C)

📌 Lógica:

1. Intercepta CTRL+C para evitar que se cierre inesperadamente.


2. Cierra correctamente el archivo log.txt antes de salir.




---

🔹 4️⃣ Descifrado de datos (decrypt.c)

📌 Lógica:

1. Lee cada carácter del archivo log.txt.


2. Aplica XOR inverso (^ 0xAA) para recuperar las teclas originales.


3. Muestra el resultado en pantalla.




---

💻 Aplicaciones en Ciberseguridad

🔹 1️⃣ Seguridad Ofensiva (Pentesting)

Se usa para testear seguridad en sistemas Linux.

Puede demostrar fallos en la protección de terminales.

Puede probar la efectividad de antivirus y herramientas de detección.


🔹 2️⃣ Seguridad Defensiva

Ayuda a detectar comportamiento sospechoso en procesos.

Puede ser usado para analizar técnicas de malware y crear contramedidas.

Demuestra la importancia de proteger stdin en Linux.


🔹 3️⃣ Educación y Entrenamiento

Permite entender cómo funciona la captura de eventos de teclado en Linux.

Introduce el concepto de cifrado XOR en aplicaciones de seguridad.

Enseña cómo ocultar procesos en sistemas basados en Unix.



---

⚠️ Advertencia Legal

Este keylogger fue desarrollado con fines educativos y de auditoría en ciberseguridad.
El uso de este software en sistemas sin permiso es ilegal y puede tener consecuencias penales.

Úsalo bajo tu propia responsabilidad y solo en entornos controlados.


---

🎯 Mejoras Futuras

🔹 Enviar logs cifrados a un servidor remoto.
🔹 Mejor manejo de procesos y ocultación.
🔹 Soporte para capturar teclas especiales (Shift, Enter).


 