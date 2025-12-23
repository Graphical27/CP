
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

void solve(){
    int n, x, y; cin >> n >> x >> y;
    string s; cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int reqa = 0, reqb = 0;
    bool is_zero = false, is_one = false;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            is_zero = true;
            int amin = v[i] / 2 + 1;
            int bmin = max(0LL, v[i] - amin);
            reqa += amin;
            reqb += bmin;
        }else{
            is_one = true;
            int bmin = v[i] / 2 + 1;
            int amin = max(0LL, v[i] - bmin);
            reqa += amin;  
            reqb += bmin;
        }
    }
    if(x < reqa || y < reqb){
        cout << "NO" << ln;
        return;
    }
    if(!is_one){ 
        if(x < y + n){
            cout << "NO" << ln;
            return;
        }
    }
    if(!is_zero){ 
        if(y < x + n){
            cout << "NO" << ln;
            return;
        }
    }
    cout << "YES" << ln;
}

int32_t main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        auto begin = chrono::high_resolution_clock::now();
        solve();
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << ln;
    }
}
