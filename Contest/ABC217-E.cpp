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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int q;
	cin >> q;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	queue<int> que;
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int val;
			cin >> val;
			
			que.push(val);
		} else if(t == 2){
			if(pq.empty()){
				cout << que.front() << "\n";
				que.pop();
			} else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		} else {
			while(!que.empty()){
				pq.push(que.front());
				que.pop();
			}
		}
	}
	
    return 0;
}

