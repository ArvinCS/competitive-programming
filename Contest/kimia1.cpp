#include <iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	for(double a=1;a<=100;a+=0.01){
		for(double b=1;b<=100;b+=0.01){
			for(double c=1;c<=100;c+=0.01){
				for(double d=1;d<=100;d+=0.01){
					if(a*c == c){
						if(2*d*a == 2 * d){
							if((4*c + 2*d) * 2 == 2*c + d){
								cout << a << " " << b << " " << c << " " << d << "\n";
							}
						}
					}
				}
			}	
		}
	}
	cout << "done\n";
    return 0;
}
