#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

bool ask(int x, int y){
	cout << "? " << x+1 << " " << y+1 << endl;
	
	string ans;
	cin >> ans;
	
	return (ans == "Yes");
}

void answer(int x, int y){
	cout << "! " << x+1 << " " << y+1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	int k[n];
	for(int x=0;x<n;x++){
		cin >> k[x];
	}
	
	while(true){
		int zero = 0;
		for(int x=0;x<n;x++){
			if(k[x] == 0){
				zero++;
				k[x] = -1;
			}
		}
		
		if(zero == 0) break;
		for(int x=0;x<n;x++){
			if(k[x] > 0){
				k[x] -= zero;
			}
		}
	}
	
	for(int x=0;x<n;x++){
		if(k[x] > 0){
			v.push_back({k[x], x});
		}
	}
	
	sort(v.begin(), v.end());
	
	if(v.size() == 0){
		answer(-1, -1);
		return 0;
	}
	
	if(v.front().first == v.back().first){
		answer(v.front().second, v.back().second);
		return 0;
	}
	
	for(int l=n;l>=0;l--){
		for(int x=0;x<v.size();x++){
			for(int y=x+1;y<v.size();y++){
				if(v[y].first-v[x].first == l){
					if(ask(v[y].second, v[x].second)){
						answer(v[x].second, v[y].second);
						return 0;
					}
				}
			}
		}
	}
	
	answer(-1, -1);
    return 0;
}

