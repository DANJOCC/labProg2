#include<iostream>
using namespace std;

// Prototipo de la funcion pow
/*
    Devuelve un dato del tipo float, y tiene como parametro un dato del tipo float
*/
float pow(float); 

// Prototipo de la funcion saludo
/*
   no devuelve ningun dato, solo realiza un proceso, y tiene como parametro un dato del tipo string
*/
void saludo(string);

//Parametros de la funcion main
/*
    argc = cantidad de argumentos dados al ejecutar el programa (por defecto 1)
    argv = arreglo/lista de argumentos pasados (por defecto siempre tiene un argumento: su misma direccion en el sistema )

*/

int main(int argc, const char *argv[]){


    cout<<argc<<endl;
    cout<<argv[0]<<endl;

    saludo(argv[1]); //<- llamada a la funcion saludos dando como argumento el segundo argumento dado al ejecutar el programa

    float b=pow(5.0);//<- llamada a la funcion pow dando como argumento el valor 5, y guardando el dato devuelto
    
    cout<<b<<endl;

    b=pow(6.0);//<- llamada a la funcion pow dando como argumento el valor 6, y guardando el dato devuelto

    cout<<b<<endl;

    b=pow(7.0);//<- llamada a la funcion pow dando como argumento el valor 7, y guardando el dato devuelto

    cout<<b<<endl;
}

/*
    Implementacion / cuerpo de las funciones
*/

float pow(float a){
    return a*a;
}

void saludo(string b){
    cout<<"hola "<<b<<endl;
}