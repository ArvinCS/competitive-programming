#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, exc[6] = {1,2,3,5,7,11};
	cin >> n;
	long long tmp;
	for(int x=0;x<n;x++){
		cin >> tmp;
		
		bool hasComposite = true;
		for(int i=0;i<6;i++){
			if(tmp == exc[i]){
				hasComposite = false;
				break;
			}
		}
		
		if(!hasComposite){
			cout << "-1\n";
		} else {
			if(tmp % 4 == 0) cout << tmp/4 << "\n";
			else if(tmp % 4 == 1) cout << 1 + (tmp-9)/4 << "\n";
			else if(tmp % 4 == 2) cout << 1 + (tmp-6)/4 << "\n";
			else if(tmp % 4 == 3) cout << 2 + (tmp-9-6)/4 << "\n";
		}
	}
	
    return 0;
}
