#include <iostream>
using namespace std;

template<class T>
void applyFunction(T array[],int a ,void(*func)(T)){
    for (int i = 0; i < a; i++)
    {
       func(array[i]);
    }
    
}

void printPow(int a){
    cout<<a*a<<endl;
}

void printDouble(int a){
    cout<<2*a<<endl;
}

void printConcat(string a){
    cout<<a+"papi"<<endl;
}

template<class T>
void (*myFuncPointer)(T);

int main(){

    int array[8]={1,2,3,4,5,6,7,8};

    string array1[3]={"mira ","que fue ","a la verga "};

    myFuncPointer<int> =printPow;

    applyFunction<int>(array,8,myFuncPointer<int>);

    myFuncPointer<int> =printDouble;

    applyFunction<int>(array,8,myFuncPointer<int>);

    myFuncPointer<string> =printConcat;

    applyFunction<string>(array1,8,myFuncPointer<string>);
}
