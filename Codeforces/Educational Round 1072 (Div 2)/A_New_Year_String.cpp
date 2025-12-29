
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


int check_2026(string s){
    string t = "2026";
    int n = s.size();
    int ans = LLONG_MAX;
    for(int i = 0; i + 3 < n; i++){
        int c = 0;
        for(int j = 0; j < 4; j++)
            if(s[i + j] != t[j]) c++;
        ans = min(ans, c);
    }
    return ans;
}

int check_2025(string s){
    int n = s.size();
    int cnt = 0;
    for(int i = 0; i + 3 < n; i++){
        if(s.substr(i, 4) == "2025"){
            cnt++;
            s[i + 3] = '6';   
        }
    }
    return cnt;
}

void solve(){
    int n;
    string s; cin >> n >> s;
    if(s.find("2026") != string::npos || s.find("2025") == string::npos){
        cout << 0 << "\n";
        return;
    }
    int a = check_2026(s);
    int b = check_2025(s);
    cout << min(a, b) << ln;
}

int32_t main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        // auto begin = chrono::high_resolution_clock::now();
        solve();
        // auto end = chrono::high_resolution_clock::now();
        // auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << ln;
    }
}