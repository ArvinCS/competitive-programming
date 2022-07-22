#include <cstdio>

using namespace std;

int main(){
    int x;
    scanf("%d", &x);
	
	if(x > 0 && x < 100000) {
	    if(x < 10) printf("satuan\n");
	    else if(x<=99) printf("puluhan\n");
		else if(x<=999) printf("ratusan\n");
		else if(x<=9999) printf("ribuan\n");
		else if(x<=99999) printf("puluhribuan\n");
	}
    return 0;
}
