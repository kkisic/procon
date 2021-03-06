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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    string s;
    cin >> n >> s;

    rep(i, n-1){
        if(s[i] != s[i+1]){
            cout << "YES" << endl;
            cout << s[i] << s[i+1] << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
