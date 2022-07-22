#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int sz = 450;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, h;
	cin >> n >> h;
	
	int cnt[h+1];
	fill(cnt, cnt+h+1, 0);
	
	int pending[sz][sz];
	fill(pending[0], pending[sz], 0);
	
	vector<pair<int, int>> v[h+1];
	for(int x=0;x<n;x++){
		int a, b;
		cin >> a >> b;
		
		if(b >= sz){
			for(int y=a;y<=h;y+=b){
				cnt[y]++;
			}
		} else {
			v[a].push_back({b, a%b});
		}
	}
	for(int x=1;x<=h;x++){
		for(auto p : v[x]){
			pending[p.first][p.second]++;
		}
		for(int y=1;y<sz;y++){
			int rem = x%y;
			cnt[x] += pending[y][rem];
		}
	}
	
	for(int x=1;x<=h;x++){
		if(x > 1) cout << " ";
		cout << cnt[x];
	}
	cout << "\n";
    return 0;
}

