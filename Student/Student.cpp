//
// Created by HP on 2019/6/30.
//

#include "Student.h"
using std::ostream;
using std::endl;
using std::string;
using std::istream;

double Student::Average() const {
    if(ArrayDb::size()>0)
        return ArrayDb::sum()/ArrayDb::size();
    else return 0;
}

double &Student::operator[](int i) {
    return ArrayDb::operator[](i);
}

const std::string &Student::Name() const {
    return (const string&)*this;
}

double Student::operator[](int i) const {
    return ArrayDb::operator[](i);
}

std::istream &operator>>(std::istream &is, Student &stu) {
    is>>(string &)stu;
    return is;
}

std::istream &getline(std::istream &is, Student &stu) {
    getline(is,(string&)stu);
    return is;
}

std::ostream &operator<<(std::ostream &os, Student &stu) {
    os<<"Score for "<<stu.Name()<<"\n:";
    stu.arr_out(os);
    return os;
}

std::ostream &Student::arr_out(std::ostream &os) const {
    int i;
    int lim = ArrayDb::size();
    if(lim>0)
    {
        for (i = 0;i<lim;i++)
        {
            os<<ArrayDb::operator[](i)<<" ";
            if(i % 5 == 4)
                os<<endl;
        }
        if(i%5 == 0)
            os<<endl;
    } else os<<" empty array";
    return os;
}
