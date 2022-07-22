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
		int n;
		cin >> n;
		
		vector<int> v;
		for(int x=1;x*x<=n;x++){
			if(n%x == 0){
				if(x != 1) v.push_back(x);
				if(n/x != x && n/x > 1) v.push_back(n/x);
			}
		}
		
		sort(v.begin(), v.end());
		
		int pos = 0;
		for(int x=1;x<v.size();x++){
			while(pos < x && __gcd(v[pos], v[x]) != 1){
				swap(v[(pos+1)%v.size()], v[x]);
				pos++;
			}
		}
		
		int cnt = 0;
		if(__gcd(v.front(), v.back()) == 1){
			cnt++;
		}
		
		for(int x=0;x<v.size();x++){
			if(x > 0) cout << " ";
			cout << v[x];
		}
		cout << "\n";
		cout << cnt << "\n";
	}

    return 0;
}

