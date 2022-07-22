#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	ll k;
	cin >> n >> k;
	
	ll a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	ll parent[n];
	fill(parent, parent+n, -1);
	
	parent[0] = 0;
	ll cur = 0, lst = -1;
	while(true){
		ll prv = cur;
		cur += a[cur%n];
		
		if(parent[cur%n] != -1){
			lst = prv%n;
			break;
		}
		parent[cur%n] = prv%n;
	}
	
	ll sum = 0;
	ll cnt = 0;
	while(true){
		cnt++;
		sum += a[lst%n];
		if(lst%n == cur%n){
			break;
		}
		
		lst = parent[lst%n];
	}
	
	ll need = 0;
	ll sum2 = 0;
	for(int x=0;x<k;x++){
		sum2 += a[sum2%n];
		
		if(sum2 == cur){
			sum2 += sum*((k-x-1)/cnt);
			need = (k-x-1)%cnt;
			break;
		}
	}
	for(int x=0;x<need;x++){
		sum2 += a[sum2%n];
	}
	
	cout << sum2 << "\n";
    return 0;
}

