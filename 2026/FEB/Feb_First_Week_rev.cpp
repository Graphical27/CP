#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
#define ln     "\n";
#define all(v) v.begin(), v.end()

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 100000;
        vector<int> dist(MOD, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        dist[start] = 0;
        while(!pq.empty()) {
            auto [step, u] = pq.top();
            pq.pop();
            if(u == end) return step;
            if(step > dist[u]) continue;
            for(auto i : arr) {
                int v = (u * i) % MOD;
                if(dist[v] > step + 1) {
                    dist[v] = step + 1;
                    pq.push({step + 1, v});
                }
            }
        }
        return -1;
    }
};

class DSU {
  private:
    vector<int> parent;
    vector<int> rank;

  public:
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end());
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
        return true;
    }
}

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<array<int, 3>> edges;
        for(int u = 0; u < V; u++) {
            for(auto i : adj[u]) {
                int v = i[0], w = i[1];
                edges.push_back({
                    w,
                    u,
                    v,
                });
            }
        }
        sort(edges.begin(), edges.end());

        DSU(V);
        int sum = 0;
        for(auto e : edges) {
            if(DSU.unite(e[1], e[2])) sum += e[0];
        }
        return sum;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1, j < n; j++){
                if(stones[0][i] == stones[0][j] || stones[1][i] == stone
                s[1][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        auto dfs = [&](int x){
            vis[x] = 1;
            for(auto i:adj[x]){
                if(!vis[i]) dfs(i);
            }
        }
        int compo = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                compo++;
            }
        }
        return n - compo;    
    }
};
