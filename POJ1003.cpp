/**
 * Hangover
 * http://poj.org/problem?id=1003
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    float target;
    while (cin>>target) {
	if (target - 0.00 < 0.01) break;
	// vector<unsigned long> molecules;
	// unsigned long denominator = 1;
	double sum = 0;
	int n = 0;
	while (sum < target) {
	    n++;
	    sum += 1.0/(n+1);
	}
	cout<<n<<" card(s)"<<endl;
    }
    return 0;
}
