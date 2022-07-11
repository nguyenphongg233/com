#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll a,b;
ll k = 1;

signed main(){
    
    cin>>a>>b;
    
    ll n = a / __gcd(a,b) * b;
    
    while(k * n < a + b)k++;
    
    cout<<k * n - a - b;
    
    
    
}