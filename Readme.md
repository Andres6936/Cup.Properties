### Objective
The objective of this library is to avoid code duplication with C++.

### Problem Definition
Throughout my projects, reading files in binary mode and
Simple text involves using the same code sequence, 
file existence check, file opening, determination
of file size and readability.

### Downloads
This library is not designed for impressive performance 
(although this is also an aspect that I take into account 
when implementing the library), is designed to avoid duplicate code.

### How to Use
With the arrival of CMake 14, a script was added that allows you to get
from the internet, taking this into account the user [TheLartians](https://github.com/TheLartians)
decided to write a script for CMake that acts as a
packages. In my opinion, this marks a new step for C++ and CMake, allowing
work with libraries that are downloaded and updated without direct intervention
of the user.

### How to use
To use this library, you need the script written by [TheLartians](https://github.com/TheLartians),
named [CPM.cmake](https://github.com/TheLartians/CPM.cmake) (acronym for CMake
Package Manager). Add it to your project, for example, under the
`CMakeModules` and then in your `CMakeFiles.txt` write the following:

```cmake
Include(CMakeModules/CPM.cmake)

CPMAddPackage(
  NAME Cup.Properties
  VERSION 2020.523
  GITHUB_REPOSITORY Andres6936/Cup.Properties
)
 
TARGET_LINK_LIBRARIES(<TARGET> PRIVATE Cup.Properties)
```

My proposal for using the library within your code is to use 
inheritance instead of encapsulation.

```cxx
using namespace Cup;

class MyClass : private Properties::Readable
{
....
}
```

The inheritance from my perspective has to be private, because it hides 
the methods inherited from the 'Readable' class to other classes that are NOT
derive directly from this one.

<p align="center">
    <img src="Documentation/Inheritance Good.png" alt="Good"/>
</p>

<p align="center">
    <img src="Documentation/Inheritance Bad.png" alt="Bad"/>
</p>

