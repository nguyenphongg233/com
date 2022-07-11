#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e6 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

ll n;
ii UL,UR,DL,DR;
ii a[MAX];

signed main(){
	cin>>n;
	ll x,y;
	cin>>x>>y;
	a[1] = {x,y};
	UL = UR = DL = DR = {x,y};
	for(ll i = 2,x,y;i <= n;i++){
		cin>>x>>y;
		a[i] = {x,y};
		if(x <= UL.X && y >= UL.Y)UL = {x,y};
		if(x <= DL.X && y <= DL.Y)DL = {x,y};
		if(x >= UR.X && y >= UR.Y)UR = {x,y};
		if(x >= DR.X && y <= DR.Y)DR = {x,y};
		
		
	}
	
	set<ii> st;
	
	st.insert(DL);
	st.insert(UL);
	st.insert(UR);
	st.insert(DR);
	
	ll xi = 0;
	ll yi = 0;
	ll cnt = 0;
	

	for(auto v : st){
		xi += v.X;
		yi += v.Y;
		cnt++;
	}
	
	
	if(xi % cnt == 0)xi /= cnt;
	else xi = xi/cnt + 1;
	if(yi % cnt == 0)yi /= cnt;
	else yi = yi / cnt + 1;
	
	ll res= 0 ;
	
	//cout<<xi<<" "<<yi<<" ";
	//cout<<UL.X<<" "<<UL.Y<<"\n";
	//cout<<UR.X<<" "<<UR.Y<<"\n";
	//cout<<DL.X<<" "<<DL.Y<<"\n";
	//cout<<DR.X<<" "<<DR.Y<<"\n";
	cout<<xi<<" "<<yi<<" ";
	for(ll i = 1;i <= n;i++){
		res = max(res,abs(a[i].X - xi) + abs(a[i].Y - yi));
	}
	
	cout<<res;
}
