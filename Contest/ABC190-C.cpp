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

const int maxM = 105;
int n, m, k;
pair<int, int> dish[maxM], p[20];

int solve(int index, int done[]){
	if(index == k){
		int cnt = 0;
		for(int x=0;x<m;x++){
			if(done[dish[x].first] > 0 && done[dish[x].second] > 0){
				cnt++;
			}
		}
		return cnt;
	}
	
	int ans = 0;
	
	done[p[index].first]++;
	ans = max(ans, solve(index+1, done));
	done[p[index].first]--;
	
	done[p[index].second]++;
	ans = max(ans, solve(index+1, done));
	done[p[index].second]--;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	for(int x=0;x<m;x++){
		cin >> dish[x].first >> dish[x].second;
	}
	
	cin >> k;
	
	for(int x=0;x<k;x++){
		cin >> p[x].first >> p[x].second;
	}
	
	int done[105];
	fill(done, done+105, 0);
	
	cout << solve(0, done) << "\n";
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

