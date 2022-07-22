#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		pair<int, int> p[n];
		for(int x=0;x<n;x++){
			cin >> p[x].first >> p[x].second;
		}
		
		int pos, cur;
		cin >> pos >> cur;
		
		sort(p, p+n, greater<pair<int, int>>());
		
		bool possible = true;
		int ans = 0;
		priority_queue<int> pq;
		for(int x=0;x<n;x++){
			if(p[x].first > pos) continue;
			
			int dist = pos-p[x].first;
			while(dist > cur && !pq.empty()){
				cur += pq.top();
				pq.pop();
				ans++;
			}
			
			if(dist > cur){
				possible = false;
				break;
			}
			
			cur -= dist;
			pos = p[x].first;
			pq.push(p[x].second);
		}
		
		if(!possible){
			cout << "-1\n";
			continue;
		}
		
		while(pos > cur && !pq.empty()){
			cur += pq.top();
			pq.pop();
			ans++;
		}
		
		if(pos > cur){
			cout << "-1\n";
			continue;
		}
		
		cout << ans << "\n";
	}
    return 0;
}

