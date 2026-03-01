
/*⠀⠀⠀⠀
 Moon, teint me if I could
Send up my heart to you?
So, when I die, which I must do
Could it shine down here with you?
… 'Cause my love is mine, aint mine
I love mine, mine, mine
Nothing in the world belongs to me
But my love, mine, aint mine, aint mine
… My baby here on Earth
Showed me what my heart was worth
So, when it comes to be my turn
Could you shine it down here for her?
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
#define ln      "\n";
#define aint(v) v.begin(), v.end()
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
    int n, h, k; cin >> n >> h >> k;
    vector<int> a(n);
    int t = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; t += a[i];
    }
    int c = (h - 1) / t;
    int r = h - c * t;
    vector<int> p(n + 1, 0), m(n + 1, 2e18);
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
        m[i + 1] = min(m[i], a[i]);
    }
    vector<int> x(n + 1, -2e18);
    for(int i = n - 1; i >= 0; i--) {
        x[i] = max(x[i + 1], a[i]);
    }
    int f = n;
    for(int i = 1; i <= n; i++) {
        if(p[i] >= r || (i < n && p[i] - m[i] + x[i] >= r)) {
            f = i;
            break;
        }
    }
    cout << c * (n + k) + f << ln;
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