#include <iostream>
#include <vector>

using namespace std;

#define inf_int 1e9
#define inf_ll 1e18

vector<short> jalan[501], tol[501];
short from, to, n;
int l, t, ans = inf_int, value[501];

bool search(int currentIndex, int i, bool ticket, bool visited[]){
	bool update = false;
	if(currentIndex == to){
//		cout << currentIndex << "\n";
		update = ans > i;
		ans = min(ans, i);
		return update;
	}

	for(int x=0;x<jalan[currentIndex].size();x++){
		if(!visited[jalan[currentIndex][x]]){
			if(i > ans - 1 || i+1 > value[jalan[currentIndex][x]]){
				continue;
			}
			visited[jalan[currentIndex][x]] = true;
			if(search(jalan[currentIndex][x], i+1, ticket, visited)){
				value[jalan[currentIndex][x]] = min(value[jalan[currentIndex][x]], i);
				update = true;
			}
			visited[jalan[currentIndex][x]] = false;
		}
	}
	
	if(ticket){
		for(int x=0;x<tol[currentIndex].size();x++){
			if(!visited[tol[currentIndex][x]]){
				if(i > ans - 1 || i+1 > value[tol[currentIndex][x]]){
					continue;
				}
				visited[tol[currentIndex][x]] = true;
				if(search(tol[currentIndex][x], i+1, false, visited)){
					value[tol[currentIndex][x]] = min(value[tol[currentIndex][x]], i);
					update = true;
				}
				visited[tol[currentIndex][x]] = false;
			}
		}
	}
	return update;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		
	cin >> n >> l >> t >> from >> to;
	
	short tmp, tmp2;
	for(int x=0;x<l;x++){
		cin >> tmp >> tmp2;
		jalan[tmp].push_back(tmp2);
		jalan[tmp2].push_back(tmp);
	}
	
	for(int x=0;x<t;x++){
		cin >> tmp >> tmp2;
		tol[tmp].push_back(tmp2);
		tol[tmp2].push_back(tmp);
	}
	
	bool visited[n+1];
	for(short x=1;x<=n;x++){
		visited[x] = false;
		value[x] = inf_int;
	}
	
	visited[from] = true;
	value[from] = 0;
	search(from, 0, true, visited);
	cout << ans << "\n";
    return 0;
}
