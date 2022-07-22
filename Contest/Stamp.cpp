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

vector<int> whites;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	bool a[n];
	fill(a, a+n, false);
	
	for(int x=0;x<m;x++){
		int tmp;
		cin >> tmp;
		
		a[tmp-1] = true;
	}
	
	if(m == 0){
		cout << "1\n";
		return 0;
	}
	
	ull cnt = 0;
	for(int x=0;x<n;x++){
		if(a[x] == 1){
			if(cnt > 0){
//				cout << x << "-" << cnt << "\n";
				whites.push_back(cnt);
			}
			cnt = 0;
		} else {
			cnt++;
		}
	}
	if(cnt > 0) whites.push_back(cnt);
	
	sort(whites.begin(), whites.end());
	
	ull ans = 0;
	for(int x=0;x<whites.size();x++){
		ans += (whites[x]+whites[0]-1)/whites[0];
	}
	
	cout << ans << "\n";
	
    return 0;
}

