
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
    int s, m_val;
    if(!(cin >> s >> m_val)) return;
    map<int, int> all;
    for(int i = 61; i >= 0; i--) {
        if((1LL << i) & m_val) {
            all[i] = 0;
        }
    }
    for(int i = 0; i < 61; i++) {
        if(!((1LL << i) & s)) continue;
        bool found = false;
        for(int j = i; j >= 0; j--) {
            if((1LL << j) & m_val) {
                int d = (1LL << i) / (1LL << j);
                all[j] += d;
                found = true;
                break;
            }   
        }
        if(!found) {
            cout << -1 << ln;
            return;
        }
    }
    vector<pair<int, int>> allv;
    for(auto const& [bit, count] : all) {
        allv.push_back({bit, count});
    }
    sort(allv.rbegin(), allv.rend());
    vector<pair<int, int>> origin = allv;
    int low = 0, high = 2e18; 
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid == 0) {
            bool possible = true;
            for(auto const& p : origin)
                if(p.second > 0) possible = false;
            if(possible) {
                ans = 0;
                high = -1;
            } else
                low = 1;
            continue;
        }
        bool check = true;
        allv = origin;
        for(int i = 0; i < (int)allv.size(); i++) {
            if(allv[i].second <= mid) continue;
            if(i == (int)allv.size() - 1) {
                check = false;
                break;
            }
            int diff = allv[i].second - mid;
            int power_diff = allv[i].first - allv[i + 1].first;
            if(diff > (4e18 / (1LL << power_diff))) {
                allv[i + 1].second = 4e18;
            } else {
                allv[i + 1].second += diff * (1LL << power_diff);
            }
        }
        if(check) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }cout << ans << ln;
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