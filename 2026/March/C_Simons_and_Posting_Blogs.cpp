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
#define pb     push_back
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
    set<int> iall;
    vector<vector<int>> arr(n + 1);
    for(int i = 1; i <= n; i++) {
        int h; cin >> h;
        while(h--) {
            int a; cin >> a;
            arr[i].pb(a);
            iall.insert(a);
        }reverse(arr[i].begin(), arr[i].end());
    }
    vector<int> ans;
    set<int> all;
    vector<bool> vis(n + 1);
    while(true) {
        vector<int> curr;
        int k = -1;
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            vector<int> currr;
            set<int> found;
            for(auto j : arr[i]) {
                if(all.find(j) == all.end() && found.find(j) == found.end()) {
                    currr.pb(j);
                    found.insert(j);
                }
            }
            if(!currr.empty() && (curr.empty() || currr < curr)) {
                curr = currr;
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = 1;
        for(auto j : curr) {
            ans.pb(j);
            all.insert(j);
        }
    }
    for(auto j : ans) cout << j << " ";
    cout << ln;
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