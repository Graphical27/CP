//9/14/2025 finally starting graph hehehehhe 10:19PM
#include<bits/stdc++.h>
using namespace std;


// vector<vector<int>> adj;
// int n, m;
// cin >> n >> m;
// adj.assign(n + 1, vector<int>(n + 1, 0));
// for (int i = 0; i < m; i++) {
//     int u, v;
//     cin >> u >> v;
//     adj[u][v]++;
//     adj[v][u]++;
// }

// int main(){
//     int n,m; cin >> n >> m;
//     vector<vector<int>> adj(n+1);
//     for(int i = 0; i < m; i++){
//         int u,v; cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
// }


// class Solution {
// public:
//     void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
//         visited[node] = true;
//         for (int neigh : adj[node]) {
//             if (!visited[neigh]) dfs(neigh, adj, visited);
//         }
//     }
//     int findNumberOfComponent(int V, vector<vector<int>> &edges) {
//         vector<vector<int>> adj(V);
//         for (auto &e : edges) {
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);  
//         }
//         vector<bool> visited(V, false);
//         int count = 0;
//         for (int i = 0; i < V; i++) {
//             if (!visited[i]) {
//                 count++;
//                 dfs(i, adj, visited);
//             }
//         }return count;
//     }
// };



class bfS{
public:
    vector<int> bfs(vector<vector<int>> &adj){
        vector<int> ans;
        vector<bool> vis(adj.size(),false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it:adj[curr]){
                if(vis[it]==false){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }return ans;
    }
}


class dfs{
public:
    vector<int> vis, ans;
    void helper(vector<vector<int>> &adj, int current){
        ans.push_back(current);
        vis[current] = 1;
        for(auto it: adj[current]){
            if(!vis[it]){
                helper(adj, it);
            }
        }
    }
    vector<int> dfs_traverse(vector<vector<int>> &adj){
        int n = adj.size();
        vis.assign(n, 0);
        ans.clear();
        helper(adj, 0);
        return ans;
    }
};

            ////// my logic ///// im a dumbooo ///////


// class Solution {
// public:
//     int helper(vector<vector<int>> &adj, vector<int> &exist){
//         vector<unordered_set<int>> groups;
//         int n = adj.size();

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(i != j && adj[i][j] == 1){
//                     if(!exist[i] && !exist[j]){
//                         groups.push_back({i, j});
//                         exist[i] = groups.size();
//                         exist[j] = groups.size();
//                     } else if(exist[i] && !exist[j]){
//                         groups[exist[i]-1].insert(j);
//                         exist[j] = exist[i];
//                     } else if(!exist[i] && exist[j]){
//                         groups[exist[j]-1].insert(i);
//                         exist[i] = exist[j];
//                     } else if(exist[i] != exist[j]){
//                         int gi = exist[i]-1;
//                         int gj = exist[j]-1;
//                         for(int x : groups[gj]){
//                             groups[gi].insert(x);
//                             exist[x] = exist[i];
//                         }
//                         groups[gj].clear();
//                     }
//                 }
//             }
//         }

//         int count = 0;
//         for(auto &g : groups){
//             if(!g.empty()) count++;
//         }
//         for(int i = 0; i < n; i++){
//             if(exist[i] == 0) count++;
//         }

//         return count;
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         ios::sync_with_stdio(false);
//         cin.tie(0);

//         int n = isConnected.size();
//         vector<int> exist(n, 0);
//         return helper(isConnected, exist);
//     }
// };




class Solution {
public:
    void dfs(int node, vector<vector<int>> &isConnected, vector<bool> &visited) {
        visited[node] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }return count;
    }
};


class Solution {
public:
    // int cnt = 0;
    void helper(vector<vector<int>> &edges,vector<int> &vis,int current){
        vis[current] = 1;
        for(auto it:edges[current]){
            if(!vis[it]){
                helper(edges,vis,it);
            }
        }
    }
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<int> vis(edges.size(), 0);
        int cnt = 0;
        for(int it = 0; it < edges.size(); it++){
            if(!vis[it]){
                cnt++;
                helper(edges,vis,it);
            }
        }
        return cnt;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    vis[i][j] = 2;
                }
            }
        }

        int ans = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int time = front.first;
            int row = front.second.first;
            int col = front.second.second;
            ans = max(ans, time);

            for(int k = 0; k < 4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == -1){
                    q.push({time+1,{nr,nc}});
                    vis[nr][nc] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1) return -1;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> q;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        vector<vector<int>> ans(image.begin(),image.end());
        ans[sr][sc] = color;
        q.push({color,{sr,sc}});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int time = front.first;
            int row = front.second.first;
            int col = front.second.second;
            for(int k = 0; k < 4; k++){
                int nr = row + dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == time && vis[nr][nc] == -1){
                    q.push({time,{nr,nc}});
                    vis[nr][nc] = time;
                    ans[nr][nc] = color;
                }
            }
            if(q.empty() && vis[row][col] == -1){
                break;
            }
        } return ans;
    }
};



class Solution{
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& parent){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                parent[it] = node;
                if(dfs(it, adj, vis, parent)) return true;
            }else if(parent[node]!=it){
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), parent(V, -1);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, parent)) return true;
            }
        }
        return false;
    }
};

class Solution{
public:
    int bfs(vector<vector<int>> &vis,vector<vector<int>> &grid,int i, int j,vector<vector<int>> &ans,queue<pair<int,int>> q){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        for(; i < n; i++){
            for(; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    while(!q.empty()){
                        auto temp = q.front();
                        int temp_i = temp.first;
                        int temp_j = temp.second;
                        q.pop();
                        ans[temp_i][temp_j] = abs(temp_i - i) + abs(temp_j - j);
                    }
                }else{
                    if(!vis[i][j]) q.push({i,j});
                }
            }
        }
    }
    
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][m]){
                    vis[i][m] = 1;
                    bfs(vis,grid,i,j,ans,q);
                }
            }
        }
    }
};

///////////// ALSO 

class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
                    ans[nr][nc] = ans[r][c] + 1;
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }return ans;
    }
};





class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // check first & last row
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                q.push({0,j}); vis[0][j] = 1;
            }
            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                q.push({n-1,j}); vis[n-1][j] = 1;
            }
        }
        // check first & last col
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                q.push({i,0}); vis[i][0] = 1;
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                q.push({i,m-1}); vis[i][m-1] = 1;
            }
        }
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        while(!q.empty()){
            auto [r,c] = q.front(); q.pop();
            board[r][c] = '#'; 
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k], nc = c + dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        
     
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};



#include <bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0);

class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& grid, int n, int m) {
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c] = 0; // mark visited

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dr[k];
                int ny = y + dc[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                    q.push({nx,ny});
                    grid[nx][ny] = 0;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // remove all 1s connected to border
        for(int i = 0; i < n; i++){
            if(grid[i][0]==1) bfs(i,0,grid,n,m);
            if(grid[i][m-1]==1) bfs(i,m-1,grid,n,m);
        }
        for(int j = 0; j < m; j++){
            if(grid[0][j]==1) bfs(0,j,grid,n,m);
            if(grid[n-1][j]==1) bfs(n-1,j,grid,n,m);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long current = 1,maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            current = current*nums[i];
            maxi = max(maxi,current);
            if(current == 0){
                current = 1;
            }
        }current = 1;
        for(int i = nums.size() - 1; i>= 0; i--){
            current = current*nums[i];
            maxi = max(maxi,current);
            if(current == 0){
                current =  1;
            }
        }return maxi;
    }
};


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if(k == 0) return ans;

        vector<int> prefix(2 * n + 1, 0);
        for(int i = 0; i < 2 * n; i++) 
            prefix[i + 1] = prefix[i] + code[i % n];
        for(auto i:prefix){
            cout << i <<" ";
        }cout << "\n";
        for(int i = 0; i < n; i++) {
            if(k > 0) 
                ans[i] = prefix[i + k + 1] - prefix[i + 1];
            else 
                ans[i] = prefix[i + n] - prefix[i + n + k];
        }
        return ans;
    }
};


// int main(){
//     Solution s;
//     vector<int> temp = {5,7,1,4};
//     vector<int> k = s.decrypt(temp, 3);
//     for(auto i : k){
//         cout << i << " ";
//     }
//     cout << "\n";
//     return 0;
// }





class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<int> prefix(n, 0);
        prefix[0] = (blocks[0] == 'B');
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + (blocks[i] == 'B');
        }
        int mini = INT_MAX;
        for(int i = 0; i <= n - k; i++){
            int j = i + k - 1;
            int blacks = prefix[j] - (i > 0 ? prefix[i-1] : 0);
            mini = min(mini, k - blacks);
        }return mini;
    }
};


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int cnt = 0, current = 0;
        for(int i = 2; i < nums.size(); i++){
            nums[i] - nums[i-1] ==  nums[i-1] - nums[i - 2] ? current++,cnt+=current:current = 0;
        }return cnt;     
    }
};


// 1, 2, 3, 4
// 3 = 1
// 4 = 3
// 5 = 6
// 1, 2, 3, 4, 5, 6
// 6 =10
// 1, 2, 3, 4, 5, 6, 7
// 7 = 15
// cnt+=lastidx - currentidx -1;



// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> mp;
        int cnt = 0;
        int n = p.size();
        for(int i = 0; i < p.size(); i++){
            mp[p[i]]++;
        }for(int i = 0; i < s.size() - n; i++){
            map<char,int> s;
            for(int j = i; j < p.size(); j++){
                s[s[i]]++;
            }if(s == mp) cnt++;
        }return {cnt};
    }
};

// optimised

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = s.size(), m = p.size();
        if (n < m) return {};
        vector<int> ans;
        vector<int> freqP(26,0), freqS(26,0);
        for (char c : p) freqP[c - 'a']++;
        for (int i = 0; i < m; i++) freqS[s[i] - 'a']++;
        if (freqS == freqP) ans.push_back(0);
        for (int i = m; i < n; i++) {
            freqS[s[i] - 'a']++;
            freqS[s[i - m] - 'a']--;
            if (freqS == freqP) ans.push_back(i - m + 1);
        }return ans;
    }
};


class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;
        if (n >= k - 1 + maxPts) return 1.0;
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double window = 1.0;
        double res = 0.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = window / maxPts;
            if (i < k) window += dp[i];
            else res += dp[i];
            if (i - maxPts >= 0) window -= dp[i - maxPts];
        }return res;
    }
};

// TODO 

class Solution {
public: // NOT COMPLETED CUZ IM TOO DUMB 
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt_one = 0;
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j  < m; j++){
                if(grid[i][j] == 1){ 
                    cnt_one = 1;
                    q.push({i,j});
                }
            }
        }vector<int> vis(n,0);
    }
};

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        int left = 0, res = 0;
        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }left++;
            }res = max(res, right - left + 1);
        }return res;
    }
};


///////////////////////////  DUH RESTARTING GRAPH CUZ I FKED UP 


class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<int> &vis,int &cnt,int i){
        vis[i] = 1;
        for(auto j:grid[i]){
            if(!vis[j]) dfs(grid,vis,cnt,j);
        }return 0;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
                if(!vis[i]){ 
                    dfs(isConnected,vis,cnt,i);
                    cnt++;
                }
        }return cnt;   
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int,int>>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    vis[i][j] = 2;
                }
            }
        }
        int ans = 0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()){
            auto t = q.front(); q.pop();
            auto temp = t.second;
            int time = t.first;
            int x = temp.first;
            int y = temp.second;
            ans = max(ans,time);
            for(int k = 0; k < 4; k++){
                int nr = x + dx[k];
                int nc = y + dx[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == -1){
                    q.push({time+1,{nr,nc}});
                    vis[nr][nc] = 2;
                }
            }
        }for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1) return -1;
            }
        }return ans;
    }
};


