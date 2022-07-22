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
		ui n, k;
		cin >> n >> k;
		
		pair<ui, ui> points[n];
		for(ui x=0;x<n;x++) cin >> points[x].first;
		for(ui x=0;x<n;x++) cin >> points[x].second;
		
		sort(points, points+n);	
		
		int left[n], right[n];
		fill(left, left+n, 0);
		fill(right, right+n, 0);
		
		int j = n-1;
		for(int x=n-1;x>=0;x--){
			while(j >= 0 && points[j].first - points[x].first > k) j--;
			right[x] = j-x+1;
			if(x+1 < n) right[x] = max(right[x], right[x+1]);
		}
		
		j = 0;
		for(ui x=0;x<n;x++){
			while(j < n && points[x].first - points[j].first > k) j++;
			left[x] = x-j+1;
			if(x > 0) left[x] = max(left[x], left[x-1]);
		}
		
		int ans = 1;
		for(ui x=0;x<n-1;x++){
			ans = max(ans, left[x] + right[x+1]);
		}
		cout << ans << "\n";
	}
	
    return 0;
}

