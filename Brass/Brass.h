//
// Created by HP on 2019/6/20.
//

#ifndef BRASS_BRASS_H
#define BRASS_BRASS_H

#include <string>

class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;
public:
    Brass(const std::string & s= "Nullbody",long an = -1,
          double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    virtual void viewAcct() const ;
    double Balance() const ;
    virtual ~Brass(){}
};

//Brass Plus
class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500, double r = 0.11125);
    BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);
    virtual void viewAcct() const ;
    virtual void Withdraw(double amt);
    void ResetMax(double m){maxLoan = m;}
    void ResetRate(double r){rate = r;}
    void ResetOwes(){owesBank = 0;}
};


#endif //BRASS_BRASS_H
