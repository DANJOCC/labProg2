/*
    Programa para crear un archivo a partir de otro archivo
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

ifstream input("./data/nombre.txt"); //Variable de flujo de entrada 
ofstream output("./data/salida.txt", ios::app); //variable de flujo de salida
/*
    ios::app -> agrega los datos en la parte final del archivo
    ios::out -> borra el contenido del archivo de salida y lo sustituye con los nuevos datos
*/

/*
    Comprobacion de apertura de archivos
*/

if(!input.is_open()){
    cout<<"no se encontro el archivo solicitado"<<endl;
    return -1;
}

if(!output.is_open()){
    cout<<"no se pudo crear el archivo de salida solicitado"<<endl;
    return -1;
}

/*
    Realizar copia
*/

    string name;
    int digit;
    while (!input.eof())
    {
        input>>name;
        if(!isdigit(name[0])){
            output<<name<<endl;
            continue;
        }
        digit=stoi(name);
        output<<digit+1<<endl;
    }
    

}