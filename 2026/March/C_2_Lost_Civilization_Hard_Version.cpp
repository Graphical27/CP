
/*⠀⠀⠀⠀
 Moon, tell me if I could
Send up my heart to you?
So, when I die, which I must do
Could it shine down here with you?
… 'Cause my love is mine, all mine
I love mine, mine, mine
Nothing in the world belongs to me
But my love, mine, all mine, all mine
… My baby here on Earth
Showed me what my heart was worth
So, when it comes to be my turn
Could you shine it down here for her?
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
#define ln     "\n";
#define all(v) v.begin(), v.end()
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int LCsubstring(string a, string b) {
    int n = a.size(), m = b.size(), res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin >> n;
    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int c = 1;
    set<int> all;
    all.insert(arr[1]);
    vector<int> val(n + 1);
    val[1] = c;
    for(int i = 2; i <= n; i++) {
        if(all.find(arr[i] - 1) != all.end()) {
            while(!all.empty() && *(all.rbegin()) > arr[i] - 1) {
                all.erase(*all.rbegin());
            }
            all.insert(arr[i]);
        } else {
            c++;
            all.clear();
            all.insert(arr[i]);
        }
        val[i] = c;
    }
    vector<int> ans(n + 1);
    map<int, int> ind;
    int h = 1;
    ans[1] = 1;
    ind[arr[1]] = 1;
    for(int i = 2; i <= n; i++) {
        if(val[i] != val[i - 1]) {
            ans[i] = ans[i - 1] + i;
            ind.clear();
        } else {
            ans[i] = ans[i - 1] + 1;
            if(ind[arr[i] - 1]) {
                ans[i] += i - ind[arr[i] - 1] - 1;
            }
        }

        h += ans[i];
        ind[arr[i]] = i;
    }
    all.clear();
    cout << h << ln;
}

int32_t main() {
    Fast_IO;
    int t = 1;
    cin >> t;
    while(t--) {
        //        auto begin = chrono::high_resolution_clock::now();
        solve();
        //        auto end = chrono::high_resolution_clock::now();
        //        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        //        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << ln;
    }
}