
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

int LCsubstring(string a, string b){
    int n = a.size(), m = b.size(), res = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                res = max(res, dp[i][j]);
            }
        }
    }return res;
}


void solve(){
    string a,b; cin >> a >> b;
    if(a == b){
        cout << 0 << ln;
        return;
    }
    int seq = LCsubstring(a,b);
    // printf("seq ===> %d \n",seq);
    cout << a.size()  - seq + b.size() - seq << ln;
}

int32_t main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int res = 0;
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i = 1; i <=n; i++){
            for(int j = 1; j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
                
            }
        }
        return res;
    }
};