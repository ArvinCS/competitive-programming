#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int mx = 500000, mxPrefix = 600000;

ull prefix[mxPrefix];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	unordered_set<ui> exist;
	ui data[n];
	for(int x=0;x<n;x++){
		cin >> data[x];
		prefix[x] = data[x];
		if(x > 0) prefix[x] += prefix[x-1];	
		exist.insert(data[x]);
	}
	
	vector<ui> ans;
	for(int x=0;x<k-1;x++){
		ans.push_back(data[x]);
	}
	
	int i = k-1, x = k-1, size = n;
	while(x < size){
		ull sum = prefix[x] - (x-k >= 0 ? prefix[x-k] : 0);
		if(sum % k == 0){
			ans.push_back(data[i]);
			i++;
			if(i == n) break;
		} else {
			sum -= (prefix[x] - prefix[x-1]);
			size++;
			int newNum = k - (sum % k);
			while(exist.count(newNum)){
				newNum += k;
			}
			if(newNum > mx){
				cout << "-1\n";
				return 0;
			}
			exist.insert(newNum);
			
			for(int y=size-1;y>=x;y--){
				prefix[y] = prefix[y-1] + newNum; 	
			}
			ans.push_back(newNum);
		}
		x++;
	}
	
	
	if(ans.size() <= mx && i >= n){
		cout << ans.size() << "\n";
		for(ui x=0;x<ans.size();x++){
			if(x > 0) cout << " ";
			cout << ans[x];
		}
		cout << "\n";
	} else {
		cout << "-1\n";
	}
    return 0;
}

