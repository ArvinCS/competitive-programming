#include <iostream>
#include <vector>

using namespace std;

short n, weight[501];
int l, t, ans = 100000001, visitTime[501];
bool romaNeighbours[501];

void dfs(short from, short to, vector<short> jalan[], vector<short> tol[]){
	if(from == to){
		ans = min(ans, visitTime[from]);
		return;
	}
	if(visitTime[from] + 1 >= ans) return;
	
	for(int x=0;x<jalan[from].size();x++){
		if(visitTime[jalan[from][x]] == -1 || visitTime[jalan[from][x]] >= visitTime[from]){
			visitTime[jalan[from][x]] = visitTime[from] + 1;
			weight[jalan[from][x]] = weight[from];
			//cout << "dfs from " << from << " to " << jalan[from][x] << "\n";
			dfs(jalan[from][x], to, jalan, tol);
		}
	}
	
	if(weight[from] == 0){
		for(int x=0;x<tol[from].size();x++){
			if(visitTime[tol[from][x]] == -1 || visitTime[tol[from][x]] > visitTime[from] + 1){
				visitTime[tol[from][x]] = visitTime[from] + 1;
				weight[tol[from][x]]++;
				//cout << "dfs from " << from << " to " << tol[from][x] << "\n";
				dfs(tol[from][x], to, jalan, tol);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(short x=1;x<=501;x++){
		visitTime[x] = -1;
		weight[x] = 0;
		romaNeighbours[x] = false;
	}
	
	short from, to;
	cin >> n >> l >> t >> from >> to;
	
	vector<short> jalan[n+1], tol[n+1];
	
	for(int x=0;x<l;x++){
		short tmp, tmp2;
		cin >> tmp >> tmp2;
		jalan[tmp].push_back(tmp2);
		jalan[tmp2].push_back(tmp);
	}
	
	for(int x=0;x<t;x++){
		short tmp, tmp2;
		cin >> tmp >> tmp2;
		tol[tmp].push_back(tmp2);
		tol[tmp2].push_back(tmp);
	}
	
	visitTime[from] = 0;
	dfs(from, to, jalan, tol);
	cout << ans << "\n";
	
    return 0;
}
