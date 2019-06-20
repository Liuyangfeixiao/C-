//
// Created by HP on 2019/6/20.
//

#ifndef BANK_QUEUE_H
#define BANK_QUEUE_H


class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer(){arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}



};

typedef Customer Item;

class Queue
{
private:
    // Node is a nested structure local to this class
    struct Node
    {
        Item item;
        struct Node* next;
    };
    enum{Q_size = 10};
    // private class members
    Node* front;
    Node* rear;
    int items;
    const int qsize;
    // preemptive definition to prevent public copying
    Queue(const Queue& q): qsize(0){}
    Queue& operator=(const Queue& q) {return *this;}
public:
    Queue(int qs = Q_size);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queueCount() const;
    bool enQueue(const Item& item); //insert item to end
    bool deQueue(Item& item); //remove item from the front
};


#endif //BANK_QUEUE_H
