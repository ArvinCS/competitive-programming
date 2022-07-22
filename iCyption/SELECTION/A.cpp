#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	short data[101] = {}, tmp, maxValue = 0;
	for(int x=0;x<n;x++){
		cin >> tmp;
		data[tmp]++;
		maxValue = max(maxValue, tmp);
	}
	
	cout << maxValue << " " << data[maxValue] << "\n";
    return 0;
}
