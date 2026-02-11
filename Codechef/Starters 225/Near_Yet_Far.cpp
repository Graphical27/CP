
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
#define ln "\n";
#define all(v) v.begin(),v.end()
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int gcd(int a,int b){if(a==0) return b; return gcd(b%a,a);}
int lcm(int a,int b){ return (a*b)/gcd(a,b);}
int LCsubstring(string a, string b){int n = a.size(), m = b.size(), res = 0;vector<vector<int>> dp(n+1, vector<int>(m+1, 0));for(int i = 1; i <= n; i++){for(int j = 1; j <= m; j++){if(a[i-1] == b[j-1]){dp[i][j] = 1 + dp[i-1][j-1];res = max(res, dp[i][j]);}}}return res;}
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if(k == 2){
        int even_maxi = -1, even_mini = 2e18;
        int odd_maxi = -1, odd_mini = 2e18;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even_maxi = max(even_maxi, a[i]);
                even_mini = min(even_mini, a[i]);
            } else {
                odd_maxi = max(odd_maxi, a[i]);
                odd_mini = min(odd_mini, a[i]);
            }
        }
        int ans_1 = (even_maxi != -1) ? (even_maxi - even_mini) : 0;
        int ans_2 = (odd_maxi != -1) ? (odd_maxi - odd_mini) : 0;
        cout << max(ans_1, ans_2) << ln;
    } else{
        int ans = 0;
        int mini = a[0];
        int maxi = a[0];
        for (int i = 2; i < n; i++){
            mini = min(mini, a[i - 2]);
            maxi = max(maxi, a[i - 2]);
            ans = max(ans, abs(a[i] - mini));
            ans = max(ans, abs(a[i] - maxi));
        }cout << ans << ln;
    }
}

int32_t main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
//        auto begin = chrono::high_resolution_clock::now();
        solve();
//        auto end = chrono::high_resolution_clock::now();
//        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << ln;
    }
}