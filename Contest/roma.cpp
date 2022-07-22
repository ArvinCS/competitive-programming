#include <iostream>
#include <vector>

using namespace std;

int n, l, t;

int search(int from, int to, vector<int> jalan[], vector<int> tol[]){
	int visitTime[n+1], weight[n+1];

	for(int x=0;x<=n;x++){
		visitTime[x] = -1;
		weight[x] = 0;
	}
	
	vector<int> queue;

	visitTime[from] = 0;
	queue.push_back(from);
	
	int ans = 10000001;
	while(!queue.empty()){
		int curNode = queue.front();
		queue.erase(queue.begin());
		
		if(curNode == to && weight[curNode] <= 1){
			ans = min(ans, visitTime[curNode]);
			cout << "ans: " << ans << " w: " << weight[curNode] << "\n";
		}
		for(int x=0;x<jalan[curNode].size(); x++){
			if(visitTime[jalan[curNode][x]] == -1 || (visitTime[jalan[curNode][x]] > visitTime[curNode] + 1) || (weight[curNode] < weight[jalan[curNode][x]])){
				visitTime[jalan[curNode][x]] = visitTime[curNode] + 1;
				weight[jalan[curNode][x]] = weight[curNode];
				queue.insert(queue.begin(), jalan[curNode][x]);
//				queue.push_back(jalan[curNode][x]);
			}
		}

		for(int x=0; x<tol[curNode].size(); x++){
			if(visitTime[tol[curNode][x]] == -1 || visitTime[tol[curNode][x]] > visitTime[curNode] + 1){
				visitTime[tol[curNode][x]] = visitTime[curNode] + 1;
				weight[tol[curNode][x]]++;
				queue.push_back(tol[curNode][x]);
//				queue.insert(queue.begin(), tol[curNode][x]);
			}
		}
//		cout << curNode << "-> " << jalan[curNode].size() << " " << tol[curNode].size()<< "\n";
	}
	//cout << visitTime[3] << "\n";
	//cout << "ticket: " << useTicket[to] << "\n";
	return visitTime[to];
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		
	int from, to;
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
