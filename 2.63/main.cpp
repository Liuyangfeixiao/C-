#include <iostream>
#include <bitset>
#include <climits>
int w = 8* sizeof(int);
using namespace std;
unsigned srl(unsigned x, int k)
{
        unsigned xrsa = (int)x>>k; //算数右移
        int sign = ((int)x >= 0) ? 0:1; //判断x符号，为负则sign = 1,否则sign = 0
        xrsa -= (unsigned)(-sign&(-1 << (w-k)));//将-1的前k位置1，其他位置0，并判断是否需要替代 xrsa 的前k位
        return xrsa;

}
int sra(int x, int k)
{
    int xsrl = (unsigned) x>>k; //逻辑右移
    int sign = (x >= 0) ? 0:1;//判断x符号，为负则sign = 1,否则sign = 0
    xsrl += (int)(-sign&(-1<<(w-k)));//将-1的前k位置1，其他位置0，并判断是否需要替代 xrsl 的前k位
    return xsrl;
}
void printLinbry(unsigned x){
    cout << bitset<sizeof(x)*8>(x)<<endl;//输出x的32位2进制形式
}
int main() {
    int enterNum;
    unsigned num ;
    cout << "Please enter the x: \n";
    cin >> num;
    printLinbry(num);
    cout<<"Please enter the k\n";
    cin >> enterNum;
    unsigned result = srl(num, enterNum);
    printLinbry(result);
    cout << "____________________________"<<endl;
    int Result = sra(num,enterNum);
    cout << bitset<sizeof(int)*8>(Result)<<endl;
    return 0;
}