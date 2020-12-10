#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool lemonadeChange(vector<int>& billis) {
    int n = billis.size();
    if (n == 0) return true;
    vector<int> bill(3, 0);
    for (int x : billis) {
        if (x == 5) {
            bill[0]++;
            continue;
        }
        else if (x == 10)
        {
            if (bill[0] != 0){
                bill[0]--;
                bill[1]++;
            }
            else return false;
        }
        else {
            if (bill[0] && bill[1]){
                bill[0]--;
                bill[1]--;
                bill[2]++;
            }
            else if (bill[0] >= 3){
                bill[0] -= 3;
                bill[2]++;
            }
            else return false;
        }
    }
    return true;
}