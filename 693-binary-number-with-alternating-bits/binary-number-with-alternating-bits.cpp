class Solution {
public:
    bool hasAlternatingBits(int n) {
        // Step 1: XOR n with itself shifted right by 1.
        // If bits alternate, this creates a number with all 1s (e.g., 101 ^ 010 = 111).
        long allOnes = n ^ (n >> 1);
        
        // Step 2: Check if 'allOnes' actually consists of all 1s.
        // If X is all 1s (e.g., 111), then X + 1 is a power of 2 (e.g., 1000).
        // Therefore, X & (X + 1) should be 0.
        return (allOnes & (allOnes + 1)) == 0;
    }
}
;