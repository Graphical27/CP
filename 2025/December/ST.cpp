
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
