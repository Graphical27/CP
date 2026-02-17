
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
const int INF = 1e15;
const int N = 1e6;
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

int n, m, k, a, b, c, d, h, l, r, q, u, v, x, y;
vector<int> arr(N);
vector<int> depth(N);
vector<int> adj[N];
vector<int> dp(N);
vector<int> ans(N);
vector<int> vis(N);

void dfs(int node, int par, int dep) {
    vis[node] = true;
    dp[node] = 4;
    depth[node] = dep;
    for(auto j : adj[node]) {
        if(!vis[j]) {
            dfs(j, node, dep + 1);
            dp[node] += dp[j];
        }
    }

    if(adj[node].size() <= 1) dp[node] = 0;
}

void dfs2(int node, int par, int val) {
    ans[node] = (val + dp[node] + depth[node]) % MOD;
    for(auto j : adj[node]) {
        if(j != par) {
            dfs2(j, node, (val + dp[node]) % MOD);
        }
    }
}

void cleartree() {
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        dp[i] = 0;
        vis[i] = 0;
        depth[i] = 0;
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(a == 0) continue;
        adj[i].pb(a);
        adj[i].pb(b);
        adj[a].pb(i);
        adj[b].pb(i);
    }
    dfs(1, 0, 0);
    dfs2(1, 0, 0);
    for(int i = 1; i <= n; i++) cout << ans[i] + 1 << " ";
    cleartree();
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