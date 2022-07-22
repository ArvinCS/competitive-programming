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

	int n;
	cin >> n;
	
	int a[n];
	bool same = true;
	for(int x=0;x<n;x++){
		cin >> a[x];
		if(x > 0 && a[x-1] != a[x]){
			same = false;
		}
	}
	
	if(same){
		cout << "YES\n";
		cout << "0\n";
		return 0;
	}
	
	vector<tuple<int, int, int>> ans;
	
	for(int x=0;x+2<n;x+=2){
		int tmp = a[x]^a[x+1]^a[x+2];
		a[x] = a[x+1] = a[x+2] = tmp;
		
		ans.push_back(make_tuple(x, x+1, x+2));
	}
	
	int pos = n-1;
	for(int x=n-1;x>=0;x--){
		if(x%2 != 0 && x > 0 && a[x-1] == a[x]) continue;
		pos = x;
		break;
	}
	
//	cout << pos << "\n";
	
	for(int x=pos-2;x>=0;x-=2){
		int tmp = a[x]^a[x+1]^a[x+2];
		
		a[x] = a[x+1] = a[x+2] = tmp;
		ans.push_back(make_tuple(x, x+1, x+2));
	}
	
	bool valid = true;
	for(int x=1;x<n;x++){
		if(a[x-1] != a[x]){
			valid = false;
			break;
		}
	}
	
	if(!valid){
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	cout << ans.size() << "\n";
	for(auto t : ans){
		cout << get<0>(t)+1 << " " << get<1>(t)+1 << " " << get<2>(t)+1 << "\n";
	}
    return 0;
}

