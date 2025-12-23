#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int> pri;
bitset<21000> prime;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0; 
    for (int i = 2; i < 21000; i++) {
        if (prime[i]) {
            pri.push_back(i);
            for (int j = i * i; j < 21000; j += i) {
                prime[j] = false;
            }
        }
    }
}

int32_t main () {
    Fast_IO;
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;
        int fir = (*lower_bound(all(pri), d + 1));
        int sec = (*lower_bound(all(pri), fir + d));
        cout << fir * sec << '\n';  
    }return 0;
}
