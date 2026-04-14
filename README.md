# Calculadora Simple en C

Una calculadora básica con interfaz gráfica nativa de Windows, desarrollada en lenguaje C.

# Requisitos previos

1. Instalar un compilador de C (GCC)
Necesitarás GCC (MinGW) para compilar el programa. Tienes dos opciones:

```bash
Opción A: MSYS2 (Recomendado)
1. Descarga MSYS2 desde: https://www.msys2.org/
2. Ejecuta el instalador y sigue los pasos
3. Abre "MSYS2 UCRT64" desde el menú de inicio
4. Ejecuta: `pacman -S mingw-w64-ucrt-x86_64-gcc`
5. Agrega `C:\msys64\ucrt64\bin` a las variables de entorno de Windows

Opción B: MinGW-w64
1. Descarga desde: https://sourceforge.net/projects/mingw-w64/
2. Instala con arquitectura `x86_64`
3. Agrega `C:\mingw-w64\mingw64\bin` a las variables de entorno
```

2. Extensiones de VS Code (Opcional pero recomendado)

- **C/C++** (Microsoft) - Soporte para lenguaje C
- **C/C++ Extension Pack** (Microsoft) - Herramientas adicionales
- **Code Runner** (Jun Han) - Ejecuta código con un clic

```bash
# Cómo compilar y ejecutar
Ejecutar DESDE el Git Bash:
./calculadora_C
O SIMPLEMENTE CON "Ejecución y depuración (CTRL+Mayús+D)
```
