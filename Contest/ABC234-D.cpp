#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int p[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
	}
	
	priority_queue<int> low;
	priority_queue<int, vector<int>, greater<int>> high;
	
	for(int x=0;x<k-1;x++){
		high.push(p[x]);
		
		while(high.size() > k){
			low.push(high.top());
			high.pop();
		}
	}
	
	for(int x=k-1;x<n;x++){
		high.push(p[x]);
		
		while(high.size() > k){
			low.push(high.top());
			high.pop();
		}
		
		cout << high.top() << "\n";
	}
    return 0;
}

