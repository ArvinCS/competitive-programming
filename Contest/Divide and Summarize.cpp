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

const int maxA = 1e6 + 5;
const int maxN = 1e5 + 5;

bool possible[maxA];
int data[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		for(int x=0;x<n;x++){
			cin >> data[x];
		}

		sort(data, data+n);
		
		unordered_set<ull> ans;
		
		queue<pair<int, int>> q;
		q.push({0, n-1});
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
						
			int mid = (data[p.first]+data[p.second])/2, bound = -1;
			ull total = 0;
			
			for(int x=p.first;x<=p.second;x++) total += data[x];
			for(int x=p.first;x<=p.second;x++){
				if(data[x] <= mid){
					bound = x;
				} else {
					break;
				}
			}
			
			ans.insert(total);
			
			if(bound == -1 || bound == p.second) continue;
			
			q.push({p.first, bound});
			q.push({bound+1, p.second});
		}
		
		for(int i=0;i<m;i++){
			int s;
			cin >> s;
			
			if(ans.count(s)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

