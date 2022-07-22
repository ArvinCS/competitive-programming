#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	short t;
	cin >> t;
	
	for(short c=1;c<=t;c++){
		short r, highest = 0, tmp;

		bool ans = false;
		for(int x=0;x<4;x++){
			cin >> tmp;
			highest = max(highest, tmp);
		}
		
		cin >> r;
		if(highest > r) cout << "Kasus #" << c << ": catatan baru!\n";
		else cout << "Kasus #" << c << ": tidak ada catatan baru\n";
	}
	
    return 0;
}
