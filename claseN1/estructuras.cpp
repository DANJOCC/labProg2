#include<iostream>
using namespace std;

struct Persona{
    string name;
    int edad;
    int ci;
};


int main(){

    union {
        float temperatura;
        int precio;
        float peso;
    };
    Persona p1,p2;


    p1.ci=27998876;
    p1.name="daniel";
    p1.edad=23;
    cout<<"hola yo soy "+p1.name<<"tengo "<<p1.edad<<" años de edad, mi cedula es: "<<p1.ci<<endl;

    p2=p1;

    cout<<"hola yo soy "+p2.name<<"tengo "<<p2.edad<<" años de edad, mi cedula es: "<<p2.ci<<endl;

    temperatura=4.5;

    cout<<temperatura<<endl;

    peso=3.12;

    cout<<temperatura<<endl;

}