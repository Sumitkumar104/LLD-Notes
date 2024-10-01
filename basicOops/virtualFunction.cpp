#include<bits/stdc++.h>
using namespace std;


/*
A virtual function in a class ia a member function of class that except us to override in derived class.
 When you use a pointer or a reference to a base class to call a virtual function, the call is dynamically bound to the appropriate function in the derived class at runtime.
*/


/*
In C++, a pure virtual function is a function that is declared in a base class but does not have an implementation in that class. The purpose of a pure virtual function is to define an interface that derived classes must implement. A class that contains at least one pure virtual function is called an abstract class and cannot be instantiated on its own.

An abstract class is a class which contain at least 1 pure virtal function.
we can not make the object of the abstract class.

*/

class base{
    public:
     virtual void fnc1(){
        cout<<" i am in base function";
        return ;
    }

    virtual void checkPureVirtualFunction()=0;

};
class derived: public base{
    public:
    void fnc1(){
        cout<<" i am in derviced class";
        return ;
    }

    void checkPureVirtualFunction(){
        cout<<"I am in pure virtual function which derive in derived class";
    }
};

int main(){
    
    // method 1
    derived b;
    // derived d;
    // b=&d;
    
    // method 2
    // base* b=new derived();
    cout<<"scd ";
    b.fnc1();

    // if I not use the virtual keyword output is I am in base class
    // if I used it output is I am in derived class.

    // So if I know our member function can be update and I need the update function with the help of reference of base class then we need to make it virtual.
    return 0;
}