#include <iostream>
#include "Sales.h"
int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double value1[12] = {
            1220,1100,1122,2212,1232,2334,
            2804,2393,3302,2922,3002,3544
    };
    double value2[12] = {
            12,11,22,21,32,34,
            28,29,33,29,32,35
    };
    Sales sales1(2004,value1,12);
    LabeledSales sales2("Blogstar",2005,value2,12);

    cout<<"First try block\n";
    try {
        int i;
        cout<<"Year = "<<sales1.Year()<<endl;
        for (int i = 0; i < 12; ++i) {
            cout<<sales1[i]<<" ";
            if (i%6 == 5)
                cout<<endl;
        }
        cout<<"Year = "<<sales2.Year()<<endl;
        cout<<"Label = "<<sales2.Label()<<endl;
        for (int i = 0; i <= 12; ++i) {
            cout<<sales2[i]<<" ";
            if (i % 6 == 5)
                cout<<endl;
        }
        cout<<"End of try block1 \n";
    }
    catch (LabeledSales::nbad_index & bad)
    {
        cout<<bad.what()<<endl;
        cout<<"Company: "<<bad.label_val()<<endl;
        cout<<"bad index: "<<bad.bi_val()<<endl;
    }
    catch (Sales::bad_index & bad)
    {
        cout<<bad.what()<<endl;
        cout<<"bad index: "<<bad.bi_val()<<endl;
    }
    cout<<"\nNext try block: \n";
    try {
        sales1[20] = 23345;
        sales2[2] = 37.5;
        cout<<"End of try block 2.\n";
    }
    catch (LabeledSales::nbad_index& bad)
    {
        cout<<bad.what()<<endl;
        cout<<"Company: "<<bad.label_val()<<endl;
        cout<<"bad index: "<<bad.bi_val()<<endl;
    }
    catch (Sales::bad_index& bad)
    {
        cout<<bad.what()<<endl;
        cout<<"bad index: "<<bad.bi_val()<<endl;
    }
    cout<<"done"<<endl;
    return 0;
}