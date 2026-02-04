
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
    int n, k; cin >> n >> k;
    vector<int> p(n);
    for(int &x : p) cin >> x;
    vector<int> dp(n + 1, 0);
    vector<int> vals = p;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    auto get_idx = [&](int val) -> int {
        return lower_bound(all(vals), val) - vals.begin();
    };
    int m = vals.size();
    int size = 1;
    while(size <= m) size *= 2;
    vector<int> tree(2 * size, 1e18);
    auto update = [&](int pos, int index_val) {
        pos += size;
        tree[pos] = index_val; 
        for (pos /= 2; pos >= 1; pos /= 2) {
            tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
        }
    };
    auto query = [&](int l, int r) -> int {
        if (l > r) return 1e18;
        int res = 1e18;
        for (l += size, r += size; l <= r; l /= 2, r /= 2) {
            if (l % 2 == 1) res = min(res, tree[l++]);
            if (r % 2 == 0) res = min(res, tree[r--]);
        }
        return res;
    };
    vector<int> dp_arr(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) {
        int current_price = p[i];
        auto it1 = lower_bound(all(vals), current_price + k + 1);
        int l1 = distance(vals.begin(), it1);
        int r1 = m - 1;
        int idx1 = query(l1, r1);
        auto it2 = upper_bound(all(vals), current_price - k - 1);
        int r2 = distance(vals.begin(), it2) - 1;
        int l2 = 0;
        int idx2 = query(l2, r2);
        int next_j = min(idx1, idx2);
        int take = 0;
        if (next_j <= n - 1) { 
            take = 1 + dp_arr[next_j + 1];
        }
        int skip = dp_arr[i + 1];
        dp_arr[i] = max(take, skip);
        update(get_idx(current_price), i);
    }cout << dp_arr[0] << ln;
}

int32_t main(){
    Fast_IO;
    int t = 1; cin >> t;
    while (t--){
//        auto begin = chrono::high_resolution_clock::now();
        solve();
//        auto end = chrono::high_resolution_clock::now();
//        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << ln;
    }
}
