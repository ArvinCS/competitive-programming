#include <iostream>
#include <vector>

#define inf_int 1e9
#define inf_ll 1e18

using namespace std;

short n, from, to;

struct Data {
	short path = 0, curNode;
	vector<short> history;
	bool visited[501], ticket;
};

short search(vector<short> jalan[], vector<short> tol[]){	
	short memo[n+1];
	fill(memo, memo+n+1, -1);
	vector<Data> queue;	
	
	Data initial;
	initial.curNode = from;
	initial.ticket = false;
	fill(initial.visited, initial.visited+n+1, false);
	initial.visited[from] = true;
	
	queue.push_back(initial);
	
	short ans = 501;
	while(!queue.empty()){
		Data curData = queue.front();
		short curNode = curData.curNode;
		queue.erase(queue.begin());
		
		if(curData.path >= ans) continue;
		if(curNode == to){
			ans = curData.path;
			int i = 0;
			for(int x=0;x<curData.history.size();x++){
				memo[curData.history[x]] = i;
				i++;
			}
			continue;
		}
		
		if(!curData.ticket){
			for(int x=0; x<tol[curNode].size(); x++){
				if(!curData.visited[tol[curNode][x]] && (memo[tol[curNode][x]] == -1 || memo[tol[curNode][x]] > curData.path + 1)){
					Data tmp = curData;
					tmp.visited[tol[curNode][x]] = true;
					tmp.path++;
					tmp.curNode = tol[curNode][x];
					tmp.ticket = true;
					tmp.history.push_back(curNode);
					queue.insert(queue.begin(), tmp);
				}
			}
		}
		
		for(int x=0; x<jalan[curNode].size(); x++){
			if(!curData.visited[jalan[curNode][x]] && (memo[jalan[curNode][x]] == -1 || memo[jalan[curNode][x]] > curData.path + 1)){
				Data tmp = curData;
				tmp.visited[jalan[curNode][x]] = true;
				tmp.path++;
				tmp.curNode = jalan[curNode][x];
				tmp.history.push_back(curNode);
				queue.insert(queue.begin(), tmp);
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int l, t;
	cin >> n >> l >>  t >> from >> to;
	
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
	
	cout << search(jalan, tol) << "\n";
	
    return 0;
}
