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
		int n, q;
		cin >> n >> q;
		
		string s;
		cin >> s;
		
		int a[n];
		for(int x=0;x<n;x++){
			a[x] = (s[x] == '+' ? 1 : -1);
		}
		
		vector<pair<int, int>> v;
		int prefix[n];
		for(int x=0;x<n;x++){
			prefix[x] = (a[x] * (x % 2 == 0 ? 1 : -1)) + (x-1 >= 0 ? prefix[x-1] : 0);
			v.push_back({prefix[x] + (x > 0 ? prefix[x-1] : 0), x});
		}
		
		sort(v.begin(), v.end());
		
		for(int i=1;i<=q;i++){
			int left, right;
			cin >> left >> right;
			
			left--; right--;
			
			int sum = prefix[right] - (left-1 >= 0 ? prefix[left-1] : 0);
						
			if(sum == 0){
				cout << 0 << "\n";
			} else if(sum % 2 == 0){
				sum = prefix[right] - prefix[left];
				
				auto it = lower_bound(v.begin(), v.end(), make_pair(2*prefix[left] + sum, left+1));
				
				cout << 2 << "\n";
				cout << left+1 << " " << (*it).second+1 << "\n";
			} else {
				auto it = lower_bound(v.begin(), v.end(), make_pair(2*(left > 0 ? prefix[left-1] : 0) + sum, left));
				
				cout << 1 << "\n";
				cout << (*it).second+1 << "\n";
			}
		}
	}

    return 0;
}

