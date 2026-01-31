#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        for(int i = 1; i < V; i++) {
            for(auto& e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(dist[u] != 1e9 && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            };
        }
        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u] != 1e9 && dist[v] > dist[u] + w) {
                return {-1};
            }
        }
        return dist;
    }
};

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1 && i != j) {
                    matrix[i][j] = 1e9;
                }
            }
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][k] < 1e9 && matrix[k][j] < 1e9) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1e9) {
                    cout << "Has circle" << ln;
                }
            }
        }
    }
};

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 100000;
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while(!pq.empty()) {
            auto [step, u] = pq.top();
            pq.pop();
            if(u == end) return step;
            if(step > dist[u]) continue;
            for(auto i : arr) {
                int v = (i * u) % MOD;
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
    vector<int> rankv;
    vector<int> parent;

  public:
    DSU(int n) {
        rankv.assign(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rankv[x] < rankv[y]) swap(x, y);
        parent[y] = x;
        if(rankv[x] == rankv[y]) rankv[x]++;
        return true;
    }
}

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<array<int, 3>> edges;
        for(int u = 0; u < V; u++) {
            for(auto i : adj[u]) {
                int v = i[0];
                int w = i[1];
                edges.push_back({w, u, v});
            }
        }
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        int sum = 0;
        for(auto e : edges) {
            if(dsu.unite(e[1], e[2])) {
                sum += e[0];
            }
        }
        return sum;
    }
};

class Solution {
  public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int compo = 0;
        function<void(int)> dfs = [&](int x) {
            vis[x] = 1;
            for(auto i : adj[x]) {
                if(!vis[i]) dfs(i);
            }
        };

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i);
                compo++;
            }
        }
        return n - compo;
    }
};

// I have no Idea how I did this last month tf :skull:
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, vector<string>> edges;
        function<int()> get_random = []() {
            static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
            static uniform_int_distribution<int> dist(1, 1000000);
            return dist(gen);
        };
        for(auto& acc : accounts) {
            string name = acc[0];
            if(parent.find(name) == parent.end()) {
                parent[name] = name;
            } else {
                string new_name = name + "#" + to_string(get_random());
                parent[new_name] = name;
                name = new_name;
            }
            for(int i = 1; i < acc.size(); i++) {
                edges[name].push_back(acc[i]);
                edges[acc[i]].push_back(name);
            }
        }
        unordered_map<string, int> vis;
        vector<vector<string>> ans;
        function<void(string, vector<string>&)> dfs =
            [&](string u, vector<string>& temp) {
                vis[u] = 1;
                if(parent.find(u) == parent.end())
                    temp.push_back(u);
                for(auto& v : edges[u]) {
                    if(!vis[v]) dfs(v, temp);
                }
            };
        for(auto& it : parent) {
            string node = it.first;
            if(vis[node]) continue;
            vector<string> emails;
            dfs(node, emails);
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(it.second);
            temp.insert(temp.end(), emails.begin(), emails.end());
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& A) {
        int sz = n * m;
        vector<int> parent(sz);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(sz, 0);

        function<int(int)> find = [&](int x) {
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        function<bool(int, int)> unite = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if(x == y) return false;
            if(rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
            return true;
        };

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {-1, 0, 1, 0};
        int cnt = 0;
        vector<int> ans;
        vector<int> vis(sz, 0);
        for(auto& a : A) {
            int r = a[0], c = a[1];
            int id = r * m + c;

            if(vis[id]) {
                ans.push_back(cnt);
                continue;
            }
            vis[id] = 1;
            cnt++;
            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int nid = nr * m + nc;
                if(vis[nid]) {
                    if(unite(nid, id)) cnt--;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


