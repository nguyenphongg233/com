#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll t,n;
ll cnt[MAX];
ll m;
signed main(){
	
	cin>>t;
	
	while(t--){
		cin>>n>>m;
		vi a(m);
		for(auto &x : a)cin>>x;
		
		sort(a.begin(),a.end());
		
		
		ll minx = 0;
		for(auto x : a)cnt[x]++;
		
		vi op;
		ll free = 0;
		for(ll i = 1;i <= n;i++){
			
			if(cnt[i] != 0)op.push_back(cnt[i]);
			else free++;
		}
		
		sort(op.begin(),op.end());
		
	
		ll time = 0;
		for(ll i = 0;i < op.size();i++){
			//cout<<i<<" "<<op[i]<<"\n";;
			if(op[i] <= time){
				free++;
				continue;
			}
			
			ll task = op[i] - time;
			
			ll cv = task / (2 + free);
			
			ll du = task % (2 + free);
			
			while(cv * (free + 2) + du < task)du++;
			
			//cout<<cv<<" "<<du<<"\n";
			
			
			ll time2 = cv * 2 + du;
			
			while(1){
			
			    cv++; 
			
			    ll du2 = task - cv * (free + 2);
			
			    //cout<<cv2<<" "<<du2<<"\n";
			    if(max(cv * 2 + du2,cv * 2) > time2)break;
			    time2 = min(time2,max(cv * 2 + du2,cv * 2));
			}
			time += time2;
			
			
			free++;
		}
		
		
		cout<<time<<'\n';
		
		
		for(ll i = 1;i <= n;i++){
			cnt[i] = 0;
		}
		
	}
	
}