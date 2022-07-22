#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k, q;
	cin >> n >> k >> q;
	
	int a[k];
	for(int x=0;x<k;x++){
		cin >> a[x];
	}
	
	while(q--){
		int pos;
		cin >> pos;
		
		pos--;
		if(pos+1 == k || a[pos]+1 < a[pos+1]){
			if(a[pos] < n) a[pos]++;
		}
	}
	
	for(int x=0;x<k;x++){
		if(x > 0) cout << " ";
		cout << a[x];
	}
	cout << "\n";
    return 0;
}

