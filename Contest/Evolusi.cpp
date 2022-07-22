#include <iostream>
#include <vector>

using namespace std;

vector<string> name;
//bool visited[10000];

int getIndex(string dest){
	for(int x=0;x<name.size();x++){
		if(name[x] == dest){
			return x;
		}
	}
	return -1;
}

vector<string> search(vector<int> adj[], int from, int to){
	vector<string> vec;
	vec.push_back(name[from]);
	for(int x=0;x<adj[from].size();x++){
		if(adj[from][x] == to){
			vec.push_back(name[adj[from][x]]);
			break;
		} else {
			vector<string> tmp = search(adj, adj[from][x], to);
			if(tmp.back() == name[to]){
				vec.insert(end(vec), begin(tmp), end(tmp));
				break;
			}
		}
	}
	return vec;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int m, n;
	cin >> m >> n;
	
	vector<int> adj[m];
	
	string p, c;
	for(int x=0;x<n;x++){
		cin >> p >> c;
		int indexP = getIndex(p), indexC = getIndex(c);
		if(indexP == -1){
			name.push_back(p);
			indexP = name.size() - 1;
		}
		if(indexC == -1){
			name.push_back(c);
			indexC = name.size() - 1;
		}
		
		adj[indexP].push_back(indexC);
	}
	
	fill(begin(visited), end(visited), false);
	
	string from, to;
	cin >> from >> to;
	
	vector<string> result = search(adj, getIndex(from), getIndex(to));
		
	if(result.back() == to){
		for(int x=0;x<result.size();x++){
			cout << result[x] << "\n";
		}
	} else {
		result = search(adj, getIndex(to), getIndex(from));
		if(result.back() == from){
			for(int x=0;x<result.size();x++){
				cout << result[x] << "\n";
			}
		} else {
			cout << "TIDAK MUNGKIN\n";
		}
	}
	
    return 0;
}
