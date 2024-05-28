#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file;
    fstream file2;

    file.open("./data/input.txt", ios::in);
    file2.open("./data/output.txt",ios::out);

/*is_open -> devuelve true si se abrio
 el archivo, devuelve false si no se logro abrir el arcivo*/

    if(!file.is_open()){ 
        cout<<"no se encontro el archivo de entrada"<<endl;
    }
    if(!file2.is_open()){ 
        cout<<"no se puedo crear/abrir el archivo de salida"<<endl;
    }

    char *cadena=new char[6]; //cadena de caracteres de 6 caracteres

    file.read(cadena,6);//leer los primeros 6 caracteres

    int x=file.tellg(); //obtener posicion del lector, en el ejemplo seria 7;

    cout<<x<<endl;//salida consola -> 7

    file.seekg(2);//colocar lector en la posicion 2 (caracter), el lector se ubica en la n de daniel

    x=file.tellg();//obtener posicion del lector, en el ejemplo seria 7;

    cout<<x<<endl;//salida consola -> 2

    file2.write(cadena,5);// escribe en el archivo de salida los primeros 5 caracteres de los primeros 6 leidos anteriormente en linea 24

    file.read(cadena,6);//leer siguientes 6 caracteres, recuerden que esta en la posicion 2

    int y=file2.tellp();//obtener posicion de la salida (donde se empezara a escribir)

    cout<<y<<endl;//salida consola -> 5

   file2.write(cadena,5);//escribe los 5 de los 6 caracteres leidos desde la posicion 2, linea 38, hasta este punto la salida en el archivo es danieniel 

   file2.seekp(2);//devuelve el cursor de salida a la posicion 2

   file2.write(cadena,5);//salida ->daniel el, vuelve a escribir los 5 caracteres anterios, pero esta vez sustituye los caracteres que estaban antes


    file.close();
    file2.close();
}