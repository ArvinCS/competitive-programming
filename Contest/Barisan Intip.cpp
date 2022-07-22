#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int tetangga[n], values[n];
	unsigned long long total = 1;
	
	fill(&values[0], &values[0]+n, 1);
	vector<int> stack;
	
	for(int x=0;x<n;x++){
		cin >> tetangga[x];
		if(x > 0){
			int last = x;
			for(int i=stack.size();i>0;i--){
				if(tetangga[stack[i-1]] <= tetangga[x]){
					last = stack[i-1];
					stack.pop_back();
				} else {
					break;
				}
			}
			//cout << x << " last is " << last << "\n";
			if(last < x) values[x] = values[last] + (x-last);
			total += values[x];
		}
		stack.push_back(x);
		//cout << x << " -> " << total << "\n";
	}

	cout << total << "\n";
    return 0;
}
