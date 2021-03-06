#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

template <typename T>
class UnionFind{
    public:
        int n;
        vector<T> p, rank;

        UnionFind(int n)
            : n(n), p(n+1, -1), rank(n+1) {}

        int find(int v){
            if(p[v] == -1){
                return v;
            }
            p[v] = find(p[v]);
            return p[v];
        }

        bool unite(int u, int v){
            u = find(u);
            v = find(v);

            if(u == v){
                return false;
            }

            if(rank[u] < rank[v]){
                swap(u, v);
            }

            if(rank[u] == rank[v]){
                rank[u]++;
            }

            p[v] = u;
            return true;
        }

        bool same(int u, int v){
            u = find(u);
            v = find(v);
            return u == v;
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, W;
    cin >> n >> m >> W;
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    UnionFind<int> uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a, b);
    }

    vector<int> ww(n), vv(n);
    rep(i, n){
        int x = uf.find(i);
        ww[x] += w[i];
        vv[x] += v[i];
    }

    vector<int> dp(W + 1, -1);
    dp[0] = 0;
    rep(i, n){
        vector<int> tmp(W + 1, -1);
        rep(j, W + 1){
            tmp[j] = max(tmp[j], dp[j]);
            if(dp[j] == -1){
                continue;
            }
            if(j + ww[i] > W){
                continue;
            }
            tmp[j+ww[i]] = max(dp[j+ww[i]], dp[j] + vv[i]);
        }
        dp = tmp;
    }

    int ans = 0;
    rep(i, W + 1){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}
