//
// Created by HP on 2019/6/20.
//

#include "Brass.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
Brass::Brass(const string &s, long an, double bal) {
fullName = s;
acctNum = an;
balance = bal;
}

void Brass::Deposit(double amt) {
    if(amt<0)
        cout<<"Negative deposit not allowed; "
        <<"deposit is cancelled.\n  ";
    else
        balance += amt;
}
void Brass::Withdraw(double amt) {
//    set up ###.## format
format initialState = setFormat();
precis prec = cout.precision(2);

    if(amt<0)
        cout<<"Negative withdraw not allowed; "
        <<"withdraw is cancelled.\n";
    else if(amt<=balance)
        balance -= amt;
    else
        cout<<"withdraw amount $"<<amt<<" exceed the balance.\n"
        <<"withdraw canceled\n";
    restore(initialState,prec);
}
double Brass::Balance() const {
    return balance;
}
void Brass::viewAcct() const {
    //set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout<<"Client: "<<fullName<<endl;
    cout<<"Account Number: "<<acctNum<<endl;
    cout<<"Balance: $"<<balance<<endl;
    restore(initialState,prec);
}
// BrassPlus Methods
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r):Brass(s,an,bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r):Brass(ba) {
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}
//redefine how ViewAcct() work

void BrassPlus::viewAcct() const {
//    set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::viewAcct();
    cout<<" Maximum loan: $"<<maxLoan<<endl;
    cout<<"Owed to bank: $"<<owesBank<<endl;
    cout.precision(3);
    cout<<"Loan Rate: "<<100*rate<<"%\n";
    restore(initialState,prec);
}
void BrassPlus::Withdraw(double amt) {
    //set up the ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);
    double bal = Balance();
    if (amt<=bal)
        Brass::Withdraw(amt);
    else if(amt<=bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance *(1+rate);
        cout<<"Bank advance: $"<<advance<<endl;
        cout<<"Finance charge: $"<<advance*rate<<endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else
        cout<<"Credit card limit exceed. Transaction canceled.\n";
    restore(initialState,prec);
}
format setFormat()
{
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}
void restore(format f, precis p)
{
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}

