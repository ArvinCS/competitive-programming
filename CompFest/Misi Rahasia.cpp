#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

bool friends[21][21];
us n, m;

int solve(vector<us> picked, int currentVer){
	if(currentVer > n){
		int conn = 0;
		for(us x=0;x<picked.size();x++){
			for(us y=x+1;y<picked.size();y++){
				if(x == y) continue;
				conn += friends[picked[x]][picked[y]];
			}
//			cout << picked[x] << " ";
		}
//		cout << "= " << conn << "\n";
		if(conn == picked.size()*(picked.size()-1)/2){
			return picked.size();
		} else {
			return 0;
		}
	}
	
	int ans = solve(picked, currentVer+1);
	picked.push_back(currentVer);
	ans = max(ans, solve(picked, currentVer+1));
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> m;
	
	fill(friends[0], friends[0]+(n+1)*2, false);
	
	while(m--){
		us tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		
		friends[tmp1][tmp2] = true;
		friends[tmp2][tmp1] = true;
	}
	
	vector<us> picked;
	
	cout << solve(picked, 1) << "\n";
    return 0;
}

