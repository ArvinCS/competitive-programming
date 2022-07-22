#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	ui data[n];
	for(ui x=0;x<n;x++) cin >> data[x];
	
	sort(data, data+n);
	
	ui ans[n];
	fill(ans, ans+n, 0);
	
	ui i = 0, cnt = 0;
	for(ui x=1;x<n;x+=2){
		ans[x] = data[i++];
		if(x != n-1) cnt++;
	}
	for(ui x=0;x<n;x++){
		if(ans[x] == 0){
			ans[x] = data[i++];
		}
	}
	
	cout << cnt << "\n";
	for(ui x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
	
    return 0;
}

