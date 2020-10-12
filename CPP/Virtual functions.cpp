#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    public:
    virtual void getdata(){;}
    virtual void putdata(){;}
};
class Professor:public Person{
private:
static int id;
int curid;
int publications;
public:
    Professor(){
        curid=id++;
    }
void getdata(){
cin>>name>>age>>publications;
}
void putdata(){
    cout<<name<<" "<<age<<" "<<publications<<" "<<curid<<endl;
}
};
class Student:public Person{
private:
int curid;
static int id;
int marks[6];
public:
Student(){
    curid=id++;
}
void getdata(){
    cin>>name>>age;
    for(int i=0;i<6;i++)
    cin>>marks[i];
}
void putdata(){
    cout<<name<<" "<<age<<" ";
    int sum=0;
    for(int x:marks)
    sum+=x;
    cout<<sum<<" "<<curid<<endl;
}
};
int Professor::id=1;
int Student::id=1;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
