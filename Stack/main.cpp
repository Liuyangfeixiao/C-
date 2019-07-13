#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

const int Num = 10;
int main() {
    std::srand(std::time(0)); //随机
    std::cout<<"Please enter the stack size: ";
    int stacksize;
    std::cin>>stacksize;
    Stack<const char*> st(stacksize);
//    in basket
    const char *in[Num] = {"1: HG","2: KI",
                           "3: BR","4: IF",
                           "5: WK","6: PK",
                           "7: JA","8: XP",
                           "9: JM","10: MM"};
    const char *out[Num];
    int nextin = 0;
    int processed = 0;
    while (processed < Num)
    {
        if(st.isEmpty())
            st.push(in[nextin++]);
        else if(st.isFull())
            st.pop(out[processed++]);
        else if(std::rand()%2 && nextin < Num)  //百分之五十的几率
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    for (int i = 0; i < Num; ++i) {
        std::cout<< out[i]<<std::endl;
    }
    std::cout<<"Bye!\n";
    return 0;
}