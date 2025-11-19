#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
#define pb push_back
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvvi = vector<vector<vector<int>>>;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;
using si = set<int>;
using msi = multiset<int>;
using mii = map<int, int>;
using tiii = tuple<int, int, int>;
const ll mod = 1000000007;
//const ll mod = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-9;
template<class T> void out(const T& a) { for (int i = 0, n = a.size();i < n;i++)cout << a[i] << " \n"[i + 1 == n]; }
template<class T> void debug(const T& x) { cout << x; }
template<class T> void debug(const vector<T>& v) { cout << "[";for (int i = 0, n = v.size();i < n;i++)cout << v[i] << ",]"[i + 1 == n]; }
template<class T> void debug(const vector<vector<T>>& v) { cout << endl;for (const auto& i : v) { debug(i);cout << endl; } }
template<class T> void debug(const set<T>& st) { debug(vector<T>(all(st))); }
template<class T> void debug(const multiset<T>& st) { debug(vector<T>(all(st))); }
template<class T> void debug(stack<T> stk) { vector<T> v;while (stk.size()) v.pb(stk.top()), stk.pop(); debug(v); }
template<class T> void debug(queue<T> q) { vector<T> v;while (q.size()) v.pb(q.front()), q.pop(); debug(v); }
template<class T> void debug(const deque<T>& d) { debug(vector<T>(all(d))); }
template<class T> void debug(priority_queue<T> pq) { vector<T> v;while (pq.size()) v.pb(pq.top()), pq.pop(); debug(v); }
template<class K, class V> void debug(const vector<pair<K, V>>& vp) { vs a;for (auto& [k, v] : vp) a.pb("[" + to_string(k) + "," + to_string(v) + "]"); debug(a); }
template<class K, class V> void debug(const map<K, V>& m) { vs a;for (auto& [k, v] : m) a.pb("[" + to_string(k) + "->" + to_string(v) + "]"); debug(a); }
template<class T> void debug(const char* name, const T& x) { cout << "debug: " << name << " = "; debug(x); cout << endl; }
#define db(x) debug(#x, x)
//sort(all(a), [](vi a, vi b) {return a[0] < b[0];});lambda表达式
//int m;cin >> m;cin.ignore();while(m--){string line;getline(cin, line);stringstream ss(line);int x;while(ss >> x){}}不定输入
//<<setw(n)右对齐字符宽度n <<left<<setw(n)左对齐宽度n <<fixed<< setprecision(n)保留n位小数
// struct aa {
//     int x, y;
//     bool operator<(const aa& o) const {
//         if (x == o.x) return y < o.y;
//         return x < o.x;
//     }
// };
// priority_queue<aa>pq;默认最大堆跟排序相反，重载小于号决定优先级
// priority_queue<int> pq;最大堆
// priority_queue<int, vi, greater<int>> pq;最小堆
ll ksm(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}
ll ny(ll x) {//依赖ksm
    return ksm(x, mod - 2);
}
vi minp, primes;//最小质因数等于自身为质数，小于等于n的全部质数
void initp(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (const int& p : primes) {
            if (i * p > n)break;
            minp[i * p] = p;
            if (p == minp[i])break;
        }
    }
}
vl nyb;
void initny(ll n){//线性求逆元
    nyb.assign(n, 0);
    nyb[1] = 1;
    for (ll i = 2; i < n; ++i) {
        nyb[i] = (mod - (mod / i) * nyb[mod % i] % mod) % mod;
    }
}
vl jcb, jcnyb;
void initjc(ll n) {//依赖ny,ksm
    jcb.assign(n + 1, 1);
    jcnyb.assign(n + 1, 1);
    for (ll i = 1; i <= n; ++i) {
        jcb[i] = jcb[i - 1] * i % mod;
    }
    jcnyb[n] = ny(jcb[n]);
    for (ll i = n - 1; i >= 0; --i) {
        jcnyb[i] = jcnyb[i + 1] * (i + 1) % mod;
    }
}
inline ll C(ll n, ll k) {//依赖initjc
    if (k < 0 || k > n) return 0;
    return jcb[n] * jcnyb[k] % mod * jcnyb[n - k] % mod;
}
inline ll A(ll n, ll k) {//依赖initjc
    if (k < 0 || k > n) return 0;
    return jcb[n] * jcnyb[n - k] % mod;
}
ll Lucas(ll n, ll k) {//mod小于1e6
    if (k == 0) return 1;
    return C(n % mod, k % mod) * Lucas(n / mod, k / mod) % mod;
}
int find(vi& root, int x) {//并查集简洁写法
    if (root[x] == x)return x;
    return root[x] = find(root, root[x]);
}
struct Trie {//常数较大
    struct Node {
        int next[26];int cnt;
        Node() {
            memset(next, 0, sizeof(next));
            cnt = 0;
        }
    };
    vector<Node> nodes;
    Trie() {
        nodes.emplace_back();
    }
    void insert(const string& word) {
        int i = 0;
        for (char c : word) {
            c -= 'a';
            if (nodes[i].next[c] == 0) {
                nodes[i].next[c] = nodes.size();
                nodes.emplace_back();
            }
            i = nodes[i].next[c];
            nodes[i].cnt++;
        }
    }
    ll find(const string& s) {
        int i = 0;
        int sum = 0;
        for (char c : s) {
            c -= 'a';
            if (nodes[i].next[c] == 0) {
                return 0;
            }
            i = nodes[i].next[c];
            sum += nodes[i].cnt;
        }
        return sum;
    }
};
struct Treea {//1-idx
    int n;vl tree;
    Treea(int size) {
        n = size;tree.assign(n + 1, 0);
    }
    void update(int i, ll t) {
        while (i <= n) {
            tree[i] += t;
            i += i & (-i);
        }
    }
    ll sum(int i) {
        ll sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }
};
struct ST {//1-idx,(max,min,gcd,lcm,&,|,minidx,maxidx)
    int n;vvl st;vl log;
    ST(const vl& v) {
        n = v.size() - 1;
        int maxlog = 20;
        st.assign(n + 1, vl(maxlog + 1));
        log.assign(n + 2, 0);
        for (int i = 2; i <= n; i++) {
            log[i] = log[i >> 1] + 1;
        }
        for (int i = 1; i <= n; i++) {
            st[i][0] = v[i];
        }
        for (int j = 1; j <= maxlog; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }
    int query(int l, int r) {
        int j = log[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
struct SegTree {//1-idx,(sum,max,min,gcd,lcm,乘积,|,&,^)
    int n;
    vl tree, lazy;
    SegTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void push(int v, int l, int r) {
        if (lazy[v] != 0) {
            tree[v] += lazy[v];
            if (l != r) {
                lazy[v*2] += lazy[v];
                lazy[v*2+1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }
    void update(int v, int l, int r, int ul, int ur, ll val) {
        push(v, l, r);
        if (ul > r || ur < l) return;
        if (ul <= l && r <= ur) {
            lazy[v] += val;
            push(v, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(v*2, l, mid, ul, ur, val);
        update(v*2+1, mid+1, r, ul, ur, val);
        tree[v] = max(tree[v*2], tree[v*2+1]);
    }
    ll query(int v, int l, int r, int ql, int qr) {
        push(v, l, r);
        if (ql > r || qr < l) return LLONG_MIN;
        if (ql <= l && r <= qr) return tree[v];
        int mid = (l + r) / 2;
        return max(query(v*2, l, mid, ql, qr), query(v*2+1, mid+1, r, ql, qr));
    }
    void update(int l, int r, ll val) {
        update(1, 1, n, l, r, val);
    }
    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int qry(int l, int r) {//交互
    cout << "? " << l << ' ' << r << endl;
    int x;cin >> x;
    return x;
}

void solve() {
    


}

/*

*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    //int MAXN = 2e5 + 10;
    //initny(MAXN);
    //initjc(MAXN);
    //initp(MAXN);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "----Test " << i << "----" << endl;
        solve();
    }
    return 0;
}
