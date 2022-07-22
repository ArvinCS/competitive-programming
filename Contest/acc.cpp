#include <iostream>
#include <vector>

using namespace std;

int n, l, t, visitTime[501];
bool useTicket[501];

bool canExplore(int node, vector<int> jalan[], vector<int> tol[]){
	for(int x=0;x<jalan[node].size();x++){
		if(visitTime[jalan[node][x]] == -1){
			return true;
		}
	}
	return false;
}

int search(int from, int to, vector<int> jalan[], vector<int> tol[]){
	bool useTicket[n+1];

	for(int x=0;x<=n;x++){
		visitTime[x] = -1;
		useTicket[x] = false;
	}
	visitTime[from] = 0;
	
	vector<int> queue;
	queue.push_back(from);

	while(!queue.empty()){
		int curNode = queue.front();
		queue.erase(queue.begin());

		for(int x=0;x<jalan[curNode].size(); x++){
			if(visitTime[jalan[curNode][x]] == -1 || visitTime[jalan[curNode][x]] > visitTime[curNode] + 1){
				visitTime[jalan[curNode][x]] = visitTime[curNode] + 1;
				useTicket[jalan[curNode][x]] = useTicket[curNode];
				queue.insert(queue.begin(), jalan[curNode][x]);
			}
		}
		if(!useTicket[curNode]){
			//bool found = false;
			for(int x=tol[curNode].size()-1; x>=0; x--){
				if(visitTime[tol[curNode][x]] == -1 || visitTime[tol[curNode][x]] > visitTime[curNode] + 1){
					if(tol[curNode][x] == to || canExplore(tol[curNode][x], jalan, tol)){
						visitTime[tol[curNode][x]] = visitTime[curNode] + 1;
						useTicket[tol[curNode][x]] = true;
						queue.push_back(tol[curNode][x]);
						//if(!found) found = canExplore(tol[curNode][x], jalan, tol);
					}
				}
			}
		}
//		cout << curNode << "-> " << jalan[curNode].size() << " " << tol[curNode].size()<< "\n";
	}
//	cout << "ticket: " << useTicket[to] << "\n";
	return visitTime[to];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int from,to;
	cin >> n >> l >> t >> from >> to;

	vector<int> jalan[n+1], tol[n+1];

	for(int x=0;x<l;x++){
		int tmp, tmp2;
		cin >> tmp >> tmp2;
		jalan[tmp].push_back(tmp2);
		jalan[tmp2].push_back(tmp);
	}

	for(int x=0;x<t;x++){
		int tmp, tmp2;
		cin >> tmp >> tmp2;
		tol[tmp].push_back(tmp2);
		tol[tmp2].push_back(tmp);
	}

	cout << search(from, to, jalan, tol) << "\n";
    return 0;
}
