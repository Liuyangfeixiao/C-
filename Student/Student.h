//
// Created by HP on 2019/6/30.
//

#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H

#include <iostream>
#include <valarray>
#include <string>

class Student : private std::valarray<double >,private std::string{
private:
    typedef std::valarray<double> ArrayDb;
    //private method for scores output
    std::ostream& arr_out(std::ostream& os) const ;

public:
    Student():std::string("Null"),ArrayDb(){}
    Student(const std::string& s): std::string(s),ArrayDb(){}
    Student(int n): std::string("Nully"), ArrayDb(n){}
    Student(const std::string& s, int n):std::string(s),ArrayDb(n){}
    Student(const std::string& s, const ArrayDb& a): std::string(s), ArrayDb(a){}
    Student(const char* str, const double pd, int n): std::string(str),ArrayDb(pd,n){}
    ~Student(){}
    double Average() const ;
    double &operator[](int i);
    double operator[](int i) const ;
    const std::string& Name() const ;

    //friend
    friend std::istream&operator>>(std::istream& is, Student& stu);
    friend std::istream& getline(std::istream&, Student& stu);
    friend std::ostream&operator<<(std::ostream& os, Student& stu);
};


#endif //STUDENT_STUDENT_H
