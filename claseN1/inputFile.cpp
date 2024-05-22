/*
    Programa para leer los datos en un archivo con formato csv e imprimirlos en pantalla
*/


#include<iostream>
#include<fstream> // libreria para manipulacion de archivos
#include<string> //libreria para manipulacion de variables tipo string
#include <sstream> //libreria para flujos de datos a partir de strings
using namespace std;

int main()
{
    ifstream input("./data/note.txt", ios::in); //declaracion de variable de flujo

    if(!input.is_open()){
        cout<<"no se encontro el archivo"<<endl;
    }

    /*
        x: guarda una linea del archivo
        word: guarda las cadenas de caracteres separadas por coma
        y: guarda las cadenas de caracteres convertidas a numeros enteros
        bool: variable de control para la deteccion de una palabra
    */

    string x;
    string word;
    int y;
    bool flag=false;

    while (!input.eof())
    {
        getline(input,x);

        stringstream s(x);
        while (getline(s,word,','))
        {
            flag= false;
            for (int i = 0; i < word.length(); i++)
            {
                if(!isdigit(word[i])){
                    flag=true;
                    break;
                }
            }

            if(flag){
                cout<<word<<" ";
                continue;
            }
            y=stoi(word)+1;
            cout<<y<<" ";
        }
        cout<<endl;
    }
    

    input.close(); //cerrado del archivo
    return 0;
}
