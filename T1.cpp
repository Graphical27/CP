
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


// class Solution {
// public:
//     map<int,map<int,multiset<int>>> mp;
//     void helper(TreeNode* root, int x, int y){
//         if(root == NULL)return ;
//         mp[x][y].insert(root->val);
//         helper(root->left,x-1,y+1);
//         helper(root->right,x+1,y+1);
//     }
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         cout << helper(TreeNode* root,0,0) << ln;
//         vector<vector<int>> ans(mp.size());
//         for(auto &x:mp){
//             sort(all(x.second));
//             for(auto &y:x.second){
//                 ans.push_back(y);
//             }
//         }
//     }
// };

class Solution{
    public:
    map<int,pair<int,int>> mp;
    void helper(TreeNode* root,int x,int y){
        if(!root) return;
        if(mp.find(x) == mp.end() || mp[x].first > y || (mp[x].first == y && mp[x].second > root->val)){
            mp[x] = {y, root->val};
        }
        helper(root->left, x - 1, y + 1);
        helper(root->right, x + 1, y + 1);
    }
    vector<int> topView(TreeNode *root){
        helper(root, 0, 0);
        vector<int> ans;
        for(auto &x: mp){
            ans.push_back(x.second.second);
        }return ans;
    }
};