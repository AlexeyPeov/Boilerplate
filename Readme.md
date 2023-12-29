# Boilerplate

I dont like writing default constructors.

## Compilation

To compile this, i've used g++.

```bash
g++ -std=c++17 main.cpp -o bp 
```

## Usage

The logic is straightforward: 
 * the program takes every instance of "class_name" from "boilerplate_cpp.txt" and "boilerplate_header.txt"
 * replaces them to the name of a class you specified 

So, you can edit these two text files to add more boilerplate.

For now, if you run the program like this:

```bash
./bp BoilerPlateClass
```
This will produce .h and .cpp files for the "BoilerPlateClass" class.


#### HEADER:

```c++
#ifndef BOILER_PLATE_CLASS_H
#define BOILER_PLATE_CLASS_H

#include <iostream>

class BoilerPlateClass{
public:
   // BoilerPlateClass constructor and destructor
   BoilerPlateClass();
   ~BoilerPlateClass();

   // copy constructors
   BoilerPlateClass(const BoilerPlateClass& other);
   BoilerPlateClass& operator=(const BoilerPlateClass& other);

   // move constructors
   BoilerPlateClass(const BoilerPlateClass&& other);
   BoilerPlateClass& operator=(const BoilerPlateClass&& other);

   // print overload
   friend std::ostream& operator<<(std::ostream& os, const BoilerPlateClass& obj);

private:



};
#endif
```

#### CPP:

```c++
#include "BoilerPlateClass.h"

BoilerPlateClass::BoilerPlateClass(){

}

BoilerPlateClass::~BoilerPlateClass(){

}


BoilerPlateClass::BoilerPlateClass(const BoilerPlateClass& other){

}

BoilerPlateClass& BoilerPlateClass::operator=(const BoilerPlateClass& other){

}

BoilerPlateClass::BoilerPlateClass(const BoilerPlateClass&& other){

}

BoilerPlateClass& BoilerPlateClass::operator=(const BoilerPlateClass&& other){

}

std::ostream& operator<<(std::ostream& os, const BoilerPlateClass& obj)
{
    os << "BoilerPlateClass object";
    return os;
}
```

Do whatever you want with this. 


