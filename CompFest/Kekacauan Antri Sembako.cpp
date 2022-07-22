#include <iostream>
#include <list>

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
	
	list<string> antrian;
	while(q--){
		cin >> r;
		if(r == 1){
			cin >> nama;
			antrian.push_front(nama);
		} else if(r == 2){
			cin >> nama;
			antrian.push_back(nama);
		} else if(r == 3){
			cout << antrian.front() << "\n";
			antrian.pop_front();
		} else {
			cout << antrian.back() << "\n";
			antrian.pop_back();
		}
	}
    return 0;
}

