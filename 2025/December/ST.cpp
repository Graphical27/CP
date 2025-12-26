
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
