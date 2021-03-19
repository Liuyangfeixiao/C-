#include <iostream>
#include <vector>
using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) : shuffer(4, 0){
        shuffer[1] = big;
        shuffer[2] = medium;
        shuffer[3] = small;
    }
    
    bool addCar(int carType) {
        if (shuffer[carType]) {
            shuffer[carType]--;
            return true;
        }
        return false;
    }
private:
    vector<int> shuffer;
};