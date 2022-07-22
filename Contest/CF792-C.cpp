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
		int n, m;
		cin >> n >> m;
		
		int a[n][m];
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				cin >> a[x][y];
			}
		}
		
		bool dif[m];
		fill(dif, dif+m, false);
		for(int x=0;x<n;x++){
			for(int y=0;y+1<m;y++){
				if(a[x][y] > a[x][y+1]){
					dif[y] = true;
				}
			}
		}
		
		vector<int> v;
		for(int x=0;x<m;x++){
			if(dif[x]){
				v.push_back(x);
			}
		}
		
		if(v.empty()){
			cout << "1 1\n";
			continue;
		}
		if(v.size() > 2){
			cout << "-1\n";
			continue;
		}
		
		int ans1 = -1, ans2 = -1;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int y=0;y<v.size();y++){
					if(v[y]+i >= m) break;
					for(int z=y;z<v.size();z++){
						if(v[z]+j >= m) break;
						if(v[z]+j < v[y]+i) continue;
						
						bool valid = true;
						for(int x=0;x<n;x++){
							int lst = 0;
							for(int c=0;c<m;c++){
								if(c == v[y]+i){
									if(a[x][v[z]+j] < lst){
										valid = false;
									}
									lst = a[x][v[z]+j];
								} else if(c == v[z]+j){
									if(a[x][v[y]+i] < lst){
										valid = false;
									}
									lst = a[x][v[y]+i];
								} else {
									if(a[x][c] < lst){
										valid = false;
									}
									lst = a[x][c];
								}
							}
						}
						
						if(valid){
							ans1 = v[y]+i+1;
							ans2 = v[z]+j+1;
						}
					}
				}
			}
		}
		
		if(ans1 == -1){
			cout << "-1\n";
		} else {
			cout << ans1 << " " << ans2 << "\n";
		}
	}
	
    return 0;
}

