#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	int a[n], idx[n];
	for(int x=0;x<n;x++){
		a[x] = x;
		idx[a[x]] = x;
	}
	
	while(q--){
		int p;
		cin >> p;
		
		p--;
		if(idx[p]+1 < n){
			int lst = a[idx[p]+1];
			
			swap(a[idx[p]], a[idx[p]+1]);
			swap(idx[p], idx[lst]);
		} else {
			int lst = a[idx[p]-1];
			
			swap(a[idx[p]], a[idx[p]-1]);
			swap(idx[p], idx[lst]);
		}
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << a[x]+1;
	}
	cout << "\n";
    return 0;
}

