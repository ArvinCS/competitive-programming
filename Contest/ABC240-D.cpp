#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int cnt = 0;
	int a[n];
	vector<pair<int, int>> v;
	for(int x=0;x<n;x++){
		cin >> a[x];
		
		cnt++;
		if(v.empty() || v.back().second != a[x]){
			v.push_back({cnt, a[x]});
		} else {
			if(cnt-v.back().first+1 == a[x]){
				v.pop_back();
				cnt -= a[x];
			}
		}
		
		cout << cnt << "\n";
	}
	
    return 0;
}

