#include<iostream>
using namespace std;

/*

    Estructura punto

    Descripcion: guarda las coordenadas de un punto en plano bidimensional.

    Espacio de memoria utilizado = 2*sizeof(float)=8 bytes

    Miembros de la estructura:

    x = coordenada en eje x
    y = coordenada en eje y
*/

    struct Point{
        float x;
        float y;
    };

/*

    Union Marca

    Descripcion: guarda uno de dos datos de una marca en el espacio bidimensional.

    Espacio de memoria utilizado = Mayor espacio utilizado por un miembro de la union = 8 bytes

    Miembros de la union:

    a = etiqueta de la marca
    p = coordenadas de la marca
*/

    union Marca{
        char a;
        Point p;
    };



int main(){

    /*
        Forma de utilizar un mismo espacio de memoria para mas de una variable
    */

    union {
        int z;
        int a;
    };

    z=28;
      cout<<z<<endl;
    a=29;

    cout<<a<<endl;
    cout<<z<<endl;

    Marca u; //declaracion de una variable del tipo Marca

    u.a='a';

    cout<<u.a<<endl;

    u.p.x=23;
    u.p.y=24;

    cout<<u.p.x<<endl;
    cout<<u.p.y<<endl;
    cout<<u.a<<endl;
}