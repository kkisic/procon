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
class SegmentTree{
    private:
        static int calc_size(int n){
            int m = 1;
            while(m < n){
                m *= 2;
            }
            return m;
        }

        T query(int s, int t, int i, int l, int r) const {
            if(r <= s || t <= l){
                return init;
            }

            if(s <= l && r <= t){
                return node[i];
            }

            int m = l + (r - l) / 2;
            T vl = query(s, t, i * 2 + 1, l, m);
            T vr = query(s, t, i * 2 + 2, m, r);
            return f(vl, vr);
        }

    public:
        int n;
        vector<T> node;
        T init;
        function<T(T, T)> f;

        SegmentTree(int n, T init, function<T(T, T)> f)
            : n(calc_size(n)), node(calc_size(n) * 2, init), init(init), f(f){}

        void update(int i, const T& x){
            i += (n - 1);
            node[i] = x;
            while(i > 0){
                i = (i - 1) / 2;
                node[i] = f(node[2*i+1], node[2*i+2]);
            }
        }

        //[s, t)
        T query(int s, int t) const {
            return query(s, t, 0, 0, n);
        }
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n - 1) cin >> c[i];
    vector<int> r(n+1), l(n+1);
    for(int i = 1; i < n; i++){
        r[i] = r[i-1] + c[i-1];
    }
    for(int i = n - 1; i > 0; i--){
        l[i] = l[i+1] + c[i-1];
    }
    r[n] = l[0] = -INF;

    SegmentTree<int> rst(n+1, -INF, [](int a, int b){return max(a, b);});
    SegmentTree<int> lst(n+1, -INF, [](int a, int b){return max(a, b);});
    rep(i, n + 1){
        rst.update(i, r[i]);
        lst.update(i, l[i]);
    }

    rep(i, n){
        int ans = 0;
        ans = max(ans, rst.query(i, n) - r[i]);
        ans = max(ans, lst.query(0, i + 1) - l[i+1]);
        cout << ans << endl;
    }

    return 0;
}
