#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int data[n], count[200001] = { 0 }, before;
	bool distinct = false, duplicate = false;
	for(int x=0;x<n;x++){
		cin >> data[x];
		
		if(x > 0 && before != data[x]){
			distinct = true;
		}
		if(count[data[x]] >= 1){
			duplicate = true;
		} else {
			count[data[x]]++;
		}
		before = data[x];
	}
	
	if(duplicate && distinct){
		cout << n-1 << "\n";
	} else if(distinct){
		cout << n << "\n";
	} else {
		cout << 1 << "\n";
	}
    return 0;
}
