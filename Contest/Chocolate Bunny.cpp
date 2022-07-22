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
	
	if(n == 1){
		cout << "! 1" << endl;
	} else if(n == 2){
		int m;
		cout << "? 1 2" << endl;
		cin >> m;
		if(m == 0){
			cout << "! 2 1" << endl;
		} else {
			cout << "! 1 2" << endl;
		}
	} else {
		int found[n];
		fill(found, found+n, 0);
		deque<pair<int, int>> search;
		
		for(int x=1;x<=n;x++){
			search.push_back({x, 0});
		}
		
		while(true){
			deque<pair<int, int>> tmp;
			while(search.size() > 1){
				cout << "? " << search.front().first << " " << search.back().first << endl;
				int k1, k2;
				cin >> k1;
				
				cout << "? " << search.back().first << " " << search.front().first << endl;
				cin >> k2;
				
				if(k1 > k2){
					found[search.front().first-1] = k1;
					tmp.push_back(search.back());
				} else {
					found[search.back().first-1] = k2;
					tmp.push_front(search.front());
				}
				search.pop_front();
				search.pop_back();
			}
			if(search.size() == 1) tmp.push_front(search.front());
			if(tmp.size() == 1) break;
			search = tmp;
		}
				
		cout << "!";
		for(int x=0;x<n;x++){
			if(found[x] == 0) cout << " " << n;
			else cout << " " << found[x];
		}
		cout << endl;
	}
	
	
	
    return 0;
}

