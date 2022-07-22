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
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		vector<int> ans;
		for(int x=0;x<n;x++){
			int left = 0, right = 0;
			for(int y=0;y<=x;y++){
				if(s[y] == '1') left++;
			}
			for(int y=x+1;y<n;y++){
				if(s[y] == '0') right++;
			}
			
			if(left == right){
				if(left == 0){
					ans.clear();
					break;
				}
				
				vector<int> v;
				for(int y=0;y<=x;y++){
					if(s[y] == '1') v.push_back(y+1);
				}
				for(int y=x+1;y<n;y++){
					if(s[y] == '0') v.push_back(y+1);
				}
				swap(ans, v);
			}
		}
		
		if(ans.size() == 0){
			cout << "0\n";
			continue;
		}
		
		cout << "1\n";
		cout << ans.size();
		for(int x=0;x<ans.size();x++){
			cout << " " << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

