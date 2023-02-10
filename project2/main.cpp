#include <iostream>
#include "usecase.cpp"

int main (){
    int numss[1] = {1};
    string ans = sliding_window(numss,1,1);
    if(ans != "1"){
        cout << "Error"<<endl;
    }
     int num[8] = {8,7,6,5,4,3,2,1};
     ans = sliding_window(num,8,4);
     //cout << ans <
     if(ans != "5 4 3 2 1"){
        cout << "Error"<<endl;
     }
}