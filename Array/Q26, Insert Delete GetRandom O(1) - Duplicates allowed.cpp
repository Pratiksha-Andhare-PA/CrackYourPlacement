class RandomizedCollection {
    vector<int> nums;
    unordered_map<int,unordered_multiset<int>> mp;
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool flag = mp.count(val)>0;
        nums.push_back(val);
        mp[val].insert(nums.size()-1);
        return !flag;
    }

    bool remove(int val) {
        if (mp.count(val) == 0)
            return false;

        int valIndex = *(mp[val].begin());
        int lastIndex = nums.size() - 1;
        int lastNum = nums[lastIndex];

        nums[valIndex] = lastNum;
        mp[val].erase(mp[val].begin());
        mp[lastNum].insert(valIndex);
        mp[lastNum].erase(lastIndex);

        nums.pop_back();
        if (mp[val].empty())
            mp.erase(val);

        return true;
    }

    
    int getRandom() {
        int randomIdx = rand() % nums.size();
        return nums[randomIdx];
    }
};

/**

TC => O(1)
SC => O(N)

**/
