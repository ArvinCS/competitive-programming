#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> vec;
	string tmp;
	while(n--){
		cin >> tmp;
		if(tmp == "push_back"){
			int n;
			cin >> n;
			vec.push_back(n);
		} else if(tmp == "push_front"){
			int n;
			cin >> n;
			vec.insert(vec.begin(), n);
		} else if(tmp == "pop_back"){
			vec.pop_back();
		} else {
			vec.erase(vec.begin());
		}
	}
	
	for(int x=0;x<vec.size();x++){
		cout << vec[x] << "\n";
	}
    return 0;
}
