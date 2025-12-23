
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
#define for0 for (int i = 0; i < n; ++i)
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
    int n, ans = 0;
    string s; cin >> n >> s;
    vector<int> pf(n),sf(n);
    set<char> st1,st2;
    for(int i = 0; i < n; i++){
        st1.insert(s[i]);
        pf[i] = st1.size();
    }
    for(int i = 0; i < n; i++){
        st2.insert(s[n-i-1]);
        sf[n-i-1] = st2.size();
    }
    for(int i = 0; i < n-1; i++)ans = max(ans,pf[i]+sf[i+1]);
    cout << ans << ln
}

int main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}
