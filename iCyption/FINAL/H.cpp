#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> list;
	bool digits[101];
	fill(digits, digits+101, false);
	vector<int> height[101];
	fill(height, height+101, vector<int>());
	int tmp;
	for(int x=1;x<=n;x++){
		cin >> tmp;
		if(!digits[tmp]){
			digits[tmp] = true;
			list.push_back(tmp);
		}
		height[tmp].push_back(x);
	}
	
	sort(list.begin(), list.end());
	
	unsigned long long ans = 0;
	for(int x=list.size()-1;x>=0;x--){
		int h = list[x];
		while(height[h].size() > 1){
			ans += (height[h][1] - 1) - height[h][0];
			height[h].erase(height[h].begin(), height[h].begin() + 1);
		}
	}
	cout << ans << "\n";
    return 0;
}
