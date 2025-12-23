
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


// Got the logic for k == 4 from jiangly

void solve(){
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    int ans = k;
    for(auto &i:v){
        ans = min(ans, (k - i % k) % k);
    }if(k == 4){
        int even = count_if(all(v),
        [&](int x){
            return x%2 == 0;
        });
        ans = min(ans, max(0, 2 - even));;
    }cout << ans << ln;
}

int main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}
