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
	
	int n, m;
	cin >> n >> m;
	
	string a, b;
	cin >> a >> b;
	
	vector<int> v, w;
	bool row[n], col[m];
	for(int x=0;x<n;x++){
		row[x] = (a[x] == '1' ? 1 : 0);
		if(row[x]){
			v.push_back(x);
		}
	}
	for(int x=0;x<m;x++){
		col[x] = (b[x] == '1' ? 1 : 0);
		if(col[x]){
			w.push_back(x);
		}
	}
	
	if(v.empty() && w.empty()){
		cout << 0 << "\n";
		return 0;
	}
	if(!v.empty() && w.empty()){
		cout << m+v.size()-1 << "\n";
		return 0;
	}
	if(v.empty() && !w.empty()){
		cout << n+w.size()-1 << "\n";
		return 0;
	}
	
	int ans = max(m+v.size()-1, n+w.size()-1);
	int cnt = 0;
	for(int x=0;x<m;x++){
		if(col[x]){
			ans = max(ans, cnt+v[0]+(v.back()-v[0]+1)+m-x-1); // case 1
			ans = max(ans, cnt+v[0]+(n-v[0])); // case 5
			ans = max(ans, x+(v.back()-v[0]+1)+m-x-1); // case 1
			ans = max(ans, x+(n-v[0])); // case 5
			ans = max(ans, max(x, v[0]+cnt)+(n-v[0])); // case 3
			ans = max(ans, max(x, v[0]+cnt)+(n-v[0])); // case 3
			ans = max(ans, max(x, v[0]+cnt)+m-x); // case 4
			
			if(cnt > 0){
				ans = max(ans, max(v[0], w[0])+(x-w[0]+1)+(n-v[0]-1)); // case 2
//				cout << x << " -> " << ans << "\n";
			}
			cnt++;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

