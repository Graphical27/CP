
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


class Solution { // im a dumb
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e9); dist[S] = 0;
        for(int i = 0; i  < V - 1; i++){
            for(auto e:edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(dist[u] != 1e9 && dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }for(auto e: edges){
             int u = e[0];
             int v = e[1];
             int w = e[2];
             if(dist[u] != 1e9 && dist[v] > dist[u] + w){
                 return {-1};
             }
        }return dist;
	}
};

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> vis(V,0);
        vector<int> dist(V,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        int sum = 0;
        while(!pq.empty()){
            auto[w,u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            sum += w;
            for(auto i:adj[u]){
                int v = i[0];
                int wt = i[1];
                if(vis[v]) continue;
                pq.push({dist[v],v});
                
            }
        }return sum;
    }   
};


class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n,0);
        size.assign(n,1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUpr(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUpr(parent[u]);
    }

    bool find(int u, int v) {
        return findUpr(u) == findUpr(v);
    }


    void unionByRank(int u, int v) {
        int ulp_u = findUpr(u);
        int ulp_v = findUpr(v);
        if(u == v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
       
    }
};


// Prim's Algo

class Solution{
    public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        vector<int> vis(n,0),dist(n,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sum = 0;
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto[wt,u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            sum+= wt;
            for(auto i:adj[u]){
                int v = i[0], wt = i[1];
                if(vis[v]) continue;
                pq.push({dist[v],v});
            }
        }return sum;
    }   
};

// Kruskals 

class DSU{
public:
    vector<int> parent,rankV;

    DSU(int n){
        parent.resize(n);
        iota(all(parent),0);
        rankV.assign(n,0);
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }return parent[x];
    }

    bool unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rankV[x] < rankV[y]) swap(x,y);
        parent[y] = x;
        if(rankV[x] == rankV[y]) rankV[x]++;
        return true;
    }
};

class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;
        for(int i = 0; i < V; i++){
            for(auto e:adj[i]){
                if(i < e[0])
                edges.push_back({e[1],i,e[0]});
            }
        }sort(all(edges));
        DSU dsu(V);
        int sum = 0;
        for(auto e:edges){
            if(dsu.unite(e[1],e[2])){
                sum+=e[0];
            }
        }return sum;
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }vector<int> vis(n,0);
        function<void(int)> dfs = [&](int x){
            vis[x] = 1;
            for(auto i:adj[x]){
                if(!vis[i]) dfs(i);
            }
        };
        int compo = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                compo++;
            }
        } return n - compo;
    }
};





class Solution {
    #define Fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Fast_IO;
        unordered_map<string,string> parent;
        unordered_map<string,vector<string>> edges;
        function<int()> get_random = [](){
            static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
            static uniform_int_distribution<int> dist(1, 1000000);
            return dist(gen);
        };
        for(auto &acc : accounts){
            string name = acc[0];
            if(parent.find(name) == parent.end()){
                parent[name] = name;
            } else {
                string new_name = name + "#" + to_string(get_random());
                parent[new_name] = name;
                name = new_name;
            }
            for(int i = 1; i < acc.size(); i++){
                edges[name].push_back(acc[i]);
                edges[acc[i]].push_back(name);
            }
        }
        unordered_map<string,int> vis;
        vector<vector<string>> ans;
        function<void(string, vector<string>&)> dfs =
        [&](string u, vector<string>& temp){
            vis[u] = 1;
            if(parent.find(u) == parent.end())   
                temp.push_back(u);
            for(auto &v : edges[u]){
                if(!vis[v]) dfs(v, temp);
            }
        };
        for(auto &it : parent){
            string node = it.first;
            if(vis[node]) continue;
            vector<string> emails;
            dfs(node, emails);
            sort(emails.begin(), emails.end());
            vector<string> temp;
            temp.push_back(it.second);
            temp.insert(temp.end(), emails.begin(), emails.end());
            ans.push_back(temp);
        }return ans;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];
        vector<int> dist(n + 1,1e9);
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0,k}); // dist, node
        while(!pq.empty()){
            auto[d,u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v,w]:adj[u]){
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v],v});
                }
            }
        }int maxi = *max_element(dist.begin() + 1,dist.end());
        return maxi == 1e9 ? -1 : maxi;
    }
};

class Solution{
public:
    int minimumMultiplications(vector<int> &arr,int start,int end){
        const int MOD = 100000;
        vector<int> dist(MOD, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while(!pq.empty()){
            auto [step, cur] = pq.top();
            pq.pop();
            if(cur == end) return step;
            if(step > dist[cur]) continue;
            for(int x : arr){
                int v = (cur * x) % MOD;
                if(dist[v] > step + 1){
                    dist[v] = step + 1;
                    pq.push({step + 1, v});
                }
            }
        }
        return -1;
    }
};


#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rankv;
public:
    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rankv[x] < rankv[y]) swap(x, y);
        parent[y] = x;
        if (rankv[x] == rankv[y]) rankv[x]++;
        return true;
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<array<int,3>> edges;

        for (int u = 0; u < V; u++) {
            for (auto &it : adj[u]) {
                int v = it[0], w = it[1];
                if (u < v)
                    edges.push_back({w, u, v});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(V);
        int sum = 0;

        for (auto &e : edges) {
            if (dsu.unite(e[1], e[2]))
                sum += e[0];
        }

        return sum;
    }
};


class Solution{
    public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        vector<int> vis(n,0), dist(n,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sum = 0;
        dist[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto[wt, u] = pq.top(); pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            sum+=wt;
            for(auto i:adj[u]){
                int v = i[0], wt = i[1];
                if(vis[v]) continue;
                pq.push({dist[v],v});
            }
        }return sum;
    }   
};

class DSU{
public:
    vector<int> parent,rank;

    DSU(int n){
        parent.resize(n);
        iota(all(parent),0);
        rank.assign(n,0);
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x,y);
        parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
        return true;   
    }
};

class Solution{
    public:
    int spanningTree(int n, vector<vector<int>> adj[]){
        vector<array<int,3>> edges;
        for(int i = 0; i < n; i++){
            for(auto e:adj[i]){
                int v = e[0], w = e[1];
                if(i < v){
                    edges.push_back({w,i,v});
                }
            }
        }sort(all(edges));
        DSU dsu(n);
        int sum = 0;
        for(auto e:edges){
            if(dsu.unite(e[1],e[2])){
                sum += e[0];
            }
        }return sum;
    }   
};



class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }vector<int> vis(n,0);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(int v:adj[u]) if(!vis[v]) dfs(v);
        };
        int components = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i);
                components++;
            }
        }return n - components;
    }
};


class Solution{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sz = n * m;
        vector<int> parent(sz), rankv(sz, 0);
        vector<int> vis(sz, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> findp = [&](int x){
            if(parent[x] != x) parent[x] = findp(parent[x]);
            return parent[x];
        };
        auto unite = [&](int x, int y){
            x = findp(x);
            y = findp(y);
            if(x == y) return false;
            if(rankv[x] < rankv[y]) swap(x, y);
            parent[y] = x;
            if(rankv[x] == rankv[y]) rankv[x]++;
            return true;
        };
        int cnt = 0;
        vector<int> ans;
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {-1, 0, 1, 0};
        for(auto &v : A){
            int r = v[0], c = v[1];
            int id = r * m + c;
            if(vis[id]){
                ans.push_back(cnt);
                continue;
            }
            vis[id] = 1;    
            cnt++;
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int nid = nr * m + nc;
                    if(vis[nid]){
                        if(unite(id, nid)) cnt--;
                    }
                }
            }ans.push_back(cnt);
        }return ans;
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int sz = n * n;
        vector<int> parent(sz), size(sz,1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x){
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };

        function<bool(int,int)> unite = [&](int x,int y){
            x = find(x);
            y = find(y);
            if(x == y) return false;
            if(size[x] < size[y]) swap(x,y);
            parent[y] = x;
            size[x] += size[y];
            return true;
        };

        int dr[] = {0,1,0,-1};
        int dc[] = {-1,0,1,0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    int id = i * n + j;
                    for(int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc]){
                            unite(id, nr * n + nc);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < sz; i++){
            if(parent[i] == i) ans = max(ans, size[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> seen;
                    int cur = 1;
                    for(int k = 0; k < 4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc]){
                            int p = find(nr * n + nc);
                            if(seen.insert(p).second) cur += size[p];
                        }
                    }
                    ans = max(ans, cur);
                }
            }
        }return ans;
    }
};


class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        int dr[] = {0,1,0,-1};
        int dc[] = {-1,0,1,0};

        while(!pq.empty()){
            auto [t, cell] = pq.top(); pq.pop();
            int r = cell.first, c = cell.second;
            if(r == n-1 && c == n-1) return t;
            if(t > dist[r][c]) continue;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    int nt = max(t, grid[nr][nc]);
                    if(nt < dist[nr][nc]){
                        dist[nr][nc] = nt;
                        pq.push({nt, {nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
