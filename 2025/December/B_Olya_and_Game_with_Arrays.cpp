
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


void solve(){
    int n; cin >> n;
    unordered_map<int,vector<int>> mp;
    vector<bool> check(n,true);
    int temp = 0;
    int min_ind;
    int mini = INT_MAX;
    while(n--){
        int k; cin >> k;
        for(int i = 0; i < k;i++){
            int t; cin >> t;
            t < mini ? mini = t,min_ind = temp : false;
            check[t] = false;
            mp[temp].push_back(t);
        }temp++;
    }
}

int main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}
