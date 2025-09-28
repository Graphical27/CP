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
