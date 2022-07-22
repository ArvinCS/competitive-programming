#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}	
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	int cnt[5005][2];
	fill(cnt[0], cnt[5005], 0);
	
	for(int x=0;x<n;x++){
		cnt[a[x]][0]++;
		cnt[b[x]][1]++;
	}
	
	bool possible = true;
	for(int x=0;x<=5000;x++){
		if(cnt[x][0] != cnt[x][1]){
			possible = false;
			break;
		}
	}
	
	if(!possible){
		cout << "No\n";
		return 0;
	}
	
	for(int x=0;x<=5000;x++){
		if(cnt[x][0] > 1){
			cout << "Yes\n";
			return 0;
		}
	}
	
	for(int x=0;x<n;x++){
		bool ok = false;
		int pos = -1;
		for(int y=x;y<n;y++){
			if(b[x] == a[y]){
				if((y-x) % 2 == 0){
					ok = true;
					pos = y;
					break;
				} else {
					if((y+1 < n && y-1 >= x)){
						swap(a[y-1], a[y+1]);
						swap(a[y], a[y+1]);
						
						ok = true;
						pos = y+1;
						break;
					} else if(y+2 < n){
						swap(a[y], a[y+2]);
						swap(a[y+1], a[y+2]);
						
						ok = true;
						pos = y+1;
						break;
					} else if(y-2 >= x){
						swap(a[y-1], a[y]);
						swap(a[y-2], a[y]);
						
						ok = true;
						pos = y-1;
						break;
					}
				}
			}
		}
		
		
		if(!ok){
			possible = false;
			break;
		}
		
		vector<int> v;
		v.push_back(a[pos]);
		for(int y=x;y<n;y++){
			if(pos == y) continue;
			v.push_back(a[y]);
		}
		for(int y=x;y<n;y++){
			a[y] = v[y-x]; 
		}
		
	}
	
	for(int x=0;x<n;x++){
		if(a[x] != b[x]){
			possible = false;
		}
	}
	
	cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}

