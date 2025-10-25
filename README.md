# 🚗 MP-GII-ESI-UCA: Sistema de Gestión de Consola (UCAcar)

[![Universidad de Cádiz](https://img.shields.io/badge/Universidad%20de%20C%C3%A1diz-UCA-blue.svg)](https://www.uca.es/)
[![Grado](https://img.shields.io/badge/Grado-Ingenier%C3%ADa%20Inform%C3%A1tica%20(GII)-yellowgreen.svg)](#)
[![Curso Académico](https://img.shields.io/badge/Curso-2017%2F2018-red.svg)](#)
[![Asignatura](https://img.shields.io/badge/Asignatura-Metodolog%C3%ADa%20de%20la%20Programaci%C3%B3n%20(MP)-red.svg)](#)
[![Lenguaje Principal](https://img.shields.io/badge/Lenguaje-C%20(ANSI%20C)-brightgreen.svg)](#tecnolog%C3%ADas-utilizadas)
[![Estado](https://img.shields.io/badge/Estado-Archivado-lightgrey.svg)](#)

---

## 📄 Descripción del Proyecto

Este repositorio contiene el trabajo práctico desarrollado para la asignatura **Metodología de la Programación (MP)**, dentro del **Grado en Ingeniería Informática (GII)** en la **Escuela Superior de Ingeniería (ESI)** de la Universidad de Cádiz.

El proyecto, denominado **UCAcar**, es una **aplicación de consola modular** implementada íntegramente en el lenguaje C. El objetivo es simular un sistema de gestión que maneja diversas entidades a través de ficheros de texto (ficheros de datos). El sistema incluye la gestión de:

* **Usuarios**
* **Vehículos**
* **Viajes**
* **Incidencias**

El desarrollo se enfoca en demostrar la aplicación de principios de programación estructurada, modularidad, y manejo de ficheros.

---

## 🚀 Tecnologías Utilizadas

El proyecto está construido principalmente con tecnologías fundamentales para la programación de sistemas:

| Tecnología | Porcentaje | Propósito |
| :--- | :--- | :--- |
| **C** | 77.1% | Lógica de negocio, manejo de estructuras de datos y operaciones del sistema. |
| **Makefile** | 12.2% | Automatización del proceso de compilación y enlace de los módulos. |
| **C++** | 8.1% | (Posiblemente) Archivos de apoyo o pruebas. |
| **Shell** | 2.5% | Scripts de sistema o utilidades. |

---

## 📂 Estructura del Repositorio

La organización del código es modular, separando las declaraciones (`.h`) de las implementaciones (`.c`):

MP-GII-ESI-UCA/ ├── UCAcar/ # Carpeta principal (puede contener el ejecutable) ├── main.c # Función principal y control de flujo/menú. ├── Usuarios.c / Usuarios.h # Módulo de gestión de usuarios. ├── Vehiculos.c / Vehiculos.h # Módulo de gestión de vehículos. ├── Viajes.c / Viajes.h # Módulo de gestión de viajes. ├── Incidencias.c / Incidencias.h # Módulo de gestión de incidencias. ├── ficheros.c / ficheros.h # Módulo para la lectura y escritura de ficheros. ├── comun.c / comun.h # Definiciones comunes (estructuras, constantes). ├── Makefile # Script de compilación. └── *.txt # Archivos de persistencia de datos (Usuarios.txt, Viajes.txt, etc.)


---

## 🛠️ Compilación y Ejecución

Para construir y probar esta aplicación, necesitarás un entorno de desarrollo que incluya el compilador GCC y la herramienta Make.

### Requisitos

1.  **GCC** (GNU Compiler Collection).
2.  **Make** (Herramienta para ejecutar el `Makefile`).

### Pasos

1.  **Clonar el Repositorio:**
    ```bash
    git clone [https://github.com/sheratanAlde/ESI-GII-MP.git](https://github.com/sheratanAlde/ESI-GII-MP.git)
    cd ESI-GII-MP
    ```

2.  **Compilar el Proyecto:**
    Utiliza el `Makefile` para compilar todos los módulos:
    ```bash
    make
    ```

3.  **Ejecutar la Aplicación:**
    El comando exacto dependerá del nombre del ejecutable definido en el `Makefile` (comúnmente `main` o `UCAcar`):
    ```bash
    ./[nombre_del_ejecutable]
    ```

---

## 🤝 Colaboradores

Este proyecto fue desarrollado en colaboración por:

* **[sheratanAlde](https://github.com/sheratanAlde)**
* **[Bizarrista](https://github.com/Bizarrista)**
