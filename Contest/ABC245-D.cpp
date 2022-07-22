#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int a[n+1], c[n+m+1];
	for(int x=0;x<=n;x++){
		cin >> a[x];
	}
	for(int x=0;x<=n+m;x++){
		cin >> c[x];
	}
	
	int b[m+1];
	fill(b, b+m+1, -1);
	
	for(int x=n+m;x>=0;x--){
		int ask = -1;
		for(int y=0;y<=n;y++){
			int z = x-y;
			if(z < 0 || z > m) continue;
			
			if(b[z] == -1){
				ask = z;
				continue;
			}
			
			c[x] -= a[y]*b[z];
		}
		
		cout << x << " " << ask << " " << c[x] << "\n";
		if(ask != -1){
			b[ask] = c[x]/a[x-ask];
		}
	}
	
	for(int x=0;x<=m;x++){
		if(x > 0) cout << " ";
		cout << b[x];
	}
	cout << "\n";
    return 0;
}

