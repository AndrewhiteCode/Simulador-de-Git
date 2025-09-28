# UGit - Simulador de Git en C

UGit es una implementación educativa y simplificada de algunas funcionalidades básicas de **Git**, desarrollada en lenguaje **C** siguiendo un enfoque de **programación estructurada**.  
El objetivo es comprender cómo funcionan conceptos como el área de staging, commits, logs y checkout a nivel de archivos.

---

## Funcionalidades implementadas

- `ugit init` → Inicializa el repositorio creando la carpeta `ugit/`.
- `ugit add` → Permite seleccionar archivos para el área de **staging** (`ugit/index.txt`).
- `ugit commit` → Guarda los archivos del staging en un nuevo **commit** dentro de `ugit/commitN/`.
- `ugit log` → Muestra el historial de commits registrados en `ugit/commits.log`.
- `ugit checkout <num_commit>` → Restaura los archivos de un commit específico.
- `ugit version` → Lista el contenido de la carpeta `ugit/`.

---

## Requisitos

- Compilador **GCC** (MinGW recomendado en Windows).
- Sistema operativo: **Windows** (usa `dir` y `mkdir` de Windows en las llamadas a `system`).

---
## Documentacion

La Documentacion se generara en base al archivo Doxyfile , Descargue e instale Doxygen para poder verlo en Html (https://www.doxygen.nl/)

---

## Compilación

En la raíz del proyecto, ejecutar:

```bash
gcc ugit.c ugit_parsing.c ugit_init.c ugit_add.c ugit_commit.c ugit_version.c ugit_log.c ugit_checkout.c -o ugit

