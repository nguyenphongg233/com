#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ii DL1,DL2,UR1,UR2;


signed main(){
	
	cin>>DL1.X>>DL1.Y>>UR1.X>>UR1.Y>>DL2.X>>DL2.Y>>UR2.X>>UR2.Y;
	
	if(UR2.X < DL1.X)swap(DL1,DL2),swap(UR1,UR2);
	
	// hinh chu nhat thu nhat luon nam trc hinh 2 trong he toa do 
	
	 if(DL1.Y <= DL2.Y <= UR1.Y || DL1.Y <= UR2.Y <= UR1.Y || DL2.Y <= DL1.Y <= UR2.Y || DL2.Y <= UR1.Y <= UR2.Y)return cout<<(DL2.X - UR1.X) * (DL2.X - UR1.X),0;
	 
	 
	 ii DR1 = {DL1.X,UR1.Y};
	 ii UL2 = {UR2.X,DL2.Y};
	 
	 ll minx = (DR1.X - UL2.X) * (DR1.X - UL2.X) + (DR1.Y - UL2.Y + 1) * (DR1.Y - UL2.Y + 1);
	 minx = min(minx,(UR1.X - DL2.X) * (UR1.X - DL2.X) + (UR1.Y - DL2.Y) * (UR1.Y - DL2.Y));
	 
	 cout<<minx;
	 
	
	
}