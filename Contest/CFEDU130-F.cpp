#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 2e4 + 5;
const int maxK = 11;

vector<int> adj[2*(maxN * 100 + maxK)];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int mx = (n-1)*100 + k;
	
	auto add = [&](int i, int j, bool fi = false, bool fj = false) -> void {
		adj[(i + (fi ? mx : 0))].push_back(j + (fj ? 0 : mx));
		adj[j + (fj ? mx : 0)].push_back(i + (fi ? 0 : mx));
	};
	
	for(int x=0;x<m;x++){
		int type;
		cin >> type;
		
		if(type == 1){
			int idx;
			cin >> idx;
			
			add(idx-1, idx-1, true, true);
		} else if(type == 2){
			int idx1, idx2;
			cin >> idx1 >> idx2;
			
			int val;
			cin >> val;
			
			for(int a=0;a<k;a++){
				for(int b=a;b<k;b++){
					if(a+b > val){
						add(idx1*100 + a, idx2*100 + b, false, true);
						add(idx1*100 + a, idx2*100 + b, true, false);
						add(idx1*100 + a, idx2*100 + b, true, true);
					}
				}
			}
		} else if(type == 3){
			int idx1, idx2;
			cin >> idx1 >> idx2;
			
			int val;
			cin >> val;
			
			for(int a=0;a<k;a++){
				for(int b=a;b<k;b++){
					if(a+b < val){
						add(idx1*100 + a, idx2*100 + b, false, true);
						add(idx1*100 + a, idx2*100 + b, true, false);
						add(idx1*100 + a, idx2*100 + b, true, true);
					}
				}
			}
		}
	}
	
	for(int x=0;x<n;x++){
		for(int a=0;a<k;a++){
			for(int b=a+1;b<k;b++){
				add(x*100 + a, x*100 + b);
			}
		}
	}
	
	
    return 0;
}

