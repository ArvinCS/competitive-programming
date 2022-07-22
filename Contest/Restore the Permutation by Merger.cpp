#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
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
		us n, tmp;
		cin >> n;
		
		unordered_set<us> cnt;
		vector<us> p;
		bool first = true;
		for(int x=0;x<n*2;x++){
			cin >> tmp;
			if(cnt.count(tmp) == 0){
				cout << (first ? "" : " ") << tmp;
				cnt.insert(tmp);
				first = false;
			}
		}	
		cout << "\n";
	}
	
    return 0;
}
