#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
#define ln "\n"
#define all(v) v.begin(),v.end()
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int gcd(int a,int b){if(a==0) return b; return gcd(b%a,a);}
int lcm(int a,int b){ return (a*b)/gcd(a,b);}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        v.push_back({temp, i + 1});
    }
    sort(all(v), greater<>());
    vector<int> ans(n + 1);
    int f = 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        auto [val, idx] = v[i];
        ans[idx] = f;
        sum += val * abs(f);
        f = (f > 0) ? -f : -f + 1;
    }
    cout << sum * 2 << ln;
    cout << 0 << " ";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << ln;
}

int32_t main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
        solve();
    }
}
