#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	pair<int, int> p[m];
	for(int x=0;x<m;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	for(int i=0;i<=1000;i++){
		int new_a[n];
		for(int x=0;x<n;x++){
			new_a[x] = a[x];
			
			for(int y=0;y<n;y++){
				if(x == y) continue;
				
				new_a[x] += (a[x])	
			}
		}
		swap(a, new_a);
	}
    return 0;
}

