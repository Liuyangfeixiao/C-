//
// Created by HP on 2019/6/11.
//

#ifndef LIST_LLIST_H
#define LIST_LLIST_H

#include "List.h"
template <typename E>
class LList: public List<E> {
    List<E>* head;
    List<E>* tail;
    List<E>* curr;
    int cnt;
    void init() {
     curr = tail = head = new List<E>;
     cnt = 0;
    }

    void removeAll() {
        while (head!= nullptr)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(int size = 10){init();}
    ~LList(){removeAll();}
    void print() const ;
    void clear(){ removeAll();init();}
//    Insert "it" at current position
    void Insert(const E& it) {
        curr->next = new List<E>(it,curr->next);
        if(tail==curr)


    }


};




#endif //LIST_LLIST_H
