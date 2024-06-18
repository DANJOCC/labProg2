#include<iostream>
#include<cmath>
using namespace std;

//Estructura persona
struct Persona{
    int ci;
    int edad;
    string name;
    
    Persona(int ci, string name, int edad){
        this->ci=ci;
        this->name=name;
        this->edad=edad;
    }
};

//Estructura punto

struct Point2D{
    float x;
    float y;

    Point2D(float x, float y){
        this->x=x;
        this->y=y;
    }
   
};


//prototipos de funciones

/*
    print_ person_data : imprimir datos de persona
    
    max_persona: devuelve la mayor de dos personas

    vectorSum: devuelve la suma de dos vectores representado por sus componentes

    distance_point: devuelve la distancia entre dos puntos
*/
void print_person_data(Persona); 

Persona max_persona(Persona, Persona);

Point2D vectorSum(Point2D,Point2D);

float distance_point(Point2D,Point2D);


int main(){
    Persona p1(27998876, "Daniel", 23);
    Persona p2(30214894, "Alfonzo", 22);

    print_person_data(p1);
    print_person_data(p2);

    print_person_data( max_persona(p2,p1) );

    Point2D q1(10.2,14.5), q2(23.3, 32.3);

    cout<<"Distancia entre q1 y q2: "<< distance_point(q2, q1)<<endl;

    Point2D q3=vectorSum(q1,q2);
    cout<<"Vector resultante q3 = "<<"("<<q3.x<<", "<<q3.y<<")"<<endl;
    
}

void print_person_data(Persona p){
    cout<<"Cedula: "<<p.ci<<endl;
    cout<<"Nombre: "<<p.name<<endl;
    cout<<endl;
}

//Implementaciones

Point2D vectorSum(Point2D a,Point2D b){

    Point2D p(a.x+b.x, a.y+b.y);

   return p;
}

Persona max_persona(Persona p1, Persona p2){
    if(p1.edad>=p2.edad) return p1;
    return p2;
}

float distance_point(Point2D a,Point2D b){
    return sqrt( pow( (a.x-b.x) , 2 )+ pow( (a.y-b.y) , 2 ));
}