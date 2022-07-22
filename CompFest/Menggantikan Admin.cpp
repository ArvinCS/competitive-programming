#include <iostream>
#include <map>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui n;
	cin >> n;
	
	map<string, int> daftar;
	while(n--){
		string tmp, nama;
		cin >> tmp >> nama;
		
		if(tmp == "DAFTAR"){
			daftar[nama]++;
		} else {
			cout << daftar[nama] << "\n";
		}
	}
    return 0;
}

