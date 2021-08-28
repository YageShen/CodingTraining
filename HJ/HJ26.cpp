#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

// static bool compare(const char& a, const char& b) {
// 	int val_a = 0, val_b = 0;
// 	if(a >= 'a' && a <= 'z')
// 		val_a = a - 'a';
// 	else if(a >= 'A' && a <= 'Z')
// 		val_a = a - 'A';
// 	else
// 		return false;

// 	if(b >= 'a' && b <= 'z')
// 		val_b = b - 'a';
// 	else if(b >= 'A' && b <= 'Z')
// 		val_b = b - 'A';
//     else
//         return false;

// 	return val_a < val_b;
// }
int main()
{
    string input;
    while(getline(cin, input)) {
        vector<char> vec;
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < input.size(); ++j) {
                if(input[j] - 'a' == i || input[j] - 'A' == i)
                    vec.emplace_back(input[j]);
            }
        }
        int k = 0;
        for(int i(0); i < input.size(); ++i) {
            if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
                input[i] = vec[k++];
        }
        cout << input << endl;        
    }

    return 0;
}
