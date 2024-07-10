#include<iostream>
#include "../model/points.h"

using namespace std;

//cambia formato actual

void changeFormat(Mode m){ 
    format = m;
}

//devuelve formato

int getFormat(){
    return format;
}

//genera un punto

Point getPoint(float x=0, float y=0, float z=0){
    return Point::createPoint(x,y,z);
}

//compara si dos puntos son iguales

bool samePoint(Point p1, Point p2){
    return Point::compare(p1, p2);
}

//convierte a polar

Polar convertPolar(Point p){
    Polar vec;
    double* coordinates = p.get_vector();
    vec.radius=p.get_distance_to_center();
    if(p.get_dimension()==D2){

        vec.alpha= tanh(coordinates[Y] / coordinates[X]);

    }else if(p.get_dimension()==D3){

        vec.alpha= tanh(coordinates[Y] / coordinates[X]);

        double root = sqrt(coordinates[X] * coordinates[X] + coordinates[Y] * coordinates[Y]);
       
        double tan = root / coordinates[Z];

        vec.beta=  tanh( tan );
    }
  
  return vec;
    
}

//convierte a cartesianas

Point convertCartesian(Polar p,int dimension){
    Point* point;
   
    if(dimension==D2){

        point=new Point(
            p.radius * cos(p.alpha),
            p.radius * sin(p.alpha)
        );

    }else if(dimension==D3){


        point = new Point(
            p.radius * sin( p.beta ) * cos( p.alpha),
            p.radius * cos( p.beta ) * sin( p.alpha),
            p.radius * cos( p.beta)
        );
        
    }
  
  return *point;
    
}