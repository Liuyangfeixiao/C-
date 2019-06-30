//
// Created by HP on 2019/6/11.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

template <typename E>
class List {
public:
    E element;
    List* next;
    List(const E& elemval,List* nextval = nullptr)
    { element = elemval; next = nextval;}
    List(List* nextval = nullptr){next = nextval;}

};


#endif //LIST_LIST_H
