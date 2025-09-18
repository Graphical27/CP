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



class bfs{
    vector<int> bfs(vector<vector<int>&adj){
        int n = adj.size();
        vector<int> ans;
        vector<int> vis(n,0);
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }return ans;
    }
}


class dfs{
    vector<int> dfs(vector<vector<int>> &adj){
        
    }
}