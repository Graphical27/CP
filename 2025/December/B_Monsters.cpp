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
#define ln "\n"
#define all(v) v.begin(),v.end()
#define YES "YES\n"
#define NO "NO\n"
#define Fast_IO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int gcd(int a, int b) { if(a == 0) return b; return gcd(b % a, a); }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
#define f first
#define s second
                                                        ///// Wrong //// 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i)
        pq.push({a[i], -i});
    vector<int> result;
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int health = top.f;
        int idx = -top.s;
        health -= k;
        if (health <= 0)
            result.push_back(idx + 1);
        else
            pq.push({health, -idx});
    }
    for (int x : result) cout << x << " ";
    cout << ln;
}

int main() {
    Fast_IO;
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}
