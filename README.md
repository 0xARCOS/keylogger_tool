<div align="center">
    <img src="https://github.com/V1nt3r4/keylogger_tool/blob/main/laptop-with-glowing-screen-table-dark-top-view-copy-space.jpg" alt="Banner oscuro" width="800"/>
    <br><br>
    <a href='https://profile.intra.42.fr/users/aarcos' target="_blank">
        <img alt='42 Madrid' src='https://img.shields.io/badge/42-Madrid-black?style=flat&logo=42&logoColor=white'/>
    </a>
    <img src="https://img.shields.io/badge/estado-activo-success?color=%2312bab9&style=flat" />
    <img src="https://api.visitorbadge.io/api/visitors?user=0xARCOS&repo=keylogger_tool&label=visitas&countColor=%2385e3ff&style=flat&labelStyle=none"/>
</div>

---

# keylogger_tool

> Keylogger básico en C para Termux/Linux, con cifrado XOR y ejecución en segundo plano. Útil como herramienta educativa para entender I/O, cifrado y multitarea.

---

## 📌 Características

- ✅ Captura teclas en tiempo real (sin necesidad de Enter)
- ✅ Guarda teclas en un archivo `log.txt`
- ✅ Cifrado XOR (clave 0xAA)
- ✅ Corre en segundo plano con `nohup` y `disown`
- ✅ Descifrador en C incluido
- ✅ Filtrado de caracteres no imprimibles

---

## 📁 Estructura del Proyecto

```plaintext
keylogger_tool/
├── keylogger.c     # Captura y cifra las teclas
├── decrypt.c       # Descifra el archivo `log.txt`
├── README.md
└── log.txt         # Log cifrado de teclas
```

---

## 🔧 Instalación y Uso

### 1️⃣ Clonar el repositorio

```bash
git clone https://github.com/V1nt3r4/keylogger_tool.git
cd keylogger_tool
```

### 2️⃣ Compilar el keylogger

```bash
clang keylogger.c -o keylogger
```

### 3️⃣ Ejecutar el keylogger

```bash
./keylogger
```

🔹 En segundo plano:

```bash
nohup ./keylogger > /dev/null 2>&1 &
disown
```

🔹 Para detenerlo:

```bash
pkill keylogger
```

---

## 🔓 Descifrar el log

```bash
clang decrypt.c -o decrypt
./decrypt log.txt
```

Esto imprimirá el texto en plano de las teclas registradas.

---

## ⚠️ Aviso Legal

Este proyecto está diseñado con **fines educativos**.  
No debe usarse para vulnerar la privacidad o derechos de terceros.  
**Cualquier uso indebido es responsabilidad exclusiva del usuario.**

---

## 🧑‍💻 Autor

**Ariel (0xARCOS)**  
📍 Campus 42 Madrid  
🔗 [GitHub](https://github.com/0xARCOS)

---

## 📜 Licencia

Uso académico y personal permitido bajo principios éticos.  
Respeta la privacidad y hackea con responsabilidad ⚖️💻

---
