#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mb emplace_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll mod = 1000000007;
//const ll mod = 998244353;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vpii = vector<pair<int, int>>;
using pii = pair<int, int>;
#define go(x) int t; cin >> t; while(t--) x();
template<typename T>
void db(T& x) { cout << x; }
template<typename T>
void db(vector<T>& v) { cout << "[";for (auto& x : v) cout << (&x == &v[0] ? "" : ",") << x;cout << "]"; }
template<typename T>
void db(vector<vector<T>>& v) { cout << endl;for (auto& i : v) { db(i);cout << endl; } }
template<typename T>
void debug(char* name, T& x) { cout << "debug: " << name << " = ";db(x);cout << endl; }
#define db(x) debug(#x, x)
//sort(a.begin(), a.end(), greater<>());
//sort(all(a), [](vi &a, vi &b) {return a[0] < b[0];});
//priority_queue<int, vi, greater<int>> pq;
//struct cmp {bool operator()(int a, int b) {return a > b;}};
//priority_queue<int, vi, cmp> pq;
//int m;cin >> m;cin.ignore();while(m--){string line;getline(cin, line);stringstream ss(line);int x;while(ss >> x){}}不定输入
//<<setw(n)右对齐字符宽度n <<left<<setw(n)左对齐宽度n <<fixed<< setprecision(n)保留n位小数


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
vi nyb;
void initny(ll n){//线性求逆元
    nyb.assign(n, 0);
    nyb[1] = 1;
    for (ll i = 2; i < n; ++i) {
        nyb[i] = (mod - (mod / i) * nyb[mod % i] % mod) % mod;
    }
}
vi jcb, jcnyb;
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
        nodes.mb();
    }
    void insert(const string& word) {
        int i = 0;
        for (char c : word) {
            c -= 'a';
            if (nodes[i].next[c] == 0) {
                nodes[i].next[c] = nodes.size();
                nodes.mb();
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
    int n;vi tree;
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
    int n;vvi st;vi log;
    ST(const vi& v) {
        n = v.size() - 1;
        int maxlog = 20;
        st.assign(n + 1, vi(maxlog + 1));
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
    vi tree, lazy;
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


void solve() {
    //cout << "---------------" << endl;
    


}


/*

*/


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    //initny(MAXN);
    //initjc(MAXN);
    //initp(MAXN);
    go(solve);
    //solve();
    return 0;
}
