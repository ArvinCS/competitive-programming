#include <iostream>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

string createString(int x, char y){
	string tmp(x, y);
	return tmp;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		us n;
		cin >> n;
		
		short data[n];
		for(us x=0;x<n;x++)	cin >> data[x];	
		
		string list[n+1];
		list[0] = createString(data[0], 'a') + createString(50-data[0], 'b');
		cout << list[0] << "\n";
		for(us x=0;x<n;x++){
			list[x+1] = list[x].substr(0, data[x]) + createString(50-data[x], list[x][data[x]] == 'a' ? 'b' : 'a');
			cout << list[x+1] << "\n";
		}	
	}
    return 0;
}
