#include<iostream>
using namespace std;

/*
    Estructura Telefono:

    Descripcion: guarda los datos que conforman un numero de telefono.

    Espacio de memoria utilizado = 3*sizeof(int)=12 bytes

    Miembros de la estructura:

    codeArea = codigo de area
    codeTelefonia = codigo de telefonia
    number = numero de telefono (sin codigo de area ni codigo de telefonia)
*/

struct Telefono{
    int codeArea;
    int codeTelefonia;
    int number;
};

   /* Estructura Persona:

     Descripcion: guarda los datos de una persona.

    Espacio de memoria utilizado = sizeof(String)+2*sizeof(int) + sizeof(char)+ sizeof(telefono)+padding alignment= 32+8+1+12+3=56 bytes

    Miembros de la estructura:

    genero= genero de la persona;
    ci= cedula de la persona;
    edad= edad de la persona;
    tlf= telefono de la persona (Estructura Telefono);
    nombre= nombre de persona

    funciones:

    constructor: Persona(string , int, int , char, int, int , int )
   */

struct Persona{
    char genero;
    int ci;
    int edad;
    Telefono tlf;
    string nombre;
    Persona(string nombre, int ci, int edad, char genero, int codeA, int codeT, int codeN){
        this->ci=ci;
        this->edad=edad;
        this->genero=genero;
        this->nombre=nombre;
        this->tlf.codeArea=codeA;
        this->tlf.codeTelefonia=codeT;
        this->tlf.number=codeN;
    }
};


/*
    Como forma alternativa se tiene:

    struct Persona{
    char genero;
    int ci;
    int edad;
    struct {
        int codeArea;
        int codeTelefonia;      No es necesario especificar el nombre de la estructura solo crear la variable
        int number;             la represente.
    } tlf;
    string nombre;
    Persona(string nombre, int ci, int edad, char genero, int codeA, int codeT, int codeN){
        this->ci=ci;
        this->edad=edad;
        this->genero=genero;
        this->nombre=nombre;
        this->tlf.codeArea=codeA;
        this->tlf.codeTelefonia=codeT;
        this->tlf.number=codeN;
    }
};


*/


int main(){

    Persona p={"daniel",2,23,'M',58,412,6757574}; //<-declaracion de un objeto/variable persona
    
    //forma alternativa de escribirlo

    //Persona p=("daniel",2,23,'M',58,412,6757574);

    //sin constructor

    //Persona p={'M',2,23,"daniel",{58,412,6757574}}; cada valor corresponde a cada miembro en el mismo orden

    //uso de memoria de cada estructura

    cout<<sizeof(Persona)<<endl; 
    cout<<sizeof(Telefono)<<endl;

    Persona p2=p;//<- una de las operaciones validas con estructuras (asignacion/igualacion)

    /*
    operaciones no validas

    p+p2; operaciones aritmeticas
    p==p2; operaciones relacionales
    p&&p2; operaciones logicas
    
    */


    //Acceso e impresion de valores en estructuras
    cout<<p2.ci<<endl;
    cout<<p2.edad<<endl;
    cout<<p2.genero<<endl;
    cout<<p2.nombre<<endl;
    cout<<p2.tlf.codeArea<<" 0"<<p2.tlf.codeTelefonia<<"-"<<p2.tlf.number<<endl;

}