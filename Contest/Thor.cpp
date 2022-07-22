#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int maxN = 3 * 10e4;

ui n;
vector<int> tree(maxN, 0);

ll query(int index){
	int total = 0;
	while(index > 0){
		total += tree[index];
		index -= index & (-index);
	}
	return total;
}

void update(int index, int val){
	while(index <= n){
		tree[index] = max(0, tree[index]+val);
		index += index & (-index);
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	
	ui q;
	cin >> n >> q;
	
	ui cnt[n+1];
	int lastPos = 0;
	fill(cnt,cnt+n+1,0);
	
	vector<pair<ui, bool>> logs;
	queue<int> notifs[n+1];
	
	while(q--){
		us type;
		cin >> type;
		
		if(type != 3){
			int x;
			cin >> x;
			
			if(type == 1){
				logs.push_back({x, true});
				update(x, 1);
				cnt[x]++;
				notifs[x].push(logs.size()-1);
			} else {
				update(x, -cnt[x]);
				cnt[x] = 0;
				while(!notifs[x].empty()){
					if(lastPos == notifs[x].front()){
						lastPos++;
					}
					logs[notifs[x].front()].second = false;
					notifs[x].pop();
				}
			}
		} else {
			int t;
			cin >> t;
			
			if(lastPos+1 <= t){
				for(int x=lastPos;x<t;x++){
					if(!logs[x].second) continue;
					update(logs[x].first, -1);
					cnt[logs[x].first]--;
					logs[x].second = false;
				}
				lastPos = t;
			}
		} 
		cout << query(n) << "\n";
	}	
	
    return 0;
}

