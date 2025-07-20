
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


bool sec(const pair<int,int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

void solve(){
    int n, q; cin >> n >> q;
    int arr[n+9];
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v.push_back({i, arr[i]});
    }
    sort(arr, arr + n);
    sort(v.begin(), v.end(), sec);
    vector<int> ck(32, 0);
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        int srch = ceil(pow(2, x));
        int ind = 0;
        while(ind < n && ck[x] == 0){
            ind = lower_bound(arr+ind, arr + n, srch) - arr;
            if(ind < n && arr[ind]%srch == 0){
                arr[ind]+=(srch/2);
                v[ind].second = arr[ind];
            }ind++;
        }ck[x] = 1;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        cout << v[i].second << " ";
    }
    cout << ln;
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