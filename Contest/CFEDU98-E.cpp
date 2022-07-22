#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	pair<int, int> p[m];
	for(int x=0;x<m;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
	}
	
	sort(p, p+m, [&](pair<int, int> a, pair<int, int> b) -> bool {
		return (a.first+a.second) < (b.first+b.second);
	});
	
	int suffix[m+1];
	fill(suffix, suffix+m+1, 0);
	
	for(int x=0;x+k<=n;x++){
		int sum = 0;
		for(int y=m-1;y>=0;y--){
			sum += max(0, min(x+k-1, p[y].second)-max(x, p[y].first)+1);
			suffix[y] = max(suffix[y], sum);
		}
	}
	
	int ans = 0;
	for(int x=0;x+k<=n;x++){
		int sum = 0;
		for(int y=0;y<m;y++){
			sum += max(0, min(x+k-1, p[y].second)-max(x, p[y].first)+1);
			ans = max(ans, sum+suffix[y+1]);
		}
	}
	
	cout << ans << "\n";
    return 0;
}

