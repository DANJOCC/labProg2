#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file;


    //abrimos el archivo para empezar a escribir datos en binario

    file.open("./data/binario.bin", ios::binary|ios::out);

    if(!file.is_open()){ 
        cout<<"no se encontro el archivo de salida"<<endl;
    }
 

    /*
        Declaran la variable donde se estaran guardandos los datos a escribir, para el ejemplo utilizaremos una variable tipo int
    */

    int x=0;

    for (int i = 0; i < 10; i++)
    {
        x=x+2*i;

        /*
            Para escribir solo se requiere de la funcion write(), donde pasamos como argumentos: nuestra variable transformada a un puntero char
            y el tamano en bytes de la variable
        */

        file.write((char *) &x, sizeof(int));
    }

    /*
        Traten de abrir el archivo por medio del block de notas una vez ejecutado el programa,
        y veran como los datos no pueden ser entendidos
    
    */
    
    file.close();

    file.open("./data/binario.bin", ios::binary|ios::in);

    //volvemos abrir el archivo, pero esta vez como entrada

    if(!file.is_open()){ 
        cout<<"no se encontro el archivo de entrada"<<endl;
    }

  
    while (!file.eof()) // el error en clase fue porque escribi mal la condicion de repeticion, me falto el !
    {
    
        /*
            Mismo procedimiento anterior, pero esta vez con la funcion read()
        */

        file.read((char *) &x, sizeof(int));
        cout<<x<<endl;
    }
    

   



}