#include<iostream>

using namespace std;

/*
    private y public son dos restricciones que nos permiten encapsular y dar
    ciertos valores de acceso a nuestras funciones (metodos) y variables (atributos)
    en nuestra clase
*/
//Definicion de la clase Person
class Person{
    
    private:
        string nombre;
        int edad;

    public:
        Person(string, int);
        void speak();
        void write(string, int);
        int getEdad();
        string getNombre();
        void setEdad(int);
        void setNombre(string);
};
