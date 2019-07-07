//
// Created by HP on 2019/7/4.
//

#include "Worker.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Worker::~Worker() {}

//保护成员
void Worker::Data() const {
    cout<<"Name: "<<fullname<<endl;
    cout<<"Employee ID: "<<id<<endl;
}
void Worker::Get()  {
    getline(cin,fullname);
    cout<<"Enter worker's ID: ";
    cin>>id;
    while (cin.get()!= '\n')
        continue;
}
void Waiter::Set() {
    cout<<"Enter waiter's name: ";
    Worker::Get();
    Get();
}
void Waiter::Show() const {
    cout<<"Category: waiter\n";
    Worker::Data();
    Data();
}

void Waiter::Data() const {
    cout<<"Panache rating: "<<panAche<<endl;
}
void Waiter::Get() {
    cout<<"Enter the waiter's panache rating: ";
    cin>>panAche;
    while (cin.get()!='\n')
        continue;
}
char * Singer::pv[Vtypes] = {"other","alto", "contralto", "soprano",
                             "base", "baritone","tenor"};
void Singer::Set() {
    cout<<"Enter the singer's name: ";
    Worker::Get();
    Get();
}

void Singer::Show() const {
    cout<<"Category: Singer\n ";
    Worker::Data();
    Data();
}


void Singer::Data() const {
    cout<<"Vocal range: "<< pv[voice]<<endl;
}
void Singer::Get() {
    cout<<"Enter number for singer's vocal range: \n";
    int i;
    for(i = 0;i<Vtypes;i++) {
        cout << i << ": " << pv[i] << "  ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i%4!=0)
        cout<<endl;
    cin>>voice;
    while (cin.get()!= '\n')
        continue;
}
void SingerWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingerWaiter::Get() {
    Waiter::Get();
    Singer::Get();
}

void SingerWaiter::Set() {
    cout<<"Enter singing waiter's name: ";
    Worker::Get();
    Get();
}

void SingerWaiter::Show() const {
    cout<<"Category: singing waiter\n";
    Worker::Data();
    Data();
}