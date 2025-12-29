#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
using ll = long long;using ull = unsigned long long;using ld = long double;using i128 = __int128;using u128 = unsigned __int128;
using vi = vector<int>;using vl = vector<ll>;using vvi = vector<vi>;using vvl = vector<vl>;using vvvi = vector<vvi>;using vvvl = vector<vvl>;
using vd = vector<double>;using vs = vector<string>;using pii = pair<int, int>;using vpii = vector<pii>;
using si = set<int>;using msi = multiset<int>;using mii = map<int, int>;
using ar3 = array<int, 3>;using ar4 = array<int, 4>;using ar5 = array<int, 5>;
const ll mod = 1000000007;//const ll mod = 998244353;
const double PI = acos(-1.0), EPS = 1e-9;
template<class T> void debug(const T& x) { cout << x; }
template<class T> void debug(const vector<T>& v) { cout << "[";for (int i = 0, n = v.size();i < n;i++)cout << v[i] << ",]"[i + 1 == n]; }
template<class T> void debug(const vector<vector<T>>& v) { cout << endl;for (const auto& i : v) { debug(i);cout << endl; } }
template<class T> void debug(const set<T>& st) { debug(vector<T>(all(st))); }
template<class T> void debug(const multiset<T>& st) { debug(vector<T>(all(st))); }
template<class T> void debug(stack<T> stk) { vector<T> v;while (stk.size()) v.pb(stk.top()), stk.pop(); debug(v); }
template<class T> void debug(queue<T> q) { vector<T> v;while (q.size()) v.pb(q.front()), q.pop(); debug(v); }
template<class T> void debug(const deque<T>& d) { debug(vector<T>(all(d))); }
template<class T, class C, class Comp> void debug(const priority_queue<T, C, Comp>& p) { auto q = p; vector<T> v; while (!q.empty()) v.pb(q.top()), q.pop(); debug(v); }
template<class K, class V> void debug(const vector<pair<K, V>>& vp) { vs a;for (auto& [k, v] : vp) a.pb("[" + to_string(k) + "," + to_string(v) + "]"); debug(a); }
template<class K, class V> void debug(const map<K, V>& m) { vs a;for (auto& [k, v] : m) a.pb("[" + to_string(k) + "->" + to_string(v) + "]"); debug(a); }
template<class T> void debug(const char* name, const T& x) { cout << "debug: " << name << " = "; debug(x); cout << endl; }
#define db(x) debug(#x, x)
void rd(vi& a) { for (int& i : a)cin >> i; }
void out(vi& a) { for (int i = 0, n = a.size();i < n;i++)cout << a[i] << " \n"[i + 1 == n]; }

void solve() {



}

/*

*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "----Test " << i << "----" << endl;
        solve();
    }
    return 0;
}
