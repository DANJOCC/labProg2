#include<iostream>
#include<cmath>
using namespace std;

enum Planes{X, Y, Z, XY, XZ,YZ}; // planos/ejes de coordenadas

enum Dimensions{D1,D2,D3}; //dimensiones disponibles

enum Mode{POLAR,CARTESIANS}; // formato de coordenadas

int save_points = 0; // cantidad de puntos guardados
int format = CARTESIANS; //formato actual

//Estructura de coordenadas polares

struct Polar{   
   double alpha= 0;
   double beta = 0;
   double radius = 0;
};


// clase punto

class Point{
    private:
        double* coordinates=NULL; // coordenadas 
        int dimension=0; //dimension del punto

    public:
        Point(double); // constructor 1 dimension

        Point(double, double); // constructor 2 dimension

        Point(double,double,double); // constructor 3 dimension

        Point(int); //constructor solo para dimension

        Point(double[],int); // constructor dado un arrgelo y dimension

        double get_distance_to_center();

        double* get_vector(); //devuelve puntero a coordenadas

        int get_dimension();

        bool compare(Point); //compara un punto externo con el punto actual

        static bool compare(Point,Point); //compara dos puntos cualquiera

        static Point createPoint(double,double,double); // devuelve un punto
};

    Point::Point(double x){
        this->coordinates=new double;
        *coordinates=x;
        this->dimension=D1;
     }

    Point::Point(double x,double y){
        this->coordinates=new double[2];
        coordinates[X]=x;
        coordinates[Y]=y;
        this->dimension=D2;
     }

    Point::Point(double x,double y,double z){
        this->coordinates=new double[3];
        coordinates[X]=x;
        coordinates[Y]=y;
        coordinates[Z]=z;
        this->dimension=D3;
     }

    Point::Point(int dimension){
        this->dimension=dimension;
    }

    Point::Point(double cordinates[],int dimension){
        this->coordinates=cordinates;
        this->dimension=dimension;
    }

    int Point::get_dimension(){
        return this->dimension;
    }

    double Point::get_distance_to_center(){
        switch (this->dimension)
        {
        case D1:
            return *coordinates;
        case D2:
            return sqrt(coordinates[X] * coordinates[X] +
                         coordinates[Y] * coordinates[Y]);
        case D3:
             return sqrt(coordinates[X] * coordinates[X] +
                         coordinates[Y] * coordinates[Y] +
                         coordinates[Z] * coordinates[Z]);
        }
        return 0.0;
    }
    
    double* Point::get_vector(){
        return this->coordinates;
    }

    Point Point::createPoint(double x,double y ,double z){
        Point* p;
    
        if(x!=0 && y!=0 && z!=0){
            p= new Point(x,y,z);
        }
        else if(x!=0 && y!=0){
            p= new Point(x,y);
        }
        else{
            p= new Point(x);
        }
        return *p;
    }

    bool Point::compare(Point p1, Point p2){
        bool dimension=false;
        bool coordinates = false;

        dimension = p1.dimension == p2.dimension;

        if(dimension){
          switch (p1.dimension)
          {
            case D1:
                coordinates = *(p1.coordinates) == *(p2.coordinates);
                break;
            case D2:
                coordinates = p1.coordinates[X] == p2.coordinates[X] &&
                            p1.coordinates[Y] == p2.coordinates[Y];
                break;
            case D3:
                coordinates = p1.coordinates[X] == p2.coordinates[X] &&
                            p1.coordinates[Y] == p2.coordinates[Y] &&
                            p1.coordinates[Z] == p2.coordinates[Z];
                break;
          }
        }
        return dimension && coordinates;
    }
    bool Point::compare(Point p){
        bool dimension=false;
        bool coordinates = false;

        dimension = this->dimension == p.dimension;

        if(dimension){
          switch (this->dimension)
          {
            case D1:
                coordinates = *(this->coordinates) == *(p.coordinates);
                break;
            case D2:
                coordinates = this->coordinates[X] == p.coordinates[X] &&
                            this->coordinates[Y] == p.coordinates[Y];
                break;
            case D3:
                coordinates = this->coordinates[X] == p.coordinates[X] &&
                            this->coordinates[Y] == p.coordinates[Y] &&
                            this->coordinates[Z] == p.coordinates[Z];
                break;
          }
        }
        return dimension && coordinates;
    };