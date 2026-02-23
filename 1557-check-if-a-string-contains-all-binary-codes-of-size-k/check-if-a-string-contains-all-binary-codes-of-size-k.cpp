// class Solution {
// public:
//     bool hasAllCodes(string s, int k) {
//         vector<bool> array (pow(2, k)-1, 0);
//         string temp  = s.substr(0, k);
//         int i = 0,j = k;
//         while(j< s.size()){
//             cout<<i<<endl;
//             cout<<temp<<endl;
//             cout<<stoi(temp)<<endl<<endl;
//             array[stoi(temp)] = true;
//             temp[i] = '0';
//             i++;
//             temp += s[j];
//             j++;
//         }
//         for(auto i: array){
//             if(i == false) return false;
//         }
//         return true;
//     }
// };

#include <string>
#include <unordered_set>

class Solution {
public:
    bool hasAllCodes(std::string s, int k) {
        // Edge case: string is shorter than the required code length
        if (s.size() < k) return false;
        
        std::unordered_set<std::string> seen;
        
        // Slide a window of size k across the string
        for (int i = 0; i <= s.size() - k; i++) {
            seen.insert(s.substr(i, k));
        }
        
        // Check if we found 2^k unique combinations
        return seen.size() == (1 << k); 
    }
};