#include<iostream>
#include "./modulos.h"
using namespace std;

//Implementacion de las funciones de la clase persona.


//El namespace Person:: nos permite diferenciar funciones de los metodos de las clases
Person::Person(string nombre, int edad){
    this->nombre=nombre;
    this->edad=edad;
}

int Person::getEdad(){
    return this->edad;
}

int getEdad(){
    return 24;
}
string Person::getNombre(){
    return this->nombre;
}

void Person::setEdad(int edad){
    this->edad=edad;
}

void Person::setNombre(string nombre){
    this->nombre=nombre;
}

void Person::write(string nombre, int edad){
    cout<<"Yo escribo el nombre de "<<nombre<<" y la edad de "<<edad<<endl;
}

void Person::speak(){
    cout<<"Mi nombre es "<<nombre<<" y tengo "<<edad<<" de edad"<<endl;
}

