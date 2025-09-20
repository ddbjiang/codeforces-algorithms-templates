#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int l, int r) {
    static mt19937_64 gen(time(0));
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

signed main() {
	int t=f(1,1);
	cout<<t<<endl;
	while (t--) {
		int n = f(1, 1e3);
		cout << n << endl;
		for (int i = 0;i < n;i++) {
			int x = f(1, 1e9);
			cout << x << " ";
		}
		cout << endl;
	}
    return 0;
}
