
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
#define ln     "\n"
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

void solve(){
    int n; cin >> n;
    vector<int> mp(2 * n + 1);
    for(int i = 0; i < 2 * n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0;
    int odd = 0, even = 0;
    for(int i = 1; i <= 2 * n; i++){
        if(mp[i]){
            ans += 2 - (mp[i] % 2);
            if(mp[i] % 2) odd++;
            else even++;
        }
    }
    if(odd) cout << ans << ln;
    else{
        int cnt = ans / 2;
        if(n % 2 == cnt % 2) cout << ans << ln;
        else cout << ans - 2 << ln;
    }
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