
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
    int a, b; cin >> a >> b;
    auto check = [&](int a, int b) {
        return a % b != 0 && b % a != 0;
    }; 
    int cnt = 0;
    while (a != b) {
        if (check(a, b)) {
            cout << -1 << ln;
            return;
        }
        if (a < b) {
            if (a * 8 <= b) a *= 8;
            else if (a * 4 <= b) a *= 4;
            else if (a * 2 <= b) a *= 2;
        } else {
            if (a % 8 == 0 && a / 8 >= b) a /= 8;
            else if (a % 4 == 0 && a / 4 >= b) a /= 4;
            else if (a % 2 == 0 && a / 2 >= b) a /= 2;
            else {
                cout << -1 << ln;
                return;
            }
        }cnt++;
    }cout << cnt << ln;
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