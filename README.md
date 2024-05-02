# Calculadora de Promedio

Este proyecto incluye dos versiones de un programa que calcula sumas y promedios de números almacenados en un archivo de texto: una versión con interfaz gráfica y otra sin interfaz gráfica.

## Estructura del Proyecto

El proyecto está organizado en dos carpetas principales:

- `TallerSOPromedio`: Contiene el programa sin interfaz gráfica.
- `raíz`: La carpeta raíz del proyecto contiene el programa con interfaz gráfica usando GTK+.

## Requisitos

- GCC para la compilación.
- GTK+ 3 para la versión con interfaz gráfica (solo si deseas ejecutar la versión con GUI).

### Instalación de GTK+ 3

Para instalar GTK+ 3 en sistemas basados en Debian (como Ubuntu):

```bash
sudo apt-get install libgtk-3-dev
```

## Compilación y Ejecución

### Versión con Interfaz Gráfica

1. **Navega a la carpeta raíz del proyecto.**
2. **Compila el programa:**

```bash
   make all
```

 3. **Ejecuta el programa.**
 ```bash
 make run
 ```

 Se desplegara una pantalla la cual cuenta con un boton para seleccionar algun archivo txt para que contenga datos numerios para que despues este calcule sus colubnas y sus promedios


### Versión sin Interfaz Gráfica

1. **Navega a la carpeta `TallerSOPromedio`.**
   Abre una terminal y utiliza el comando `cd` para cambiar al directorio donde está almacenado el programa sin interfaz gráfica. Asegúrate de estar en el directorio correcto antes de proceder con la compilación.

```bash
   cd TallerSOPromedio
```

2. **Compila el programa:**

```bash
   make all
```

 3. **Ejecuta el programa.**
 ```bash
 make run
 ```

### Ejecutar la Versión sin Interfaz Gráfica

Después de compilar el programa como se describió anteriormente, puedes ejecutarlo proporcionando la ruta al archivo de texto que contiene los datos a analizar. Sigue estos pasos para ejecutar el programa:

1. **Asegúrate de estar en la carpeta `TallerSOPromedio`.** Si no estás seguro de dónde te encuentras, puedes usar el comando `pwd` para verificar tu ubicación actual y `cd` para moverte al directorio correcto si es necesario.

2. **Ejecuta el programa:**
   El programa `calculadora_promedio` necesita la ruta de un archivo de texto como argumento. Este archivo debe contener los datos numéricos distribuidos en columnas, como se especifica en la documentación. Utiliza el siguiente comando, reemplazando `ruta/a/tu/archivo.txt` con la ruta real al archivo de datos que deseas analizar:

```bash
   ./calculadora_promedio ruta/a/tu/archivo.txt
```
