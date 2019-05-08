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

    int n;
    cin >> n;
    vector<int> a(n);
    auto cnt = initVec2<int>(n + 1, 30);
    rep(i, n){
        cin >> a[i];
        int m = a[i];
        rep(j, 30){
            cnt[i+1][j] = cnt[i][j] + (m >> j) % 2;
        }
    }

    vector<int> p2(30);
    p2[0] = 1;
    rep(i, 29){
        p2[i+1] = p2[i] * 2;
    }

    int x = 0;
    rep(i, n){
        x ^= a[i];
        int sum = x * (i + 1);
        rep(j, 30){
            if((x >> j) % 2){
                sum -= cnt[i+1][j] * p2[j];
            }else{
                sum += cnt[i+1][j] * p2[j];
            }
        }
        cout << sum << endl;
    }

    return 0;
}
