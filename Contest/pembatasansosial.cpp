#include <iostream>
#include <cmath>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	unsigned long long kelompok[n+1];
	
	for(int x=0;x<=n;x++){
		cin >> kelompok[x];
	}
	
	unsigned int capacity = pow(2,n);
	unsigned long long member = 0;
	for(int x=0;x<=n;x++){
		int anggota = pow(2,x);
		member += kelompok[x] * anggota;
		if((member % capacity) > 0 && (member % capacity) % anggota != 0){
			member = -1;
			break;
		}
	}
	
	if(member % capacity == 0){
		cout << member/capacity << "\n";
	} else {
		cout << "-1\n";
	}
    return 0;
}
