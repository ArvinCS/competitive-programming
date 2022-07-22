#include <iostream>
#include <cmath>

using namespace std;

float round_up(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

float degreeToRadian(int degree){
	float rad = degree / 180.00;
	rad *= 3.14159265;
	//cout << degree << " - > " << rad << "\n";
	return rad;
}

int factorial(int n){
	if(n == 1) return 1;
	return n * factorial(n-1);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	/*
	int h, base, top;
	cin >> h >> base >> top;
	*/
	for(int a=1;a<10;a++){
		for(int b=1;b<10;b++){
			for(int c=1;c<10;c++){
				for(int d=1;d<10;d++){
					int result = a * 1000 + b * 100 + c * 10 + d;
					int selisih = abs(factorial(a) + factorial(b) + factorial(c) + factorial(d) - result);
					if(selisih <= 50){
						cout << "FOUND!\n";
						cout << "a: " << a << "\n";
						cout << "b: " << b << "\n";
						cout << "c: " << c << "\n";
						cout << "d: " << d << "\n";
						cout << "selisih: " << selisih << "\n";
						cout << "hasil: " << result << "\n";
						cout << "format: " << a << " " << b << " " << c << " " << d << " - " << selisih << " = " << result << "\n";
					}
				}
			}
		}
	}
	//cout << "tan 50 - tan 40 = " << tan(degreeToRadian(50)) - tan(degreeToRadian(40)) << "\n";
	/*
	float tanA1 = tan(degreeToRadian(top));
	bool found = false;
	cout << "tan: " << tanA1 << " cos: " << cos(degreeToRadian(base)) << "\n";
	for(float cliff=1;cliff<80 && !found;cliff+=0.001){
		float tmp = cliff + h;
		float far = tmp / tanA1;
		float diagonal = sqrt(pow(far, 2) + pow(cliff, 2));
		cout << far << "||" << diagonal << "||" << cliff << " : " << far/diagonal << "\n";
		if(round_up(far/diagonal, 6) == round_up(cos(degreeToRadian(base)), 6)){
			cout << "FOUND!\n";
			cout << "ANS: " << far << "\n";
			break;
		}
	}*/
    return 0;
}
