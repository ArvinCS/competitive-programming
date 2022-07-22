#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	priority_queue<int, vector<int>, greater<int>> pq1;
	priority_queue<int> pq2;
	
	int lazy = 0;
	int mn = 0, mx = 0;
	for(int x=0;x<n;x++){
		if(a[x]){
			lazy--;
			
			pq1.push(-1-lazy);
			pq2.push(-1-lazy);
		} else {
			lazy++;
			
			pq1.push(1-lazy);
			pq2.push(1-lazy);
		}
		
		mx = max(mx, pq2.top()+lazy);
		mn = min(mn, pq1.top()+lazy);
	}
	
	cout << mx-mn+1 << "\n";
    return 0;
}

