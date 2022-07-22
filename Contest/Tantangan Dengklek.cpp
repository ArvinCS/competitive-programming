#include <iostream>
#include <vector>
#include <unordered_set> 
#include <queue>

using namespace std;

#define ull unsigned long long
#define ll long long
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

string swap(short i, short n, string arr){
	short start = i, end = i+(n-1);
	char tmp;
	while(start < end){
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
	return arr;
}

unordered_set<string> visited;

bool isSorted(string data){
	for(int i=1;i<data.size();i++){
		if(data[i-1] >= data[i]){
			return false;
		}
	}
	return true;
}

int solve(short n, string initial, short k){
	queue<tuple<string, int, short>> queue;
	queue.push(make_tuple(initial, 0, -1));
	
	while(!queue.empty()){
		string cur = get<0>(queue.front());
		int cost = get<1>(queue.front());
		short prev = get<2>(queue.front());
//		cout << cur << "\n";
		queue.pop();
				
		if(visited.find(cur) == visited.end()){
			if(isSorted(cur)){
				return cost;
			}
			visited.insert(cur);
			for(short x=0;x<=n-k;x++){
				if(x == prev) continue;
//				cout << " -> " << cost << "\n";
				queue.push(make_tuple(swap(x, k, cur), cost+1, x));
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short n, k;
	string tmp;
	cin >> n;
	
	string data;
	for(short x=0;x<n;x++){
		cin >> tmp;
		data.append(tmp);
	}
	
	cin >> k;
	
	cout << solve(n, data, k) << "\n";
    return 0;
}
