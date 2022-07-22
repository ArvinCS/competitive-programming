#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 2005;

int parrent[maxN];

int getParrent(int x){
	return parrent[x];
}

void merge(int x, int y){
	parrent[x] = y;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	vector<int> v;
	int a[n][n];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cin >> a[x][y];
			
			if(x != y){
				v.push_back(a[x][y]);
			}
		}
	}
	
	sort(v.rbegin(), v.rend());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	int ans[4*n], idx = n;
	fill(ans, ans+4*n, -1);
	for(int x=0;x<4*n;x++){
		parrent[x] = x;
	}
	for(int x=0;x<n;x++){
		ans[x] = a[x][x];
	}
	
	ans[idx] = v.front();
	for(int x=0;x<n;x++){
		parrent[x] = idx;
	}
	idx++;
	
	for(auto val : v){
		if(val == v.front()) continue;
		
		vector<int> head;
		ans[idx] = val;
		head.push_back(idx++);
		
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				if(a[x][y] == val){
//					cout << val << " " << x << " " << y << "\n";
					for(int i=0;i<head.size();i++){
						int p = head[i];
						
						bool ok = true;
						for(int z=0;z<n;z++){
							if(x == z || y == z) continue;
							if(getParrent(z) == p && (a[z][x] > val || a[z][y] > val)){
//								cout << val << " " << x << " " << y << " " << z << " " << p << "\n";
								ok = false;
								break;
							}
						}
						
						if(ok){
							if(ans[getParrent(x)] > val){ // make sure the new employee is connected if lowerlevel employee has supervisor
								merge(p, getParrent(x));
							}
							
							merge(x, p);
							merge(y, p);
							break;
						} else {
							if(p == head.back()){
								merge(idx, getParrent(p));
								ans[idx] = val;
								head.push_back(idx++);
							}
						}
					}
				}
			}
		}
	}
	
	cout << idx << "\n";
	for(int x=0;x<idx;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
	
	cout << n+1 << "\n";
	for(int x=0;x<idx;x++){
		if(getParrent(x) != x){
			cout << x+1 << " " << getParrent(x)+1 << "\n";
		}
	}
//	for(int x=0;x<2*n;x++){
//		cout << x << " " << parrent[x] << "\n";
//	}
    return 0;
}

