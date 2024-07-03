#include<iostream>

using namespace std;

int main(){
    int* pointer; //int* pointer = NULL, int* pointer= nullptr (punteros apuntando a nada)
    int* pointer2= new int;

    int var1=13;
    cout<<"valores de pointer sin asignacion"<<endl;
    //valores de puntero sin una direccion de memoria asignada previamente.
    cout<<pointer<<endl;

    //cout<<(*pointer)<<endl; //genera un error donde se cierra el programa
    //cout<<&pointer<<endl;   // por no tener una direccion de memoria valida asignada
    

    pointer = &var1;  // el operador & devuelve la direccion de memoria propia de una variable
    cout<<"valores de pointer"<<endl;
    cout<<"valor de memoria guardado "<<pointer<<endl;
    cout<<"valor dentro de la memoria guardada "<<(*pointer)<<endl; 
    cout<<"direccion de memoria del puntero "<<&pointer<<endl;
    cout<<endl<<endl;
    cout<<"puntero 2, valor de memoria guardado "<<pointer2<<endl;
    cout<<"puntero 2, valor dentro de la memoria guardada "<<(*pointer2)<<endl; 
    cout<<"puntero 2, direccion de memoria del puntero "<<&pointer2<<endl;

    cout<<endl<<endl;
    cout<<"valor de variable var1 antes "<<var1<<endl;

    *pointer=15; //se accede y se manipula el contenido de la direccion de memoria
                //guardada en el puntero
    cout<<"valor de variable var1 despues "<<var1<<endl;
    
    cout<<endl<<endl;
    
    *pointer2=*pointer;//se igualan los contenidos de las direcciones de memorias guardadas
                        // en los punteros

    cout<<"valores de punteros con misma asignacion de dato en la direccion de memoria guardada"<<endl;
    cout<<"valor de memoria guardado "<<pointer<<endl;
    cout<<"valor dentro de la memoria guardada "<<(*pointer)<<endl;
    cout<<"direccion de memoria del puntero "<<&pointer<<endl;
    cout<<endl;
    cout<<"puntero 2, valor de memoria guardado "<<pointer2<<endl;
    cout<<"puntero 2, valor dentro de la memoria guardada "<<(*pointer2)<<endl; 
    cout<<"puntero 2, direccion de memoria del puntero "<<&pointer2<<endl;


    cout<<endl<<endl;

    pointer=pointer2; // se igualan la direccion de memoria contenida en los punteros
 
    
    cout<<"valores de punteros igualados"<<endl;
     cout<<"valor de memoria guardado "<<pointer<<endl;
    cout<<"valor dentro de la memoria guardada "<<(*pointer)<<endl; //genera un error donde se cierra el programa por no apuntar a nada
    cout<<"direccion de memoria del puntero "<<&pointer<<endl;
    cout<<endl;
     cout<<"puntero 2, valor de memoria guardado "<<pointer2<<endl;
    cout<<"puntero 2, valor dentro de la memoria guardada "<<(*pointer2)<<endl; 
    cout<<"puntero 2, direccion de memoria del puntero "<<&pointer2<<endl;

    //se libera utilizada por los punteros para poder posteriormente reasignarle 
    //otra direccion de memoria.
    delete pointer;
    delete pointer2;
    return 0;
}
