/**
 * 487-3279
 * http://poj.org/problem?id=1002
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int char_map[] = {2, 2, 2, // ABC
	3, 3, 3,  // DEF
	4, 4, 4,  // GHI
	5, 5, 5,  // JKL
	6, 6, 6,  // MNO
	7, 7, 7, 7,  // PQRS
	8, 8, 8,  // TUV
	9, 9, 9, 9};  // WXYZ

int main() {
    int n = 0;
    map<string, int> number_map;
    cin>>n;
    for (int i = 0; i < n; i++) {
	string number_i;
	cin>>number_i;
	number_i.erase(remove(number_i.begin(), number_i.end(), '-'), number_i.end());
	for (int s = 0; s < number_i.size(); s++) {
	    char c = number_i[s];
	    if (c >= 'A' && c <= 'Z') {
	    	number_i[s] = char(char_map[c - 'A']+'0');
	    }
	}
	
	number_i.insert(3, 1, '-');
	if (number_map.find(number_i) == number_map.end() ) {
	    number_map.insert(pair<string, int>(number_i, 1));
	}
	else number_map[number_i]++;
    }
    
    bool dup = false;
    for (map<string, int>::iterator iter = number_map.begin(); iter != number_map.end(); iter++) {
	if (iter->second > 1) {
	    cout<<iter->first<<' '<<iter->second<<endl;
	    dup = true;
	}
    }
    if (dup == false) {
	cout<<"No duplicates."<<endl;
    }

    return 0;
}
