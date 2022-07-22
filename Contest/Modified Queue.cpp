#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> queue;
	
	string tmp;
	for(int x=0;x<n;x++){
		cin >> tmp;
		if(tmp == "add"){
			int x,y;
			cin >> x >> y;
			queue.insert(queue.end(), y, x);//.push_back(x);
			cout << queue.size() << "\n";
		} else if(tmp == "del"){
			int y, first = queue.front();
			cin >> y;
			queue.erase(queue.begin(), queue.begin() + y);
			cout << first << "\n";
		} else {
			reverse(queue.begin(), queue.end());
		}
	}
    return 0;
}
