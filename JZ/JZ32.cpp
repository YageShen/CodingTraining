class Solution {
public:
//     static bool compare(const string &s1, const string &s2) {
//         int i = 0;
//         int n1 = s1.size();
//         int n2 = s2.size();
//         int min_n = min(n1, n2);
//         while(i < min_n) {
//             if(s1[i] < s2[i])
//                 return true;
//             if(s1[i] > s2[i])
//                 return false;
//             ++i;
//         }
//         if(n1 > n2) {
//             for(int j(n2); j < n1; ++j) {
//                 if(s1[j] < s2[i-1])
//                     return true;
//                 if(s1[j] > s2[i-1])
//                     return false;
//             }
//         }
//         else
//             for(int j(n1); j < n2; ++j) {
//                 if(s2[j] < s1[i-1])
//                     return false;
//                 if(s2[j] > s1[i-1])
//                     return true;
//             }
//         return false;
//     }
    static bool compare(const string &s1, const string &s2) {
        return s1 + s2 < s2 + s1;
    }
    
    string PrintMinNumber(vector<int> numbers) {
        vector<string> num_str;
        for(int i(0); i < numbers.size(); ++i) {
            num_str.push_back(to_string(numbers[i]));
        }
        sort(num_str.begin(), num_str.end(), compare);
        string ret;
        for(int i(0);i < numbers.size(); ++i) {
            ret += num_str[i];
        }
        return ret;
    }
};