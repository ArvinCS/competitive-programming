#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	int members = 0;
	int value;
	for(int x=0;x<=n;x++){
		cin >> value;
		members = (members + value * pow(2,x));
	}

	int capacity = pow(2,n);
	if(members % capacity == 0){
		cout << members/capacity << "\n";
	} else {
		cout << "-1\n";
	}

    return 0;
}


