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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    auto a = initVec2<int>(n, m);
    auto b = initVec2<int>(n, m);
    rep(i, n) rep(j, m) cin >> a[i][j];
    rep(i, n) rep(j, m) cin >> b[i][j];

    vector<map<int, int>> sa(n + m, map<int, int>());
    vector<map<int, int>> sb(n + m, map<int, int>());
    rep(i, n){
        rep(j, m){
            sa[i+j][a[i][j]]++;
            sb[i+j][b[i][j]]++;
        }
    }

    rep(i, n + m){
        for(P p : sa[i]){
            if(sb[i][p.first] != p.second){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}
