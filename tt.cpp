#define all(a) a.begin(),a.end()
#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
class Solution {
    public:
        vector<int> shortestPath(vector<vector<int>>& edges, int N, int M){
            vector<vector<int>> adj(N);
            for(auto &e : edges) {
                int u = e[0], v = e[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            const int INF = 1e9;
            vector<int> dist(N, INF);
            queue<int> q;
            dist[0] = 0;
            q.push(0);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] > dist[u] + 1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                    }
                }
            }
            for(int i = 0; i < N; ++i) {
                if (dist[i] == INF) dist[i] = -1;
            }return dist;
        }
};

class Solution {
    public:
        vector<int> shortestPath(vector<vector<int>>& edges, int N, int M){
            vector<vector<int>> adj;
            for(auto e:edges){
                int u = e[0],v = e[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }const int inf = INT_MAX;
            vector<int> dis(N,inf);
            queue<int> q;
            dis[0] = 0;
            q.push(0);
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v: adj[u]){
                   if(dis[v] > dis[u] + 1){
                        dis[v] = dis[u] + 1;
                        q.push(v);
                   } 
                }
            }
            for(int i = 0; i < dis.size(); i++){
                if(i == inf){
                    cout << -1 << ln;
                    return;
                }
            }return dis;
        }
};

class Solution {
private:
    void topo_sort(int i, vector<int> &vis, stack<int> &st, vector<pair<int,int>> adj[]) {
        vis[i] = 1;
        for (auto &k : adj[i]) {
            if (!vis[k.first]) {
                topo_sort(k.first, vis, st, adj);
            }
        }
        st.push(i);
    }
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        vector<pair<int,int>> adj[N];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) topo_sort(i, vis, st, adj);
        }
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != INT_MAX) {
                for (auto &it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        for (int &x : dist) if (x == INT_MAX) x = -1;
        return dist;
    }
};

class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        vector<pair<int,int>> adj[N];
        for(auto [u,v,w]:edges){
            adj[u].push_back({v,w});
        }const int inf = INT_MAX;
        vector<int> dist(N,inf);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            for(auto [v,w]:adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }for(auto &x:dist) if(x == inf) x = -1;
        return dist;
    }
};


class Solution {
public:
    vector<int> dijkstra(int N, vector<vector<int>> &edges, int S) {
        vector<pair<int,int>> adj[N];
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }const int inf = INT_MAX;
        vector<int> dist(N,inf),parent(N,0);
        iota(all(parent),0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        dist[S] = 0;
        while(!pq.empty()){
            auto[d,u] = pq.top(); pq.pop();
            for(auto [v,w]:adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v],v});
                }
            }
        }if(dist[N-1] == inf) return {-1};
        vector<int> path;
        int node = N - 1;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }path.push_back(S);
        reverse(all(path));
        return path;
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0) return -1;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<vector<int>> q;
        q.push({source.first, source.second, 0});
        vis[source.first][source.second] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int r = temp[0], c = temp[1], dist = temp[2];
            if (r == destination.first && c == destination.second) return dist;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
        return -1;
    }
};



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); 
        dist[0][0] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int effort = cur[0], r = cur[1], c = cur[2];
            if (r == n - 1 && c == m - 1) return effort;
            if (effort > dist[r][c]) continue;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newEffort = max(effort, abs(heights[nr][nc] - heights[r][c]));
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }return 0;
    }
};


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];
        for(auto e:flights){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }const int inf = INT_MAX;
        vector<int> dist(n,inf);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()){
            auto[price,u] = pq.top(); pq.pop();
            if(u == dst) return price;
            for(auto &[v,w]:adj[u]){
                if()
            } 
        }
    }
};




class Solution {
    public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<pair<int,int>> adj[N];
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }const int inf = INT_MAX;
        vector<int> dist(N,inf);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto[d,u] = pq.top(); pq.pop();
            for(auto[v,w]:adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }for(auto &x:dist) if(x == inf) x = -1;
        return dist;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<vector<int>> q;
        q.push({0,0,1});
        vis[0][0] = 1;
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};
        while (!q.empty()) {
            auto temp = q.front(); q.pop();
            int r = temp[0], c = temp[1], dist = temp[2];
            if (r == n-1 && c == n-1) return dist;
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc, dist + 1});
                }
            }
        }return -1;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); 
        dist[0][0] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto e = pq.top(); pq.pop();
            int effort = e[0];
            int r = e[1];
            int c = e[2];
            if(r == n - 1&& c == m - 1) return effort;
            if (effort > dist[r][c]) continue;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newEffort = max(effort,abs(heights[nr][nc] - heights[r][c]));
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,nr,nc});
                    }
                }
            }
        }return 0;
    }
};


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto e:flights){
            int u = e[0];
            int v = e[1];
            int w = e[2];
        adj[u].push_back({v,w});
        }const int inf = INT_MAX;
        vector<int> cost(n,inf);
        queue<vector<int>> q;
        q.push({0,0,src}); //stop,cost, pst
        cost[src] = 0;
        while(!q.empty()){
            auto temp = q.front(); q.pop();
            int step = temp[0];
            int price = temp[1];
            int  u = temp[2];
            if(step > k) continue;
            for(auto[v,w]:adj[u]){
                if(cost[v] > price + w){
                    cost[v] = price + w;
                    q.push({step + 1,cost[v],v});
                }
            }
        }return cost[dst] == INT_MAX ? -1:cost[dst];
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for (auto &e : times)
            adj[e[0]].push_back({e[1], e[2]});
        const int INF = INT_MAX;
        vector<int> dist(n+1, INF);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k}); 
        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (cost > dist[u]) continue; 
            for (auto [v, w] : adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return (ans == INF) ? -1 : ans;
    }
};


class Solution {
public:
    int countPaths(int N, vector<vector<int>>& roads) {
        vector<vector<int>> adj[N];
        for(auto e:roads){
            adj[e[0]].push_back({e[1],e[2]});
        }const int inf = INT_MAX;
        vector<int> dist(N,inf);
        vector<int> vis(N,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto[d,u] = pq.top(); pq.pop();
            for(auto[v,w]:adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }   
            }
        }
        set<vector<int>> s;
        int mini = dist[N - 1];
        queue<pair<int,int>> q;
        fill(all(dist),inf);
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()){
            auto[dist,u] = q.front(); q.pop();
            if(dist > mini) continue;
            for(auto[v,w]:adj[u]){
                if()
            }
        }
    }
};