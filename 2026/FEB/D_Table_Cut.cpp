
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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1, 0));
    int total = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            total += a[i][j];
        }

    int need = total / 2;
    int cur = 0;
    string path;
    int i = 0;
    int c = m;
    int j = m;
    for(i = 0; i < n; i++) {
        j = m - 1;
        bool f = false;
        for(; j >= -1; j--) {
            if(a[i][j + 1] == 1 && cur < need) {
                cur++;
            }
            if(cur == need) {
                cur++;
                f = true;
                break;
            }
        }
        for(; j >= 0; j--) {
            path += 'R';
            c--;
        }
        path += 'D';
        if(f) break;
        }
    for(; c > 0; c--) path += 'R';
    for(; i + 1 < n; i++) path += 'D';
    cout << 1LL * need * (total - need) << ln cout << path << ln;
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