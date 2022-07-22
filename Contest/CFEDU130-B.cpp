#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	ll p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	sort(p, p+n);
	
	for(int x=1;x<n;x++){
		p[x] += p[x-1];
	}
	
	while(q--){
		int a, b;
		cin >> a >> b;
		
		cout << (n-(a-b)-1 >= 0 ? p[n-(a-b)-1] : 0) - (n-a-1 >= 0 ? p[n-a-1] : 0) << "\n";
	}
    return 0;
}

