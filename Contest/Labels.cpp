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
	
	int tmp, highest = 1;
	vector<int> ans;
	
	for(ui x=0;x<n-1;x++){
		cin >> tmp;
		ans.push_back(tmp + (x > 0 ? ans[x-1] : 1));
		highest = max(highest, ans[x]);
	}
	
	if(highest != n){
		cout << "-1\n";
	} else {
		cout << "1";
		for(ui x=0;x<n-1;x++){
			cout << " " << ans[x];
		}
		cout << "\n";
	}
	
    return 0;
}

