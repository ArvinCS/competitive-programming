#include <iostream>
#include <vector>

using namespace std;

short n;
int l, t,  best = 100001;

vector<short> jalan[501], tol[501];

int search(int i, short from, short to, bool visited[], bool tiket){
	if(from == to){
		return i;
	}
	if(i >= best) return best;
	
	visited[from] = true;
	if(tiket){
		for(short x=0;x<tol[from].size();x++){
			if(!visited[tol[from][x]]){
				visited[tol[from][x]] = true;
				best = min( best, search(i+1, tol[from][x], to, visited, false));
				visited[tol[from][x]] = false;
			}
		}
	}

	for(short x=0;x<jalan[from].size();x++){
		if(!visited[jalan[from][x]]){
			visited[jalan[from][x]] = true;
			best = min(best, search(i+1, jalan[from][x], to, visited, tiket));
			visited[jalan[from][x]] = false;
		}
	}
	
	return best;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		
	short from, to;
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
	fill(visited, visited+n+1, false);
	cout << search(0, from, to, visited, true) << "\n";
    return 0;
}
