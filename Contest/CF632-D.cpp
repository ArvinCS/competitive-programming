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

const int maxK = 3e6 + 5;

vector<int> ans[maxK];
vector<tuple<int, int, int>> v;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int a[n];
	for(int x=0;x<n;x++){
		a[x] = 1;
		if(s[x] == 'L'){
			a[x] *= -1;
		}
	}
	
	int turn = 0;
	while(true){
		bool move = false;
		int pos = 0;
		while(pos+1 < n){
			if(a[pos] == 1 && a[pos+1] == -1){
				move = true;
				v.push_back(make_tuple(turn, pos, pos+1));
				
				a[pos] *= -1;
				a[pos+1] *= -1;
				pos++;
			}
			pos++;
		}
		
		if(!move) break;
		turn++;
	}
	
	if(k < turn || k > v.size()){
		cout << "-1\n";
		return 0;
	}
	
	int cnt = 0, cur = 0;
	int lastTurn = get<0>(v[0]);
	
	int x = 0;
	for(;x<v.size();x++){
		if(cnt+(ans[cur].size() > 0)+(v.size()-x) == k){
			if(ans[cur].size() > 0){
				cnt++;
				cur++;
			}
			break;
		}
		
		if(lastTurn != get<0>(v[x])){
			cnt++;
			cur++;
			lastTurn = get<0>(v[x]);
		}
		ans[cur].push_back(get<1>(v[x]));
	}
	
	for(;x<v.size();x++){
		ans[cur++].push_back(get<1>(v[x]));
	}
	
	for(int x=0;x<k;x++){
		cout << ans[x].size();
		for(int y=0;y<ans[x].size();y++){
			cout << " " << ans[x][y]+1;
		}
		cout << "\n";
	}
    return 0;
}

