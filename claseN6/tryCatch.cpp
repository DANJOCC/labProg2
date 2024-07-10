#include <iostream>
using namespace std;

void func3(bool flag, bool flag2){
    try
    {
        /* if(!flag){
            string a ="fatal";
            throw a;
        }*/

         if(flag){
            throw 3;
        }

        if(flag2){
            throw 'a';
        }
    
    }
    catch(string e)
    {
        cout<<e<<endl;
    }
    
}
void func2(bool flag){
    try
    {
         if(flag){
            throw 2;
        }
        else{
            func3(true,false);
        }
    }
    catch(char e)
    {
        cout<<"error tipo:"<<e<<endl;
    }
    
}
void func1(bool flag){
    try
    {
        if(flag){
            throw 1;
        }
        else{
            func2(false);
        }
    }
    catch(int e)
    {
        cout<<"error en:"<<e<<endl;
    }
    
}
 
int main()
{
    func1(false);
}