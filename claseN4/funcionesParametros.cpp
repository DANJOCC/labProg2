#include<iostream>
#include<cmath>
using namespace std;



struct Point2D{
    float x;
    float y;

    Point2D(float x, float y){
        this->x=x;
        this->y=y;
    }
   
};

//Paso por referencia

void grad_to_radians(float& alpha){
    alpha = (alpha*3.14)/180;
}

Point2D vectorSum(Point2D,Point2D);

Point2D vectorSum(float, float, float, float);

float distance_point(Point2D,Point2D);


int main(){
  
    Point2D q1(10.2,14.5), q2(23.3, 32.3);

    cout<<"Distancia entre q1 y q2: "<< distance_point(q2, q1)<<endl;

    Point2D q3=vectorSum(q1,q2);

    cout<<"Vector resultante q3 = "<<"("<<q3.x<<", "<<q3.y<<")"<<endl;
    
    float alpha = 60;
    float beta = 70;

    grad_to_radians(alpha);
    grad_to_radians(beta);

    Point2D q4=vectorSum(34,45,alpha, beta);

    cout<<"Vector resultante q4 = "<<"("<<q4.x<<", "<<q4.y<<")"<<endl;
    cout<<"angulo alpha en radianes: "<<alpha<<endl;
     cout<<"angulo beta en radianes: "<<beta<<endl;
}


Point2D vectorSum(Point2D a,Point2D b){

    Point2D p(a.x+b.x, a.y+b.y);

    return p;
}

Point2D vectorSum(float mag1,float mag2, float alpha, float beta){

    Point2D p(mag1*cos(alpha)+mag2*cos(beta), mag1*sin(alpha)+mag2*sin(beta));

    return p;
}


float distance_point(Point2D a,Point2D b){
    return sqrt( pow( (a.x-b.x) , 2 )+ pow( (a.y-b.y) , 2 ));
}