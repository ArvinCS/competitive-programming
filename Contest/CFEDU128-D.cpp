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
	
	prefix<ll, int> prefix[n];
	for(int x=0;x<n;x++){
		prefix[x] = (x > 0 ? prefix[x-1] : {0, 0});
		if(a[x] == 0){
			prefix[x].second++;
		} else {
			prefix[x].first += a[x];
		}
	}
	
	// max prefix - min prefix + 1
	// how to maximize, and minimize some prefixes?
	
	ll need = prefix[n-1].first;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if(prefix[x].second > 0 && prefix[y].second > 0){
				
			} else if(prefix[x].second == 0){ // [=0, >=0]
				
			} else if(prefix[y].second == 0){ // [=0, =0]
				
			}
		}
	}
    return 0;
}

