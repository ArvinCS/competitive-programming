#include <iostream>

using namespace std;

string gunung(int t){
	if(t == 1){
		return "*\n";
	}
	string bintang = gunung(t-1);
	for(int x=1;x<=t;x++){
		bintang = bintang + "*";
	}
	return bintang + "\n" + gunung(t-1);
}
int main(){
	int tingkat;
	cin >> tingkat;
	
	cout << gunung(tingkat);
	return 0;
}
