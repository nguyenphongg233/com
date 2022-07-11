#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// a.k.a 1 Dam Wrong Answer

using namespace std;

ll n,m,x1,x2,y1,y2;

signed main(){
    faster();
    cin>>n>>m>>x1>>y1>>x2>>y2;
    ll q = abs(x1-x2);
    ll p = abs(y1-y2);
    if((q % 2 == 0) && (p % 2 == 0))cout<<(p+q)/2;
    else cout<<-1;
    return 0;
}