class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int targetValue) {
        map<int, int> indexMap;

        for(int index = 0; index < numbers.size(); index++) {
            int difference = targetValue - numbers[index];
            if(indexMap.find(difference) != indexMap.end()) {
                return {indexMap[difference], index};
            }

            indexMap[numbers[index]] = index;
        }

        return {-1};
    }
};

