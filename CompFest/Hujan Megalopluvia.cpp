#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int mxN = 1000000 + 5;
int data[mxN];
deque<int> pos;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n, k;
	cin >> n >> k;
	
	for(ui x=1;x<=n;x++) cin >> data[x];
	data[0] = data[n+1] = inf_int;
	
	pos.push_back(k);
	
	bool isRight = (k == 0 || data[k] > data[k+1]);
	int left = k, right = pos.front();
	vector<int> ans;
	
	while(1 <= left || right <= n){
		if(isRight){
			int cur = ++right;
			while(pos.size() > 1){
				if(data[pos.front()] < data[cur]){
					ans.push_back(pos.front());
					pos.pop_front();
				} else {
					break;
				}
			}	
			if(pos.size() == 1 && data[pos.back()] < data[cur]) isRight = false;
			pos.push_front(cur);
		} else {
			int cur = --left;
			while(pos.size() > 1){
				if(data[pos.back()] < data[cur]){
					ans.push_back(pos.back());
					pos.pop_back();
				} else {
					break;
				}
			}
			if(pos.size() == 1 && data[pos.front()] < data[cur]) isRight = true;
			pos.push_back(cur);
		}
	}
	
	cout << ans[0];
	for(ui x=1;x<ans.size();x++){
		cout << " " << ans[x]; 
	}
	cout << "\n";
    return 0;
}

