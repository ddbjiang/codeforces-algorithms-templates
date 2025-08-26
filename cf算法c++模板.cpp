#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mb emplace_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll mod = 1000000007;
//const ll mod = 998244353;
const int MAXN = 10000007;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vvi = vector<vector<int> >;
using vvl = vector<vector<ll> >;
using vvvi = vector<vector<vector<int>>>;
using vvvl = vector<vector<vector<ll>>>;
using vpii = vector<pair<int, int> >;
using vpll = vector<pair<ll, ll> >;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define go(x) int t; cin >> t; while(t--) x();
template<typename T>
void db(const T& x) { cout << "debug: " << x << endl; }
template<typename T>
void db(const vector<T>& v) { cout << "debug(1): "; for (const auto& i : v)cout << i << " "; cout << endl; }
template <typename T>
void db(const vector<vector<T>>& v) { cout << "debug(2): " << endl; for (const auto& i : v) { db(i); } }
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
ll ny(ll x) {
    return ksm(x, mod - 2);
}
vi minp, primes;
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
void initny(int n){
    nyb.assign(n, 0);
    nyb[1] = 1;
    for (int i = 2; i < n; ++i) {
        nyb[i] = (mod - (ll)(mod / i) * nyb[mod % i] % mod) % mod;
    }
}
vl jcb, jcnyb;
void initjc(int n) {
    jcb.assign(n + 1, 1);
    jcnyb.assign(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        jcb[i] = jcb[i - 1] * i % mod;
    }
    jcnyb[n] = ny(jcb[n]);
    for (int i = n - 1; i >= 0; --i) {
        jcnyb[i] = jcnyb[i + 1] * (i + 1) % mod;
    }
}
inline ll C(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return jcb[n] * jcnyb[k] % mod * jcnyb[n - k] % mod;
}
inline ll A(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return jcb[n] * jcnyb[n - k] % mod;
}
int find(vi& root, int x) {
    if (root[x] == x)return x;
    return root[x] = find(root, root[x]);
}
struct Trie {
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
struct SegTree {//1-idx
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
        return max(query(v*2, l, mid, ql, qr),
                   query(v*2+1, mid+1, r, ql, qr));
    }
    void update(int l, int r, ll val) {
        update(1, 1, n, l, r, val);
    }
    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};


void solve() {
    //db("-----------");
    

    
}


/*



*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    //initjc(MAXN);
    //initp(MAXN);
    //initny(MAXN);
    go(solve);
    //solve();
    return 0;
}
