#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int func(int x){
	return x >= 0 ? 1 : -1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	ll data[n], diff[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		if(x > 0) diff[x] = data[x] - data[x-1];
	}
	diff[0] = data[0];
	
	ll point = 0;
//	cout << "i: " << boundA << " | " << boundB << "\n";
	for(int x=1;x<n;x++){
		if(diff[x] > 0){
			point += diff[x];
		}
	}
//	cout << "\n";
	
	ll total = diff[0]+point;
	cout << (total+(1*(total >= 0)))/2 << "\n";
	
	int q;
	cin >> q;
	
	while(q--){
		int l, r;
		ll m;
		cin >> l >> r >> m;
		
//		for(int x=l-1;x<r;x++){
//			data[x] += m;
////			cout << data[x] << "-\n";
//			if(x == 0) continue;
//			if(x > 0 && diff[x] > 0){
//				point -= diff[x];
//			}
//			diff[x] = data[x] - data[x-1];
//			if(diff[x] > 0) point += diff[x];
//		}
		if(l > 1 && diff[l-1] > 0){
			point -= diff[l-1];
		}
		diff[l-1] += m;
		if(l > 1 && diff[l-1] > 0) point += diff[l-1];
		if(r < n){
			if(diff[r] > 0){
				point -= diff[r];
			}
			diff[r] -= m;
			if(diff[r] > 0) point += diff[r];
		}
		
//		
//		for(int x=0;x<n;x++) cout << diff[x] << " ";
//		cout << "\n";
//		cout << "-- " << boundA << " | " << boundB << "\n";
//		cout << (boundA+boundB)/2 << "\n";
//		cout << data[0] << " | " << point << "\n";
		ll total = diff[0]+point;
//		cout << "total: " << total << "\n";
//		for(int x=0;x<n;x++) cout << diff[x] << " ";
//		cout << "\n";
		cout << (total+(1*(total >= 0)))/2 << "\n";
	}
	
	return 0;
}

