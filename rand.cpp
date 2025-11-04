#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;

int f(int l, int r) {
    static mt19937_64 gen(time(0));
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

signed main() {
    int t = f(1, 1);
    cout << t << endl;
    while (t--) {
        int n = f(10, 10);cout << n << endl;
    }
    return 0;
}
