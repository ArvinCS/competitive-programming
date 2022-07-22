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

int ask1(int l, int r, int x){
	l++; r++;
	cout << "? 1 " << l << " " << r << " " << x << endl;
	int ans;
	cin >> ans;
	
	return ans;
}

int ask2(int l, int r, int x){
	l++; r++;
	cout << "? 2 " << l << " " << r << " " << x << endl;
	int ans;
	cin >> ans;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		
		vector<pair<int, int>> check1, check2;
		for(int x=0;x+1<n;x+=2){
			int tmp = ask2(x, x+1, 1);
			if(tmp == 1){
				check1.push_back({x, x+1});	
			} else if(tmp == 2){
				check2.push_back({x, x+1});
			}
		}
		
		if(n&1){
			int tmp = ask2(0, n-1, 1);
			if(tmp == 1){
				check1.push_back({0, n-1});	
			} else if(tmp == 2){
				check2.push_back({0, n-1});
			}
		}
		
		if(check1.size() == 0){
			for(auto p : check2){
				int tmp = ask2(p.second, p.first, 1);
				if(tmp == 1){
					check1.push_back({p.second, p.first});
					break;
				}
			}
		}
		
		int ans[n];
		fill(ans, ans+n, -1);
		
		ans[check1[0].first] = 1;
		for(int x=0;x<n;x++){
			if(x == check1[0].first) continue;
			int tmp = ask1(check1[0].first, x, n-1);
			ans[x] = tmp;
		}
		
		cout << "!";
		for(int x=0;x<n;x++){
			cout << " ";
			cout << ans[x];
		}
		cout << endl;
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

