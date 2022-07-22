#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		long long n,x;
		int m;
		cin >> n >> x >> m;
		
		pair<int,int> operations[m];
		for(int x=0;x<m;x++) cin >> operations[x].first >> operations[x].second;
		
		long long l = x, r = x;
		for(int x=0;x<m;x++){
			if(operations[x].first < l && l <= operations[x].second) l = operations[x].first;
			if(operations[x].second > r && r >= operations[x].first) r = operations[x].second;
		}
		cout << r - l + 1 << "\n";
	}
    return 0;
}
