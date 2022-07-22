#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 3e7 + 5;

bool exist[maxA];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, m;
	cin >> n >> m;
	
	fill(exist, exist+maxA, false);
	
	int a[n];
	for(int x=0;x<n;x++){
		a[x] = x+1;
		exist[a[x]] = true;
	}
	
	ll cnt = 0;
	for(int x=0;x<n;x++){
		for(int y=x+1;y<n;y++){
			if(exist[a[x]+a[y]]){
				cnt++;
			}
		}
	}
	
	if(m > cnt){
		cout << "-1\n";
		return 0;
	}
	
	fill(exist, exist+maxA, false);
	cnt = 0;
	
	for(int x=0;x<2;x++){
		a[x] = x+1;
		exist[a[x]] = true;
	}
	
	for(int x=2;x<n;x++){
		int left = 1, right = 5e3, ans = 1;
		
		while(left <= right){
			int mid = (left+right) >> 1;
			
			int val = 0;
			for(int y=0;y<x;y++){
				if(a[x-1]+mid-a[y] > a[y]){
					if(exist[a[y]] && exist[(a[x-1]+mid)-a[y]]){
						val++;
					}
				}
			}
			
//			cout << x << " " << mid << " " << cnt << " " << val << "\n";
			if(cnt+val >= m){
				ans = max(ans, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
//		cout << x << " -> " << ans << "\n";
		for(int y=0;y<x;y++){
			if(a[x-1]+ans-a[y] > a[y]){
				if(exist[a[y]] && exist[(a[x-1]+ans)-a[y]]){
					cnt++;
				}
			}
		}
		
		a[x] = a[x-1]+ans;
		exist[a[x-1]+ans] = true;
		
//		cout << cnt << "\n";
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << a[x];
	}
	cout << "\n";
    return 0;
}
