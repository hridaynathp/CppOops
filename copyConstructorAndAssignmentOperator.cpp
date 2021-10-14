/*
    This program will demonstrate the implementation of
    copy constructor and assignment operator, and in which
    scenarios they gets activated
*/

#include <iostream>

using namespace std;
class Test{
    int id;
    string name;
public:
    // Default constructor, default initialization
    Test():id(0),name(""){cout<<"Default"<<endl;}
    // Parameterized constructor
    Test(int id, string name):id(id),name(name){cout<<"parameterized"<<endl;}
    // Display/print method
    void print(){
        cout<<"ID:"<<id<<", Name:"<<name<<endl;
    }

    /* Copy constructor Gets called:
        1. Pass by value
        2. Return by valued
        3. Object construction while creating object with another object
        4. When compiler generates temporary object
    */
    /*private: If we make copy constructor private then compiler
               will not allow to copy object of class */
    Test(const Test& other){
        id=other.id;
        name=other.name;
        cout<<"copy constructor gets called"<<endl;
    }

    Test& operator=(const Test& other){
        id = other.id;
        name = other.name;
        cout<<"assignment operator gets called"<<endl;
        return *this;
    }

    ~Test(){
            // deallocate memory if any you have allocated on heap
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Test t1(1,"kiran");
    t1.print();

    int* p;
    int i = 10;
    p = &i;
    cout<<p<<endl;
    Test t2(t1); // This will invoke copy constructor
    Test t3;
    t3=t1; // This will invoke assignment operator
    return 0;
}
