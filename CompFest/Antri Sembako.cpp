#include <iostream>
#include <queue>

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
	
	us q, r;
	string nama;
	cin >> q;
	
	queue<string> antrian;
	while(q--){
		cin >> r;
		if(r == 1){
			cin >> nama;
			antrian.push(nama);
		} else {
			cout << antrian.front() << "\n";
			antrian.pop();
		}
	}
    return 0;
}

