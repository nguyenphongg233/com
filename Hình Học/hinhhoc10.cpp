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





struct line{
    ll a,b,c;
};

//phuong trinh duong thang biet toa do 2 diem 

line calc(ii a,ii b){
    ll x = a.X - b.X;
    ll y = a.Y - b.Y;

    ll tmp = -y;
    y = x;
    x = tmp;

    ll no = __gcd(abs(x),abs(y));

    y /= no;
    x /= no;

    ll aw = x,bw = y;

    // x,y -> phap tuyen

    return {aw,bw,-aw * a.X - bw * a.Y};
}



signed main(){
    
    cout<<""

    
    
}