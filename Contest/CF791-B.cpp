#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	pair<ll, int> a[n];
	for(int x=0;x<n;x++){
		cin >> a[x].first;
		a[x].second = -1;
	}
	
	ll sum = 0;
	for(int x=0;x<n;x++){
		sum += a[x].first;
	}
	
	int lst = -1;
	ll lstVal = -1;
	for(int x=0;x<q;x++){
		int t;
		cin >> t;
		
		if(t == 1){
			int pos;
			ll val;
			cin >> pos >> val;
			
			pos--;
			if(a[pos].second < lst){
				sum += val - lstVal;
			} else {
				sum += val - a[pos].first;
			}
			
			a[pos].first = val;
			a[pos].second = x;
		} else if(t == 2){
			ll val;
			cin >> val;
			
			sum = n*val;
			lst = x;
			lstVal = val;
		}
		
		cout << sum << "\n";
	}
	
    return 0;
}

