#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], cnt[n];
	fill(cnt, cnt+n, 0);
	
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x]--;
		
		cnt[a[x]]++;	
	}
	
	int ans = a[n-1];
	for(int x=0;x+1<n;x++){
		if(a[x] > a[x+1]){
			ans = a[x];
			break;
		}
	}
	
	bool space = false;
	for(int x=0;x<n;x++){
		if(a[x] != ans){
			if(space) cout << " ";
			cout << a[x]+1;
			space = true;
		}
	}
	cout << "\n";
    return 0;
}

