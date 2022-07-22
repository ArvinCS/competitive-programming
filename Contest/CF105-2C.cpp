#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	
	if(n > 1 && a == n-1 && b == 0){
		cout << "-1\n";
		return 0;
	}
	
	ll sum = 1;
	vector<int> ans;
	ans.push_back(1);
	if(b == 0){
		if(a > 0){
			ans.push_back(1);
			sum++;
		}
	}
	
	for(int x=0;x<b;x++){
		ans.push_back(sum+1);
		sum += sum+1;
	}
	
	for(int x=0;x<a;x++){
		ans.push_back(ans.back()+1);
		sum += ans.back();
	}
	
	for(int x=ans.size();x<n;x++){
		ans.push_back(1);
	}
	
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

