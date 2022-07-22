#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n; 
	long long extra = 0, a, b;
	cin >> n;
	
	vector<long long> stack(0);
	
	string tmp;
	for(int x=0;x<n;x++){
		cin >> tmp;
		if(tmp == "add"){
			cin >> a >> b;
			stack.insert(stack.end(), b, a);//.push_back(x);
			extra = 0;
			cout << stack.size() << "\n";
		} else if(tmp == "del"){
			long long first = stack.size() > 0 ? stack.back() + extra : 0;
			cin >> b;
			while(b--) stack.pop_back();
			cout << first << "\n";
		} else if(tmp == "adx"){
			cin >> b;
			extra += b;
		} else if(tmp == "dex"){
			cin >> b;
			extra -= b;
		}
		//for(int x=0;x<stack.size();x++) cout << stack[x] + extra << " ";
		//cout << "\n";
	}
    return 0;
}
