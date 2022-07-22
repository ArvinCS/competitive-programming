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
	
	us t;
	cin >> t;
	
	while(t--){
		short n, k;
		cin >> n >> k;
		
		unordered_set<int> exist;
		vector<int> data;
		for(us x=0;x<n;x++){
			short tmp;
			cin >> tmp;
			
			if(exist.count(tmp)) continue;
			data.push_back(tmp);
			exist.insert(tmp);
		}
		
		if(k == 1){
			if(data.size() <= k) cout << "1\n";
			else cout << "-1\n";
		} else {
			int tmp = (data.size()+(k-1)-2)/(k-1);
			cout << max(tmp, 1) << "\n";
		}
	}
	
    return 0;
}

