#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

const long long N = 15;

ll n,m,q;
ll mustvis[N];
ll dist[MAX][MAX];
vector<ii> adj[MAX];

void bfs(ll u){
    priority_queue<ii,vector<ii>,greater<ii>> h;
    dist[u][u] = 0;
    
    h.push({0,u});
    for(auto v : adj[u])h.push({v.Y,v.X});

    while(!h.empty()){
        ll x = h.top().Y;
        ll y = h.top().X;
        
        h.pop();
        if(y != dist[u][x])continue;

        for(auto v : adj[x]){
            ll x1 = v.X;
            ll y1 = v.Y;
            if(dist[u][x1] > dist[u][x] + y1){
                dist[u][x1] = dist[u][x] + y1;
                h.push({dist[u][x1],x1});

            }
        }
    }
}

ll dp[(1 << 11)][11];


ll f(ll mask,ll end){

    if(mask == (1 << q) - 1)return dp[mask][end] = dist[1][mustvis[end]];

    if(dp[mask][end] != -1)return dp[mask][end];
    ll res = INF;
    for(ll i = 0;i < q;i++){
        if(end == i || (1 << i) & mask)continue;
            res = min(res,f(mask | (1 << i),i) + dist[mustvis[end]][mustvis[i]]);
        
    }
    return dp[mask][end] = res;
}

bool check(ll u){
    bool visited[MAX];

    memset(visited,0,sizeof visited);
    visited[u] = 1;

    deque<ll> d;

    d.push_back(u);

    while(!d.empty()){
        ll id = d.front();

        d.pop_front();

        visited[id] = 1;

        for(auto v : adj[id]){
            if(!visited[v.X])d.push_back(v.X),visited[v.X] = 1;
        }


    }

    for(ll i = 0;i < q;i++){
        if(!visited[mustvis[i]])return 0;
    }

   
    if(!visited[1])return 0;


    return 1;
}

signed main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    
    for(ll i = 0;i < q;i++){
        cin>>mustvis[i];
    }    

    for(ll i = 1; i<= n;i++){
        for(ll j = 1;j <= m;j++){
            dist[i][j] = INF;
        }
    }
    
    for(ll i = 1,u,v,c;i <= m;i++){
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
        dist[u][v] = dist[v][u] = min(dist[u][v],c);
    }
    

    for(ll i = 1;i <= n;i++)bfs(i);

    ll res = INF;

    memset(dp,-1,sizeof dp);

    for(ll i = 0;i < q;i++){
        ll x = f(1 << i,i);
        res = min(res,x + dist[1][mustvis[i]]);
    }


    if(!check(1))cout<<-1;
    else 

    cout<<res;

    
    
}
