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

void solve(){
    int n; cin >> n;
    vector<int> a(n), cnt(n+1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<bool> pfix(n+2);
    pfix[0] = true;
    for (int k = 1; k <= n+1; k++) pfix[k] = pfix[k-1] && (cnt[k-1] > 0);
    vector<int> diff(n+2);
    for (int i = 0; i <= n; i++){
        if (!pfix[i]) break;
        int l = cnt[i];
        int r = n - i;
        if (l <= r) {
            diff[l]++;
            diff[r+1]--;
        }
    }
    vector<int> ans(n+1);
    int cur = 0;
    for (int k = 0; k <= n; k++){
        cur += diff[k];
        ans[k] = cur;
    }
    for (int k = 0; k <= n; k++){
        cout << ans[k] << " \n"[k==n];
    }
}

int32_t main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}
