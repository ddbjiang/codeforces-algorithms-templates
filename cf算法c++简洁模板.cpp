#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
#define pb push_back
#define eb emplace_back
#define pf push_front
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define up(a) iota(all(a),0)
#define so(a) sort(all(a))
#define rso(a) sort(rall(a))
using ll = long long;using ull = unsigned long long;using ld = long double;using i128 = __int128;using u128 = unsigned __int128;
using vi = vector<int>;using vl = vector<ll>;using vvi = vector<vi>;using vvl = vector<vl>;using vvvi = vector<vvi>;using vvvl = vector<vvl>;
using si = set<int>;using msi = multiset<int>;using mii = map<int, int>;
using vd = vector<double>;using vs = vector<string>;using pii = pair<int, int>;using vpii = vector<pii>;using vvpii = vector<vpii>;
using ar3 = array<int, 3>;using tiii = tuple<int, int, int>;//get<0>(t);
template<class T> void debug(const T& x) { cout << x; }
template<class T> void debug(const vector<T>& v) { cout << "[";for (int i = 0, n = v.size();i < n;i++)cout << v[i] << ",]"[i + 1 == n]; }
template<class T> void debug(const vector<vector<T>>& v) { cout << endl;for (const auto& i : v) { debug(i);cout << endl; } }
template<class T> void debug(const set<T>& st) { debug(vector<T>(all(st))); }
template<class T> void debug(const multiset<T>& st) { debug(vector<T>(all(st))); }
template<class T> void debug(stack<T> stk) { vector<T> v;while (stk.size()) v.pb(stk.top()), stk.pop(); debug(v); }
template<class T> void debug(queue<T> q) { vector<T> v;while (q.size()) v.pb(q.front()), q.pop(); debug(v); }
template<class T> void debug(const deque<T>& d) { debug(vector<T>(all(d))); }
template<class T, class C, class Cmp> void debug(const priority_queue<T, C, Cmp>& p) { auto q = p; vector<T> v; while (!q.empty()) v.pb(q.top()), q.pop(); debug(v); }
template<class K, class V> void debug(const vector<pair<K, V>>& vp) { vs a;for (auto& [k, v] : vp) a.pb("[" + to_string(k) + "," + to_string(v) + "]"); debug(a); }
template<class K, class V> void debug(const map<K, V>& m) { vs a;for (auto& [k, v] : m) a.pb("[" + to_string(k) + "->" + to_string(v) + "]"); debug(a); }
template<class T> void debug(const char* name, const T& x) { cout << "debug: " << name << " = "; debug(x); cout << endl; }
#define db(x) debug(#x, x)
void rd(vi& a) { for (int& x : a)cin >> x; }
void rd(vpii& a) { for (auto& [x, y] : a) { cin >> x >> y; } }
void rd(vs& a) { for (string& s : a)cin >> s; }
void rd(vvi& a) { for (vi& x : a)rd(x); }
void out(int x) { cout << x << endl; };
void out(string s) { cout << s << endl; };
void out(vi a) { for (int i = 0, n = sz(a);i < n;i++)cout << a[i] << " \n"[i + 1 == n]; }
void out(vpii& a) { for (auto& [x, y] : a) { cout << x << " " << y << endl; } };
string to2(ll x) { string s;while (x) { s += x % 2 + '0';x >>= 1; }reverse(all(s));return s; }
struct hash2 { size_t operator()(const ar3& a) const { return a[0] * 1000000007 + a[1] * 1000000009 + a[2] * 998244353; } };
//unordered_map<ar3, int, hash2> mp;mp.reserve(n);mp.max_load_factor(0.5);
struct node {
    int x, y;
    bool operator<(const node& o) const {
        if (x == o.x) return y < o.y;return x < o.x;
    }
};
const ll mod = 1000000007;//const ll mod = 998244353;
const ll base1 = 131, base2 = 13331, smod1 = 1e9 + 7, smod2 = 1e9 + 9;
const double pai = acos(-1.0), eps = 1e-9;
const int N = 2e5 + 10;


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
