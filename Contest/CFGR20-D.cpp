#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int a[n], b[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
			a[x]--;
		}
		for(int x=0;x<n;x++){
			cin >> b[x];
			b[x]--;
		}
		
		int last[n], last2[n];
		fill(last, last+n, -1);
		fill(last2, last2+n, -1);
		
		vector<int> v, w;
		vector<int> z[2][n];
		for(int x=n-1;x>=0;x--){
			if(last[a[x]] == -1){
				v.push_back(a[x]);
				last[a[x]] = x;
			}
			
			if(last2[b[x]] == -1){
				w.push_back(b[x]);
				last2[b[x]] = x;
			}
		}
		
		bool possible = true;
		for(int x=0;x<v.size();x++){
			if(v[x] != w[x]){
				possible = false;
			}
		}
		
		int cnt[n];
		fill(cnt, cnt+n, 0);
		
		for(int x=n-1;x>=0;x--){
			if(x == n-1 || a[x] != a[x+1]){
				z[0][a[x]].push_back(x);
			}
			if(x == n-1 || b[x] != b[x+1]){
				z[1][b[x]].push_back(x);
			}
		}
		
		for(int x=n-1;x>=0;x--){
			
		}
		
		if(possible){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

