#include<iostream>
#include "./view/menu.cpp"
using namespace std;

int main()
{
    char opt='s';

    while(opt=='s'){
        getValues();
        cout<<"Desea continuar? (s= SI, n= NO)"<<endl;
        cin>> opt;
    }
    return 0;
}
