class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Replacing unordered_set with fast boolean lookup arrays
        // Size 128 covers all ASCII values perfectly
        bool s[200] = {false};
        bool ignore[200] = {false};
        int res = 0;

        for (auto i : word) {
            int temp = i; // 'temp' is just the ASCII value of the character
            
            // Your original logic: if character is lowercase ('a' to 'z')
            if (temp >= 'a' && temp <= 'z' && !ignore[temp]) {
                if (s[temp - 32]) { // temp - 32 converts lowercase to uppercase
                    res--;
                    ignore[temp] = true;
                    continue;
                }
                s[temp] = true;
                continue;
            }
            
            // Your original logic: if character is uppercase
            if (!s[temp]) {
                if (s[temp + 32]) { // temp + 32 converts uppercase to lowercase
                    res++;
                    s[temp] = true;
                } else {
                    ignore[temp + 32] = true;
                }
            }
        }
        return res;
    }
};