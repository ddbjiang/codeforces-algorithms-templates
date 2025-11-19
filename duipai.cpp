#include <bits/stdc++.h>
using namespace std;
int main() {
    system("g++ -std=c++23 rand.cpp -o rand.exe");
    system("g++ -std=c++23 t1.cpp -o t1.exe");
    system("g++ -std=c++23 t2.cpp -o t2.exe");
    int t=1;
    while (true) {
    	cout<<"test "<<t++<<":";
        system("rand.exe > data.txt");
        system("t1.exe < data.txt > t1.txt");
        system("t2.exe < data.txt > t2.txt");
        if (system("fc t1.txt t2.txt")) {
            cout << "wa" << endl;
            cout<<"data:"<<endl;
            system("type data.txt");
            break;
        }
        else {
            cout << "ac" << endl;
        }
    }
    return 0;
}
