
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
//   public:
//     map<int,pair<int,int>> mp;
//     void helper(TreeNode* root,int x,int y){
//         if(!root) return;
//         if(mp.find(y) == mp.end() || mp[y].first <= x) mp[y] = {x,root->data};
//         helper(root->left,x+1,y-1);
//         helper(root->right,x+1,y+1);
//     }
//     vector<int> bottomView(TreeNode *root){
//         helper(root,0,0);
//         vector<int> ans;
//         for(auto &it:mp) ans.push_back(it.second.second);
//         return ans;
//     }
// };


// class Solution {
// public:
//     map<int,vector<int>> mp;
//     void helper(TreeNode* root,int level){
//         if(!root) return;
//         mp[level].push_back(root->val);
//         helper(root->left,level+1);
//         helper(root->right,level+1);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         helper(root,0);
//         vector<int> ans;
//         for(auto &it:mp) ans.push_back(it.second.back());
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> ans;
//     void helper(TreeNode* root, vector<int>& temp){
//         if (!root) return;
//         temp.push_back(root->val);
//         if (!root->left && !root->right) {
//             ans.push_back(temp);
//         } else {
//             helper(root->left, temp);
//             helper(root->right, temp);
//         }
//         temp.pop_back();
//     }

//     vector<vector<int>> allRootToLeaf(TreeNode* root) {
//         vector<int> temp;
//         helper(root, temp);
//         return ans;
//     }
// };


// class Solution {
// public:
//     int ans = -1;
//     bool found_1 = false, found_2 = false;
//     vector<int> temp,temp_2;
//     void helper2(){
//         for(int i = 0; i < temp.size();i++){
//             for(int j = 0; j < temp2.size(); j++){
//                 if(temp[i] == temp2[j]){
//                     ans = temp[i];
//                     return;
//                 }
//             }
//         }
//     }
//     void helper(TreeNode* root, TreeNode* p, TreeNode* q){
//         if(!root) return;
//         if(found_1 && found_2){
//             helper2();
//             return;
//         }
//         temp.push_back(root->data);
//         if(root == p){
//             found_1 = true;
//             temp2 = temp;
//             temp.clear();
//         }else if(root == q){
//             found_2 = true;
//         }helper(root->left,p,q);
//         helper(root->right,p,q);
//         temp.pop_back();
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//             helper(root,p,q);
//             return ans;
//     }
// };

// class Solution {
// public:
//     void childrenSum(TreeNode* root) {
//         if (!root) return;
//         childrenSum(root->left);
//         childrenSum(root->right);

//         int leftVal = (root->left ? root->left->val : 0);
//         int rightVal = (root->right ? root->right->val : 0);
//         int sum = leftVal + rightVal;

//         if (root->left || root->right) {  
//             if (sum >= root->val) {
//                 root->val = sum;
//             } else {
//                 if (root->left) root->left->val = root->val - rightVal;
//                 if (root->right) root->right->val = root->val - leftVal;
//             }
//         }
//     }
// };



// class Solution {
// public:
//     void markedparent(TreeNode* root, unordrer_map<TreeNode* , TreeNode*> &parent_track, TreeNode* target){
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* current = q.front();
//             q.pop();

//             if(current->left){
//                 parent_track[current->left] = current;
//                 q.push(current->left)
//             }if(current->right){
//                 parent_track[current->right] = current;
//                 q.push(current->right)
//             }
//         }
//     }
// 	vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
// 		unordrer_map<TreeNode* , TreeNode*> parent_track;
//         markedparent(root, &parent_track, target);
//         unordered_map<TreeNode*, bool> visited;
//         queue<TreeNode*> q;
//         q.push(target);
//         visited[target] = true;
//         int curr_lvl = 0;
//         while(!q.empty()){
//             int size = q.size();
//             if(curr_lvl++ == k) break;
//             for(int i = 0; i < size; i++){
//                 TreeNode* current = q.front();
//                 queue.pop();
//                 if(current->left && !visited[current->left]){
//                     q.push(current->left);
//                     visited[current->left] = true;
//                 }
//                 if(current->right && !visited[current->right]){
//                     q.push(current->right);
//                     visited[current->right] = true;
//                 }
//                 if(parent_track[current] && !visited[parent_track[current]]){
//                     q.push(parent_track[current]);
//                     visited[parent_track[current]] = true;
//                 }
//             }
//         }vector<int> result;
//         while(!q.empty()){
//             TreeNode* current = q.front();
//             q.pop();
//             result.push_back(current->data);
//         }
//         return result;
//     }
// };


// class Solution {
// public:
//     TreeNode* target = NULL;
//     void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int tar) {
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             TreeNode* current = q.front();
//             q.pop();
//             if(current->val == tar) target = current;
//             if(current->left){
//                 parent_track[current->left] = current;
//                 q.push(current->left);
//             }
//             if(current->right){
//                 parent_track[current->right] = current;
//                 q.push(current->right);
//             }
//         }
//     }

//     int timeToBurnTree(TreeNode* root, int start) {
//         unordered_map<TreeNode*, TreeNode*> parent_track;
//         markParent(root, parent_track, start);

//         unordered_map<TreeNode*, bool> visited;
//         queue<TreeNode*> q;
//         q.push(target);
//         visited[target] = true;

//         int cnt = 0;
//         while(!q.empty()){
//             int size = q.size();
//             bool burned = false;
//             for(int i = 0; i < size; i++){
//                 TreeNode* current = q.front();
//                 q.pop();
//                 if(current->left && !visited[current->left]){
//                     burned = true;
//                     q.push(current->left);
//                     visited[current->left] = true;
//                 }
//                 if(current->right && !visited[current->right]){
//                     burned = true;
//                     q.push(current->right);
//                     visited[current->right] = true;
//                 }
//                 if(parent_track.count(current) && !visited[parent_track[current]]){
//                     burned = true;
//                     q.push(parent_track[current]);
//                     visited[parent_track[current]] = true;
//                 }
//             }if(burned) cnt++;
//         }return cnt;
//     }
// };


class Solution {
public:
    int helper(TreeNode* root){
        if(!root) return 0;
        return helper(root->left) + helper(root->right) + 1;
    }
    int countNodes(TreeNode* root) { 
       cout << helper(root);
    }
};


class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			return a==b? false: a==2||b==2? true:false;
		}
};