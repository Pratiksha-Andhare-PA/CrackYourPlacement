void printDuplicateChars(string str){
    unordered_map<char, int> mp;
    
    for(char ch : str){
        mp[ch]++;
    }
    
    for(auto it : mp){
        if(it.second > 1)
            cout << it.first << " " << it.second << endl; 
    }
}

/*

1) Brute Force:
Use 2 Nested Loops.

TC => O(N^2)
SC => O(1)

2) Sort the string.

TC => O(N*logN)
SC => O(1)

3) Use Hashmap.

TC => O(N)
SC => O(N)

*/
