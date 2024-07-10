#include<iostream>
#include "../controller/fileController.cpp"


using namespace std;

//variables de control

float point[3];
float dimension= 3;
char formato;

//guarda un punto haciendo una llamada a la funcion add_point de pointController

void savePoint(){
    char opt;
    cout<<"Desea guardar el punto (s = Si, n = No)"<<endl;
    std::cin>>opt;

    if(opt != 's'){
        return;
    }
    else{
        cout<<"Por favor, ingrese formatoo para guardar (p = Polar, c = Catersianas)"<<endl;
        cin>>opt;

        if(opt == 'p' && formato == 'p'){
            Polar p;

            p.radius = point[0];
            p.alpha = point[1];
            p.beta = point[2];

            add_point(p,dimension);
        }else if(opt == 'p' && formato == 'c'){
             
            add_point(convertPolar(getPoint(point[0],point[1],point[2])),dimension);
        }else if( opt == 'c' && formato == 'c'){
             add_point(getPoint(
                point[0],
                point[1],
                point[2]));
        }
        else{
            Polar p;

            p.radius = point[0];
            p.alpha = point[1];
            p.beta = point[2];
            add_point(convertCartesian(p,dimension));
        }
    }
}

//obtiene las coordenadas desde la consola

void getValues(){
    
    cout<<"Por favor, ingrese dimension a trabajar"<<endl;
    cin>>dimension;
    
    if(dimension>3 || dimension<2) dimension = 3;

    cout<<"Por favor, ingrese formato a trabajar (p = Polar, c = Catersianas)"<<endl;
    cin>>formato;
    
    if(formato == 'p'){
        cout<<"Por favor, ingrese valor de radio";
        cin>>point[0];

        cout<<"Por favor, ingrese valor del angulo alpha";
        cin>>point[1];
        
    }else{
        cout<<"Por favor, ingrese valor de X";
        cin>>point[0];

        cout<<"Por favor, ingrese valor de Y";
        cin>>point[1];
    }

    if(dimension==3 && formato=='p'){
         cout<<"Por favor, ingrese valor de angulo beta";
        cin>>point[2];
    }
    else if(dimension==3){
         cout<<"Por favor, ingrese valor de Z";
        cin>>point[2];
    }

    savePoint();

}
