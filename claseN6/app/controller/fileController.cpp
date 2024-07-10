#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "./pointController.cpp"

using namespace std;

//agrega un punto (coordenadas cartesianas) al archivo de puntos

void add_point( Point point,
                string file="./model/points.csv"){
    
    ofstream output(file, ios::app);

    if( !output.is_open() ){
        cout<<"No se pudo crear el archivo"<<endl;
        return;
    }

    save_points++;

    Polar p;
    double * coordinates=NULL;
   
        coordinates=point.get_vector();

            if(point.get_dimension()==D2){
              
                output<<coordinates[X]<<";"<<coordinates[Y]<<";"<<0<<endl;
            
            }else if(point.get_dimension()==D3){
                
                output<<coordinates[X]<<";"
                      <<coordinates[Y]<<";"
                      <<coordinates[Z]<<endl;
            
            }
            


    coordinates=NULL;

    output.close();
    
}

//guarda un punto (coordenadas polares) en el archivo de puntos

void add_point( Polar point,
                int dimension,string file="./model/points.csv"){
    
    ofstream output(file, ios::app);

    if( !output.is_open() ){
        cout<<"No se pudo crear el archivo"<<endl;
        return;
    }

    save_points++;

   if(dimension== D2){
         output<<point.radius<<";"<<point.alpha<<";"<<0<<endl;
   }else{
         output<<point.radius<<";"<<point.alpha<<";"<<point.beta<<endl;
   }

    output.close();
    
}

//genera un archivo de puntos dado un arreglo

void generate_file_points( string file="./model/points.csv", 
                           Point points[] = {},
                           int size = 0,
                           bool opt =false){
    
    ofstream output(file, ios::app);

    if( !output.is_open() ){
        cout<<"No se pudo crear el archivo"<<endl;
        return;
    }

    save_points=size;

    Polar p;
    double * coordinates=NULL;
    format = opt ? CARTESIANS : POLAR;
    for (int i = 0; i < size; i++)
    {
        coordinates=points[i].get_vector();
        if(opt){

            p=convertPolar(points[i]);
            
            output<<p.radius<<";"<<p.alpha<<";"<<p.beta<<endl;
        
        }else{

            if(points[i].get_dimension()==D2){
              
                output<<coordinates[X]<<";"<<coordinates[Y]<<";"<<0<<endl;
            
            }else if(points[i].get_dimension()==D3){
                
                output<<coordinates[X]<<";"
                      <<coordinates[Y]<<";"
                      <<coordinates[Z]<<endl;
            
            }
            
        }

      
    }

    coordinates=NULL;

    output.close();
    
}

//limpia el archivo de puntos

void clear_file(string file="./model/points.csv"){
     ofstream output(file);

    if( !output.is_open() ){
        cout<<"No se pudo crear el archivo"<<endl;
        return;
    }
    output<<"";

    output.close();
}

//lee un archivo de puntos

void read_file(string file="./model/points.csv"){
    ifstream input(file);

    if( !input.is_open() ){
        cout<<"No se pudo abrir el archivo"<<endl;
        return;
    }

    string x="";
    string word="";
    if(format == POLAR){
        cout<<"puntos en coordenadas polares: "<<endl;
    }
    else{
        cout<<"puntos en coordenadas cartesianas "<<endl;
    }
   while (!input.eof())
    {
        std::getline(input,x);

        stringstream s(x);
        while (getline(s,word,';'))
        {
            cout<<word<<"; ";
        }
        cout<<endl;
    }
    input.close();
}