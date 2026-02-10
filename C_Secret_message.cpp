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
#define ln     "\n";
#define all(v) v.begin(), v.end()
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int LCsubstring(string a, string b) {
    int n = a.size(), m = b.size(), res = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin >> n >> k;
    vector<int> masks(n, 0);
    for(int i = 0; i < k; i++) {
        string s; cin >> s;
        for(int j = 0; j < n; j++) {
            masks[j] |= (1 << (s[j] - 'a'));
        }
    }
    vector<int> divs;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divs.push_back(i);
            if(i * i != n) divs.push_back(n / i);
        }
    }
    sort(all(divs));
    for(int d : divs) {
        string temp = "";
        bool flag = true;
        for(int i = 0; i < d; i++) {
            int same_cnt = (1 << 26) - 1;
            for(int j = i; j < n; j += d) {
                same_cnt &= masks[j];
            }
            if(same_cnt == 0) {
                flag = false;
                break;
            }
            int char_idx = __builtin_ctz(same_cnt);
            temp += ('a' + char_idx);
        }
        if(flag) {
            string res = "";
            for(int i = 0; i < n / d; i++) {
                res += temp;
            }
            cout << res << ln;
            return;
        }
    }
}

int32_t main() {
    Fast_IO;
    int t = 1;
    cin >> t;
    while(t--) {
        //        auto begin = chrono::high_resolution_clock::now();
        solve();
        //        auto end = chrono::high_resolution_clock::now();
        //        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        //        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << ln;
    }
}