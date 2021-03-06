#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 998244353;

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

int factM(int n){
    static vector<int> t = {1};

    if((int)t.size() > n){
        return t[n];
    }

    for(int i = t.size(); i <= n; i++){
        t.push_back(t[i-1] * i % MOD);
    }
    return t[n];
}

int comb(const vector<int>& t, int cn, int n, int k){
    if(n < k){
        return 0;
    }
    return cn * t[k] % MOD * t[n-k] % MOD;
}

vector<int> makeTable(int n){
    vector<int> t(n+1);
    t[n] = powM(factM(n), MOD-2);

    for(int i = n-1; i >= 0; i--){
        t[i] = t[i+1] * (i+1) % MOD;
    }
    return t;
}

signed main(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<int> table = makeTable(n);

    int aa = min(a, b);
    int bb = max(a, b);

    int x = k / aa;
    if(x > n){
        x = n;
    }

    int ans = 0;
    while(x >= 0){
        int r = k - x * aa;
        int y = r / bb;
        if(r % bb != 0){
            x--;
            continue;
        }

        int t1 = comb(table, factM(n), n, x);
        int t2 = comb(table, factM(n), n, y);
        int tmp = t1 * t2 % MOD;
        ans = (ans + tmp) % MOD;
        x--;
    }
    cout << ans << endl;

    return 0;
}
