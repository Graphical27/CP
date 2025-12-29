
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
const int MOD = 998244353;
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

int C[60][60];    
int fact[60];       

void precompute(){
    for (int i = 0; i <= 55; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    fact[0] = 1;
    for (int i = 1; i <= 55; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for(int i = 0; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    int q = sum / n;  
    int r = sum % n;  
    int need = 0, cnt = 0; 
    for(int i = 1; i <= n; i++){
        if(a[i] > q + 1) {
            cout << 0 << ln;
            return;
        }
        a[i] == q + 1 ? need++ : cnt++;
    }
    if(need > r){
        cout << 0 << ln;
        return;
    }
    int no_ways = C[cnt][r - need];
    int cnt_vip = fact[r];
    int cnt_nrm = fact[n - r];
    int ans = (no_ways * cnt_vip) % MOD;
    ans = (ans * cnt_nrm) % MOD;
    cout << ans << ln;
}

int32_t main(){
    Fast_IO;
    precompute();
    int t = 1; cin >> t;    
    while (t--){
        // auto begin = chrono::high_resolution_clock::now();
        solve();
        // auto end = chrono::high_resolution_clock::now();
        // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << ln;
    }
}