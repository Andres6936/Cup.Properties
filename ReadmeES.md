### Objetivo
El objetivo de esta libreria es evitar la duplicación de código con C++.

### Definición de Problema
A lo largo de mis proyectos, la lectura de archivos en modo binario y
texto simple involucra el utilizar la misma secuencia de código, 
verificación de existencia de archivos, apertura de archivos, determinación
de tamaño y lectura de archivos.

### Descargos
Esta libreria no esta diseñada para tener un rendimiento impresionante 
(aunque también es un aspecto que tengo en cuenta al implementar la libreria),
es diseñada para evitar código duplicado.

### Modo de Uso
Con la llegada de CMake 14, se añadio un script que permite obtener recursos
desde internet, teniendo esto en cuenta el usuario [TheLartians](https://github.com/TheLartians)
decidió escribir un script para CMake que actuá como un administrador de
paquetes. En mi opinión, esto marca un nuevo paso para C++ y CMake, permitiendo
trabajar con librerias que se descargan y actualizan sin intervención directa
del usuario.

### Cómo usar
Para usar esta libreria, necesitas el script escrito por [TheLartians](https://github.com/TheLartians),
nombrado [CPM.cmake](https://github.com/TheLartians/CPM.cmake) (Siglas de CMake
Package Manager). Añadelo a tu projecto, por ejemplo, bajo el directorio
`CMakeModules` y luego en tú `CMakeFiles.txt` escribe lo siguente:

```cmake
Include(CMakeModules/CPM.cmake)

CPMAddPackage(
  NAME Cup
  VERSION 2020.523
  GITHUB_REPOSITORY Andres6936/Cup
)
 
TARGET_LINK_LIBRARIES(<TARGET> PRIVATE Cup)
```

Mi propuesta para utilizar dentro de tú código la libreria es utilizar 
herencia en lugar de encapsulamiento.

```cxx
using namespace Cup;

class MyClass : private Properties::Readable
{
....
}
```

La herencia desde mi perspectiva a de ser privada, porque oculta 
los métodos heredados de la clase `Readable` a otras clases que NO se
deriven directamente de esta.

<p align="center">
    <img src="Documentation/Inheritance Good.png" alt="Good"/>
</p>

<p align="center">
    <img src="Documentation/Inheritance Bad.png" alt="Bad"/>
</p>
