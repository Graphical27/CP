
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
typedef long long ll;
const int MOD = 1e9 + 7;
#define ln "\n";
#define all(v) v.begin(),v.end()
#define YES "YES\n";
#define NO "NO\n";
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int gcd(int a,int b){if(a==0) return b; return gcd(b%a,a);}
int lcm(int a,int b){ return (a*b)/gcd(a,b);}


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         Fast_IO;
         vector<int> dp(amount+1,INT_MAX);
         dp[0] = 0;
         for(auto c: coins){
            for(int i=c;i<=amount;++i){
                if(dp[i-c]!=INT_MAX) dp[i]=min(dp[i],dp[i-c]+1);
            }
         }
         if(dp[amount]==INT_MAX)return -1;
         else{
             return dp[amount];
         }
    }
};