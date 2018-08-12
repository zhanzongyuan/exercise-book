/**
 * 浮点数高精度幂次算法（基于高精度乘法）
 * Exponentiation
 * http://poj.org/problem?id=1001
 */

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string multi(string a, string b) {
	// a length must longer than b.
	if (a.size() > b.size()) swap(a, b);

	// Record the floating point position.
	int a_ppos = a.find('.');
	if (a_ppos != string::npos) {
		a.erase(a_ppos, 1);
		a_ppos = a.size() - a_ppos;
	}
	else a_ppos = 0;

	int b_ppos = b.find('.');
	if (b_ppos != string::npos) {
		b.erase(b_ppos, 1);
		b_ppos = b.size() - b_ppos;
	}
	else b_ppos = 0;

	// Initial result string.
	int result_len = a.size() + b.size() + 1;
	string result(result_len, '0');
    

	// Computing.
	for (int bi = b.size()-1; bi >= 0; bi--) {
		int ri = (result.size()-1) - (b.size()-bi-1);
		int ai = a.size()-1;
		int carry = 0;
        while (ai >= 0 || carry != 0) {
			int element_r = (result[ri]-'0') + carry;
            
            if (ai >= 0 && bi >= 0) element_r += (b[bi]-'0')*(a[ai]-'0');

			carry = element_r / 10;
			int remain = element_r % 10;
			result[ri] = char(remain+'0');

			ri--;
			ai--;
		}
	}
    
	// Insert floating point into result.
    if ((a_ppos+b_ppos) > 0) {
        result.insert(result.size() - (a_ppos+b_ppos), 1, '.');
        
        // Erase '0' in back of the result.
        char tail = result[result.size()-1];
        while (tail == '0') {
            result.erase(result.size()-1, 1);
            tail = result[result.size()-1];
        }
        if (tail == '.') result.erase(result.size()-1, 1);
    }

	// Erase '0' in front of the result.
	while (result[0] == '0') {
		result.erase(0, 1);
	}

	return result;
}

int main() {
	string r;
	int n;

	while (cin>>r>>n) {
		string result = "1";
        if (n == 0) {
            cout<<1<<endl;
            continue;
        }
		for (int i = 0; i < n; i++) {
			result = multi(result, r);
		}
        if (result.size() != 0) cout<<result<<endl;
        else cout<<0<<endl;
	}
	return 0;
}

