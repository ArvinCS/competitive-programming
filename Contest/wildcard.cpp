#include <iostream>

using namespace std;

int main(){
	string prefix;
	int jumlah;
	cin >> prefix >> jumlah;
	string kata[jumlah];
	for(int x=0;x<jumlah;x++){
		string command;
		cin >> command;
		bool add = true;
		for(int y=0;y<prefix.size();y++){
			if(prefix[y] != '*' && command[y] != prefix[y]){
				add = false;
				break;
			}
		}
		if(add) kata[x] = command;
	}
	
	for(int x=0;x<jumlah;x++){
		if(kata[x] != ""){
			cout  << kata[x] << "\n";
		}
	}
	
	return 0;
}
