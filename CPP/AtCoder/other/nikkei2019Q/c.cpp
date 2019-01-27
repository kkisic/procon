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

bool compare(pair<P, int> a, pair<P, int> b){
    if(a.first.first != b.first.first){
        return a.first.first > b.first.first;
    }
    return a.first.second < b.first.second;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n){
        cin >> a[i] >> b[i];
    }

    vector<P> aa, bb;
    rep(i, n){
        aa.emplace_back(a[i] + b[i], i);
    }
    sort(ALL(aa), greater<P>());

    int ans = 0;
    rep(i, n){
        if(i % 2 == 0){
            ans += a[aa[i].second];
        }else{
            ans -= b[aa[i].second];
        }
    }
    cout << ans << endl;

    return 0;
}