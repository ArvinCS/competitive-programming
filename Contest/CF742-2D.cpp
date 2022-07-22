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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	us t;
	cin >> t;
	
	while(t--){
		int n, m, sum;
		cin >> sum >> n;
				
		vector<int> v;
		int tmp = sum;
		while(tmp > 0){
			v.push_back(tmp%10);
			tmp /= 10;
		}
		
		bool pass[1005];
		fill(pass, pass+1005, false);
		
		priority_queue<int, vector<int>, greater<int>> pq;
		ll pw = 1;
		for(int x=0;x<v.size();x++){
			if(v[x] > 0){
				while(v[x] > 0){
					pq.push(pw);
					v[x]--;
				}
			}
			pw *= 10;
		}
		
		vector<int> ans;
		
		while(pq.size()+ans.size() < n){
			int val = pq.top();
			pq.pop();
						
			if(val == 1){
				ans.push_back(val);
				continue;
			}
			
			int sz = pq.size()+ans.size();
			int cnt = min(10, n-sz);
			
			for(int y=1;y<cnt;y++){
				pq.push(val/10);
			}
			pq.push(val/10 * (10-cnt+1));
		}
		
		while(!pq.empty()){
			ans.push_back(pq.top());
			pq.pop();
		}
		
		while(ans.size() > n){
			ans[ans.size()-2] += ans[ans.size()-1];
			ans.pop_back();
		}
		
		for(int x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	}

    return 0;
}

