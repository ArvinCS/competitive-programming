#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	
	ll rem = p%w;
	
	ll visit[w];
	fill(visit, visit+w, -1);
	visit[0] = 0;
	
	ll cur = d, cnt = 1;
	while(true){
		if(visit[cur] != -1) break;
		visit[cur] = cnt;
		
		cur += d;
		cur %= w;
		cnt++;
	}
	
	if(visit[rem] == -1){
		cout << "-1\n";
		return 0;
	}
	
	ll a = (p-visit[rem]*d)/w, b = visit[rem];
	ll c = n-a-b;
	
	if(a < 0 || c < 0){
		cout << "-1\n";
		return 0;
	}
	
	cout << a << " " << b << " " << c << "\n";
    return 0;
}

