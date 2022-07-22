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

const int maxN = 2e5 + 5;

int a[maxN];

void calc(int pos){
	int val = a[pos]^a[pos+1]^a[pos+2];	
	a[pos] = a[pos+1] = a[pos+2] = val;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int> v, ans;
		for(int x=0;x<n;x++){
			cin >> a[x];
			
			if(a[x] == 1) v.push_back(x);
		}
		
		bool possible = true;
		for(int x=v.size()-2;x>=0;x-=2){
			int dist = v[x+1]-v[x];
			if(dist <= 2){
				calc(v[x]);
				ans.push_back(v[x]);
			} else {
				if(dist % 2 == 0){
					int pos = v[x], mid = v[x]+3;
					
					calc(pos);
					ans.push_back(pos);
					
					pos += 4;
					while(pos+2 <= v[x+1]){
						calc(pos);
						ans.push_back(pos);
						
						pos += 3;
					}
					
					calc(mid-1);
					ans.push_back(mid-1);
					
					pos = mid-2;
					while(pos-1 >= v[x]){
						calc(pos-1);
						ans.push_back(pos-1);
						
						pos -= 2;
					}
					
					pos = mid+1;
					while(pos+2 <= v[x+1]){
						calc(pos);
						ans.push_back(pos);
						
						pos += 2;
					}
				} else {
					possible = false;
					break;
				}
			}
		}
		
		if(v.size() % 2 == 1){
				
		}
		
		for(int x=0;x<n;x++){
			if(a[x] == 1){
				possible = false;
				break;
			}
		}
		
		if(possible && ans.size() <= n){
			cout << "YES\n";
			cout << ans.size() << "\n";
			for(int x=0;x<ans.size();x++){
				if(x > 0) cout << " ";
				cout << ans[x]+1;
			}
			cout << "\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

