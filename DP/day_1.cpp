#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// Normal recursive Fibonacci
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// DP (memoized) Fibonacci
int fib_dp(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib_dp(n - 1, dp) + fib_dp(n - 2, dp);
}

// DP (tabulation) Fibonacci
int fib_tab(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// int main() {
//     int n; cin >> n;

//     // Measure normal recursive Fibonacci
//     auto begin1 = chrono::high_resolution_clock::now();
//     cout << "Recursive: " << fib_recursive(n) << ln;
//     auto end1 = chrono::high_resolution_clock::now();
//     auto elapsed1 = chrono::duration_cast<chrono::nanoseconds>(end1 - begin1);
//     cerr << "Recursive Time: " << elapsed1.count() * 1e-9 << " seconds." << ln;

//     // Measure DP Fibonacci (memoized)
//     vector<int> dp(n + 1, -1);
//     auto begin2 = chrono::high_resolution_clock::now();
//     cout << "DP: " << fib_dp(n, dp) << ln;
//     auto end2 = chrono::high_resolution_clock::now();
//     auto elapsed2 = chrono::duration_cast<chrono::nanoseconds>(end2 - begin2);
//     cerr << "DP Time: " << elapsed2.count() * 1e-9 << " seconds." << ln;

//     // Measure DP Fibonacci (tabulation)
//     auto begin3 = chrono::high_resolution_clock::now();
//     cout << "Tabulation: " << fib_tab(n) << ln;
//     auto end3 = chrono::high_resolution_clock::now();
//     auto elapsed3 = chrono::duration_cast<chrono::nanoseconds>(end3 - begin3);
//     cerr << "Tabulation Time: " << elapsed3.count() * 1e-9 << " seconds." << ln;
// }


class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
