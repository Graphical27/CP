
/*⠀⠀⠀⠀
 Moon, tell me if I could
send up my heart to you?
so, when I die, which I must do
Could it shine down here with you?
… 'Cause my love is mine, all mine
I love mine, mine, mine
Nothing in the world belongs to me
But my love, mine, all mine, all mine
… My baby here on Earth
showed me what my heart was worth
so, when it comes to be my turn
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

void solve(){
    string s; cin >> s;
    int N = s.size();
    for(int i = 0; i < N - 1; i++)
        if((s[i] == '>' || s[i] == '*') && (s[i + 1] == '<' || s[i + 1] == '*')){
            cout << -1 << '\n';
            return;
        }
    int maxi = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == '<' || s[i] == '*') maxi = max(maxi, i + 1); 
        if(s[i] == '>' || s[i] == '*') maxi = max(maxi, N - i);
    }cout << maxi << ln;
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