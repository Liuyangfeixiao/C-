#include<iostream>
#include<cstring>
using namespace std;
#define I 1;
#define V 5;
#define X 10;
#define L 50;
#define C 100;
#define D 500;
#define M 1000;
int romanToInt(string s) 
{
        int sum = 0;
        for (int i=0; i<s.length()-1; i++)
        {
            if(s[i]<s[i+1])
                sum = sum- s[i];
            else 
            sum = sum + s[i];
            
            
        }
        return sum;
    }
};
int main()
{
   string s;
   cin>>s;
   cout<<romanToInt(s);
   return 0;
   
}