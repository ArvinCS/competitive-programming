#include <iostream>

using namespace std;

string toLower(string l){
	for(int x=0;x<l.size();x++){
		if (l[x] <= 'Z' && l[x] >= 'A'){
	    	l[x] -= ('Z' - 'z');	
	    }
	}
	return l;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	string s,t;
	cin >> s;
	cin >> t;
	
	if(toLower(s).compare(toLower(t)) == 0){
		cout << "20/20\n";
	} else {
		cout << "x_x\n";
	}
}
