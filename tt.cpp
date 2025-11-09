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
