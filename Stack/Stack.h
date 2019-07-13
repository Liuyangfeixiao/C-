//
// Created by HP on 2019/7/7.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
template <class Type>

class Stack {
private:
    enum {SIZE = 10};
    int stackSize;
    Type* items;
    int top;
public:
    explicit Stack(int ss = SIZE); //阻止隐式转换
    Stack(const Stack& st); //复制构造函数
    ~Stack(){delete []items;}
    bool isEmpty(){ return top == 0;}
    bool isFull() { return top == stackSize;}
    bool push(const Type& item);
    bool pop(Type& item);
    Stack&operator=(const Stack& st);

};

template<class Type>
Stack<Type>::Stack(const Stack &st) {
    stackSize = st.stackSize;
    top = st.top;
    items = new Type[stackSize];
    for (int i = 0; i <top ; ++i) {
        items[i] = st.items[i];
    }
}

template<class Type>
Stack<Type>::Stack(int ss): stackSize(ss), top(0) {
    items = new Type[stackSize];
}

template<class Type>
bool Stack<Type>::push(const Type &item) {
    if(top < stackSize)
    {
        items[top++] = item;
        return true;
    } else
    return false;
}

template<class Type>
bool Stack<Type>::pop(Type &item) {
    if(top > 0) {
        item = items[--top];
        return true;
    }
    return false;
}

template<class Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &st) {
    if(this = &st)
        return *this;
    delete [] items;
    stackSize = st.stackSize;
    top = st.top;
    items = new Type [stackSize];
    for (int i = 0; i <top ; ++i) {
        items[i] = st.items[i];
    }
    return *this;
}


#endif //STACK_STACK_H
