class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> vp = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        int i = 0;
        string ans = "";
        while(num > 0){
            if(num >= vp[i].first){
                num -= vp[i].first;
                ans += vp[i].second;
            }
            else i++;
        }
        return ans;
    }
};

/*

# Complexity
TC => O(1) => Traversal will be for number of roman letters which is constant
SC => O(1) => Vector pair stores constant pairs

*/
