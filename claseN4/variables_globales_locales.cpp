#include<iostream>
#include<cmath>
using namespace std;



float alpha = 60;
float beta2 = 70;

//Parametro como variable local

float grad_to_radians(float alpha){
    alpha = (alpha*3.14)/180;
   return alpha;
}

//Variable local declarada dentro de la funcion

/*float grad_to_radians(float a){
    float alpha = (a*3.14)/180;
   return alpha;
}*/

//Sin variable local, se utiliza la global

/*float grad_to_radians(float a){
    alpha = (a*3.14)/180;
   return alpha;
}
*/

int main(){
  
 
    cout<<"angulo alpha: "<<alpha<<endl;
     cout<<"angulo beta : "<<beta2<<endl;
     cout<<"angulo alpha en radianes:"<<grad_to_radians(alpha)<<endl;
     cout<<"angulo beta en radianes:"<<grad_to_radians(beta2)<<endl;
     cout<<"angulo alpha : "<<alpha<<endl;
     cout<<"angulo beta : "<<beta2<<endl;
}


