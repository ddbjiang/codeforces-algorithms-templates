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

//sort(all(a), [](vi a, vi b) {return a[0] < b[0];});lambda表达式
//int t;cin >> t;cin.ignore();while (t--) {string line;getline(cin, line);stringstream ss(line);int x;while (ss >> x) {}}不定输入
//<<setw(n)右对齐字符宽度n <<left<<setw(n)左对齐宽度n <<fixed<< setprecision(n)保留n位小数
// priority_queue<node>pq;默认最大堆跟排序相反，重载小于号决定优先级
// priority_queue<int> pq;最大堆
// priority_queue<int, vi, greater<int>> pq;最小堆

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
vl jcb, jcnyb;
void initjc(ll n) {//依赖ny,ksm
    jcb.assign(n + 1, 1);
    jcnyb.assign(n + 1, 1);
    for (ll i = 1; i <= n; i++) {
        jcb[i] = jcb[i - 1] * i % mod;
    }
    jcnyb[n] = ny(jcb[n]);
    for (ll i = n - 1; i >= 0; i--) {
        jcnyb[i] = jcnyb[i + 1] * (i + 1) % mod;
    }
}
vl nyb;
void initny(ll n) {//线性求逆元
    nyb.assign(n, 0);
    nyb[1] = 1;
    for (ll i = 2; i < n; ++i) {
        nyb[i] = (mod - (mod / i) * nyb[mod % i] % mod) % mod;
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
ll Lucas(ll n, ll k) {//mod小于1e6,预处理initjc(mod - 1);适用C和A
    if (k == 0) return 1;
    return C(n % mod, k % mod) * Lucas(n / mod, k / mod) % mod;
}
int find(vi& root, int x) {//并查集简洁写法
    if (root[x] == x)return x;
    return root[x] = find(root, root[x]);
}
struct Trie {//字符串字典树
    struct Node {
        int next[26];
        int cnt;
        Node() {
            memset(next, -1, sizeof(next));
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
            if (nodes[i].next[c] == -1) {
                nodes[i].next[c] = nodes.size();
                nodes.emplace_back();
            }
            i = nodes[i].next[c];
            nodes[i].cnt++;
        }
    }
    void erase(const string& word) {
        int i = 0;
        for (char c : word) {
            c -= 'a';
            i = nodes[i].next[c];
            nodes[i].cnt--;
        }
    }
    ll find(const string& s) {
        int i = 0;
        ll sum = 0;
        for (char c : s) {
            c -= 'a';
            if (nodes[i].next[c] == -1 || nodes[nodes[i].next[c]].cnt == 0) return 0;
            i = nodes[i].next[c];
            sum += nodes[i].cnt;
        }
        return sum;
    }
};

struct Trie2 {//01字典树，处理最大异或和
    struct Node {
        int next[2];int cnt;
        Node() {
            memset(next, -1, sizeof(next));
            cnt = 0;
        }
    };
    vector<Node> nodes;
    Trie2() {
        nodes.emplace_back();
    }
    void insert(int x) {
        int i = 0;
        for (int b = 31; b >= 0; b--) {
            int c = (x >> b) & 1;
            if (nodes[i].next[c] == -1) {
                nodes[i].next[c] = nodes.size();
                nodes.emplace_back();
            }
            i = nodes[i].next[c];
            nodes[i].cnt++;
        }
    }
    void erase(int x) {
        int i = 0;
        for (int b = 31; b >= 0; b--) {
            int c = (x >> b) & 1;
            i = nodes[i].next[c];
            nodes[i].cnt--;
        }
    }
    int find(int x) {
        int i = 0;
        int sum = 0;
        for (int b = 31; b >= 0; b--) {
            int c = (x >> b) & 1;
            int t = c ^ 1;
            if (nodes[i].next[t] != -1 && nodes[nodes[i].next[t]].cnt > 0) {
                sum |= (1 << b);
                i = nodes[i].next[t];
            }
            else {
                i = nodes[i].next[c];
            }
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
struct ST {//1-idx,(max,min,gcd,lcm,&,|,minidx,maxidx,idx存pii)
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
struct SegTree {//1-idx,(max,min,sum,*,^,gcd,lcm,|,&)
    struct tnode {
        ll val;
        bool zero;
        tnode() {
            //val = -4e18;//max
            //val = 4e18;//min
            val = 0;//sum
            zero = true;
        }
        tnode(ll v) {
            val = v;zero = false;
        }
        friend tnode operator+(const tnode& a, const tnode& b) {
            if (a.zero) return b;
            if (b.zero) return a;
            tnode res;
            res.zero = false;
            //能区间更新
            res.val = a.val + b.val;            // sum
            //res.val = max(a.val, b.val);        // max
            //res.val = min(a.val, b.val);        // min
            //res.val = (a.val * b.val) % mod;    // *
            //res.val = a.val ^ b.val;            // ^
            //不能区间更新
            //res.val = gcd(a.val, b.val);        // gcd
            //ll g = gcd(a.val, b.val);
            //res.val = (a.val / g) * b.val;      // lcm
            //但支持区间^,|,&
            //res.val = a.val | b.val;            // |
            //res.val = a.val & b.val;            // &
            return res;
        }
    };
    int n;
    vector<tnode> tree;
    vl lazyadd;
    //vl lazyset;
    //vl lazymul;
    SegTree(int size) {
        n = size;
        tree.assign(4 * n + 1, tnode());
        lazyadd.assign(4 * n + 1, -4e18);
        //lazyset.assign(4 * n + 1, -4e18);
        //lazymul.assign(4 * n + 1, -4e18);
        vl a(n + 1);
        build(a, 1, 1, n);
    }
    SegTree(const vl& a) {
        n = (int)a.size() - 1;
        tree.assign(4 * n + 1, tnode());
        lazyadd.assign(4 * n + 1, -4e18);
        //lazyset.assign(4 * n + 1, -4e18);
        //lazymul.assign(4 * n + 1, -4e18);
        build(a, 1, 1, n);
    }
    void build(const vl& v, int idx, int l, int r) {
        if (l == r) {
            tree[idx] = tnode(v[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(v, idx * 2, l, mid);
        build(v, idx * 2 + 1, mid + 1, r);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
    void apply(int idx, int l, int r, ll add) {
        int len = r - l + 1;
        //区间增加
        if (add == -4e18) return;
        tree[idx].val += add * len;//sum加上*len
        tree[idx].zero = false;
        if (lazyadd[idx] == -4e18) {
            lazyadd[idx] = add;
        }
        else {
            lazyadd[idx] += add;
        }
        //区间赋值
        // if (setval != -4e18) {
        //     tree[idx].val = setval;//sum加上*len
        //     lazyset[idx] = setval;
        //     lazyadd[idx] = 0;
        // }
        // if (add != -4e18) {
        //     tree[idx].val += add;//sum加上*len
        //     if (lazyset[idx] != -4e18) lazyset[idx] += add;
        //     else {
        //         if (lazyadd[idx] == -4e18) lazyadd[idx] = add;
        //         else lazyadd[idx] += add;
        //     }
        // }
        //区间乘加maxmin
        // val = val * k;lazymul = lazymul * k;
        // val = val + add;lazyadd = lazyadd + b;//sum add加上*len
    }
    void push(int idx, int l, int r) {
        if (lazyadd[idx] != -4e18) {
            int mid = (l + r) / 2;
            apply(idx * 2, l, mid, lazyadd[idx]);
            apply(idx * 2 + 1, mid + 1, r, lazyadd[idx]);
            lazyadd[idx] = -4e18;
            //lazymul[idx] = -4e18;
        }
    }
    void update(int idx, int l, int r, int ul, int ur, ll val) {
        if (ul <= l && r <= ur) {
            apply(idx, l, r, val);
            return;
        }
        push(idx, l, r);
        int mid = (l + r) / 2;
        if (ul <= mid) update(idx * 2, l, mid, ul, ur, val);
        if (ur > mid) update(idx * 2 + 1, mid + 1, r, ul, ur, val);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
    tnode query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[idx];
        push(idx, l, r);
        int mid = (l + r) / 2;
        tnode res;
        if (ql <= mid) res = res + query(idx * 2, l, mid, ql, qr);
        if (qr > mid) res = res + query(idx * 2 + 1, mid + 1, r, ql, qr);
        return res;
    }
    void update(int l, int r, ll val) { update(1, 1, n, l, r, val); }
    ll query(int l, int r) { return query(1, 1, n, l, r).val; }
};


void solve() {


}

/*

*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    //int MAXN = 2e5 + 10;
    //initp(MAXN);
    //initjc(MAXN);
    //initny(MAXN);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        //cout << "----Test " << i << "----" << endl;
        solve();
    }
    return 0;
}
