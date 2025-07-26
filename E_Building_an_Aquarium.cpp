
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

// void solve(){
//     int n, x; cin >> n >> x;
//     vector<int> v(n);
//     for (auto &i : v) cin >> i;
//     if (n == 1) {
//         cout << v[0] + x << ln;
//         return;
//     }
//     priority_queue<int, vector<int>, greater<>> pq(v.begin(), v.end());
//     while (x){
//         int curr = pq.top();
//         pq.pop();
//         pq.push(curr + 1);
//         x--;
//     }cout << pq.top() << ln;
// }

// void solve(){
//     ll n;
//     cin >> n;
//     ll x;
//     cin>>x;
//     vector<ll>v(n);
//     for (int i = 0; i < n; i++) {
//         cin >> v[i];
//     }
 
//     ll si = 1, ei = 1e12, ans = -1;
//     while (si <= ei) {
//         ll mid = si + (ei - si) / 2;
//         if(helper(mid,v,x)){
//             ans=mid;
//             si=mid+1;
//         }
//         else{
//             ei=mid-1;
//         }
//     }
//     cout<<ans<<endl;
 
// }

void solve() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    int low = 0, high = 1e12, ans = 0;
    auto canFill = [&](int h) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += max(0LL, (int)h - v[i]);
            if (sum > x) return false;
        }
        return true;
    };
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFill(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }cout << ans << ln;
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