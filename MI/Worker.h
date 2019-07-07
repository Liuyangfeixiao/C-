//
// Created by HP on 2019/7/4.
//

#ifndef MI_WORKER_H
#define MI_WORKER_H

#include <string>

class Worker {  //ABC 抽象基类
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const ;
    virtual void Get()  ;

public:
    Worker():fullname("no name"),id(0L){}
    Worker(const std::string& s,long n):fullname(s),id(n){}
    virtual ~Worker()=0; //纯虚函数
    virtual void Set()=0;
    virtual void Show() = 0;
    virtual void Show() const = 0;
};

class Waiter: virtual public Worker //虚基类，需显式调用虚基类的构造函数
{
private:
    int panAche;
protected:
    void Data() const ;
    void Get();

public:
    Waiter() : Worker(),panAche(0){}
    Waiter(const std::string& s, long n, int p)
    : Worker(s,n),panAche(p){}
    Waiter(const Worker& wk, int p): Worker(wk),panAche(p){}
    void Set();
    void Show() const ;
};
class Singer: virtual public Worker
{
protected:
    enum {other,alto, contralto, soprano,
            base, baritone,tenor};
    enum {Vtypes = 7};
    void Data() const ;
    void Get();

private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer(): Worker(),voice(other){}
    Singer(const std::string& s, long n, int v = other): Worker(s,n),voice(v){}
    Singer(const Worker& wk,int v = other): Worker(wk),voice(v){}
    void Set();
    void Show() const ;
};

//MI
class SingerWaiter: public Singer,public Waiter
{
protected:
    void Data()const ;
    void Get();

public:
    SingerWaiter(){}
    SingerWaiter(const std::string& s, long n, int p = 0, int v = other):
    Worker(s,n),Waiter(s,n,p),Singer(s,n,v){}
    SingerWaiter(const Worker& wk,int p = 0,int v = other):
    Worker(wk),Waiter(wk,p),Singer(wk,v){}
    SingerWaiter(const Waiter& wt, int v = other):
    Worker(wt),Waiter(wt),Singer(wt,v){}
    SingerWaiter(const Singer& sg, int p = 0):
    Worker(sg),Waiter(sg,p),Singer(sg){}
    void Set();
    void Show()const ;

};


#endif //MI_WORKER_H
