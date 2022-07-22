#include <iostream>

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
	
	string a;
	cin >> a;

	if(a[0] >= 'a' && a[0] <= 'z'){
		cout << "kata\n";
	} else if(a[0] == '0'){
		cout << "nol\n";
	} else if(a[0] == '-'){
		cout << "bilangan bulat negatif\n";
	} else {
		cout << "bilangan bulat positif\n";
	}
    return 0;
}

