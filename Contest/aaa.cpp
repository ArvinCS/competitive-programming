#include <iostream>
#include <vector>

using namespace std;

short n, from, to;
int l, t;

void search(vector<short> jalan[], vector<short> tol[], bool visited[]){
	int visitTime[n+1][2];
	bool useTicket[n+1][2];
	for(int x=0;x<=n;x++){
		visitTime[x][0] = -1;
		visitTime[x][1] = -1;
		useTicket[x][0] = false;
		useTicket[x][1] = false;
	}
	
	visitTime[from][0] = 0;
	visitTime[from][1] = 0;

	vector<short> queue;
	queue.push_back(from);
	
	while(!queue.empty()){
		for(short x=0;x<max(jalan[queue.front()].size(), tol[queue.front()].size());x++){
			if(x + 1 <= jalan[queue.front()].size() && visitTime[jalan[queue.front()][x]][0] == -1){ // lewat jalan
				int tmp = (useTicket[queue.front()][0] || useTicket[queue.front()][1]) ? visitTime[queue.front()][1] : 100001;
				visitTime[jalan[queue.front()][x]][0] = min(visitTime[queue.front()][0], tmp == -1 ? 100001 : tmp) + 1;
				useTicket[jalan[queue.front()][x]][0] = useTicket[queue.front()][0] || useTicket[queue.front()][1];
				queue.push_back(jalan[queue.front()][x]);
			} 
			
			if(x + 1 <= tol[queue.front()].size() && visitTime[tol[queue.front()][x]][1] == -1){ // lewat tol
				visitTime[tol[queue.front()][x]][1] = visitTime[queue.front()][0] + 1;
				useTicket[tol[queue.front()][x]][1] = true;
				queue.push_back(tol[queue.front()][x]);
			}
		}
		
		queue.erase(queue.begin());
	}
	
	//cout << visitTime[to][0] << " " << visitTime[to][1] << "\n";
	cout << min(visitTime[to][0], visitTime[to][1] == -1 ? 100001 : visitTime[to][1]) << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n >> l >> t >> from >> to;
	
	vector<short> jalan[n+1], tol[n+1];
	
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
	
	bool visited[n+1] = { false };
	visited[from] = true;
	
	search(jalan, tol, visited);
	
    return 0;
}
