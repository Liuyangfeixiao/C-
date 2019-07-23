#include <iostream>
#include <cmath>
#include "exa_mean.h"
double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);
int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout<<"Enter two numbers: ";
    while(cin>>x>>y)
    {
        try {
            z = hmean(x,y);
            cout<<"Harmonic mean of "<< x <<" and "<< y <<" is "<<z<<endl;
            cout<<"G mean of "<<x<<" and "<<y<<" is "<<gmean(x,y)<<endl;
            cout<<"Enter next set of numbers<q to quit>: ";
        }//end of try block
        catch (bad_hmean& bh)
        {
            bh.mesg();
            cout<<"Try again.\n";
            continue;
        }
        catch (bad_gmean& bg)
        {
            cout<<bg.mesg();
            cout<<"Value used: "<<bg.v1<<" , "<<bg.v2<<endl;
            cout<<"Sorry, you don't get to play anymore.\n";
            break;
        }

    }
    cout<<"Bye!";
    return 0;
}
double hmean(double a, double b) throw(bad_hmean)
{
    if (a==-b)
        throw bad_hmean(a,b);
    return 2.0*a*b/(a+b);
}

double gmean(double a, double b) throw(bad_gmean){
    if(a<0||b<0)
        throw bad_gmean(a,b);
    return std::sqrt(a*b);
}
