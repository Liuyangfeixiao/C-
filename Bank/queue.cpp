//
// Created by HP on 2019/6/20.
//

#include "queue.h"
#include <cstdlib>
Queue::Queue(int qs): qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node* temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }

}
bool Queue::isEmpty() const
{
    return items == 0;
}

bool Queue::isFull() const
{
    return items == qsize;
}
int Queue::queueCount() const
{
    return items;
}

// Add item to a queue
bool Queue::enQueue(const Item& item)
{
    if(isFull())
        return false;
    Node* add = new Node;
    if(add == nullptr)
        return false;
    add->item = item;
    add->next = nullptr;
    items++;
    if(front == nullptr)
        front = add;
    else
    {
        rear->next = add;
    }
    rear = add;
    return true;
}

bool Queue::deQueue(Item& item)
{
    if(isEmpty())
        return false;
    item = front->item;
    Node* temp = front;
    front = front->next;
    delete temp;
    items--;
    if(items == 0)
        rear = nullptr;
    return true;

}

void Customer::set(long when)
{
    processtime = std::rand()%3 + 1;
    arrive = when;
}