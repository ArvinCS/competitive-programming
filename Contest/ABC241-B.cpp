#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int b[m];
	for(int x=0;x<m;x++){
		cin >> b[x];
	}
	
	sort(a, a+n);
	sort(b, b+m);
	
	bool possible = true;
	int pos = 0;
	for(int x=0;x<m;x++){
		while(pos < n && a[pos] != b[x]){
			pos++;
		}
		if(pos == n){
			possible = false;
			break;
		}
		pos++;
	}
	
	cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}

