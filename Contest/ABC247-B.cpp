#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	pair<string, string> p[n];
	for(int x=0;x<n;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	bool possible = true;
	for(int x=0;x<n;x++){
		bool a = true, b = true;
		for(int y=0;y<n;y++){
			if(x == y) continue;
			if(p[y].first == p[x].first || p[y].second == p[x].first){
				a = false;
			}
			if(p[y].first == p[x].second || p[y].second == p[x].second){
				b = false;
			}
		}
		possible &= (a || b);
	}
	
	cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}

