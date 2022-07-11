#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;


ll dx[] = {0,0,-1,1};
ll dy[] = {-1,1,0,0};

struct State{
    ll i,j,v;
};

bool solve(){

    ll n,m;
    char a[MAX][MAX];
    ll step[MAX][MAX][10];

    cin>>n>>m;

    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= m;j++){
            cin>>a[i][j];
            if(a[i][j] == '.')a[i][j] = '0';
        }
    }

    memset(step,-1,sizeof step);

    step[1][1][0] = 0;

    deque<State> d;
    d.push_back({1,1,0});
    while(!d.empty()){

        
        ll i = d.front().i;
        ll j = d.front().j;
        ll v = d.front().v;

        //cout<<i<<" "<<j<<" "<<v<<"\n";

        d.pop_front();
        if(i == n && j == m && v < 10)return cout<<"possible",0;

        for(ll s = 0;s < 4;s++){
            ll x = i + dx[s];
            ll y = j + dy[s];

            if(x < 1 || x > n || y < 1 || y > m || a[x][y] == '#')continue;
            if(a[x][y] <= '9' && a[x][y] >= '0' && a[x][y] - '0' + v >= 10)continue;
            if(a[x][y] <= '9' && a[x][y] >= '0' && step[x][y][v + a[x][y] - '0'] != -1)continue;
            if(a[x][y] <= '9' && a[x][y] >= '0')step[x][y][v + a[x][y] - '0'] = step[i][j][v] + 1,d.push_back({x,y,v + a[x][y] - '0'});
            if(a[x][y] == 'S')step[x][y][0] = step[i][j][v] + 1,d.push_back({x,y,0});

        }

    }

    return cout<<"imposible",0;


}

signed main(){
    

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solve();
        cout<<"\n";
    }    
    
    
}