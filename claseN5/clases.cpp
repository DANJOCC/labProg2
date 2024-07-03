#include<iostream>
#include "./modules/modulos.cpp"

using namespace std;

int main(){
    Person p1("daniel",23); //Creacion de una instancia de clase (objeto)

    //utilizacion de los metodos de la clase

    p1.speak(); 
    p1.write("pancho",14);

    cout<<p1.getEdad()<<endl;
    cout<<getEdad()<<endl;
    return 0;
}