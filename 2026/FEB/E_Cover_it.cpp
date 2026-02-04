
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
#define eb     emplace_back
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
const int N = 2e5 + 5;
vector<int> e[N], ans[2];
int vis[N], d[N];

void dfs(int u, int z) {
    vis[u] = 1;
    ans[z].eb(u);
    for(auto v : e[u])
        if(!vis[v])
            dfs(v, 1 - z);
}

void solve() {
    int n, m; cin >> n >> m;
    ans[0].clear();
    ans[1].clear();
    for(int i = 1; i <= n; ++i) {
        vis[i] = d[i] = 0;
        e[i].clear();
    }
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].eb(v);
        e[v].eb(u);
    }
    dfs(1, 1);
    int fk = ans[0].size() > ans[1].size();
    cout << ans[fk].size() << ln;
    for(auto i : ans[fk])
        cout << i << ' ';
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