class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
           return 1;
        int nb = log2(num) + 1;
        int mask = (unsigned)(1 << nb) - 1;
        return num^mask;
    }
};