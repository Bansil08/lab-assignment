class Solution {
public:
    int longestConsecutive(vector<int>& numbers) {
        int length = numbers.size();
        if(length == 0) return 0;

        unordered_set<int> numSet;
        int maxStreak = 0;

        for(int index = 0; index < length; index++){
            numSet.insert(numbers[index]);
        }

        for(auto value : numSet){
            if(numSet.find(value - 1) == numSet.end()){
                int currentStreak = 1;
                int currentValue = value;

                while(numSet.find(currentValue + 1) != numSet.end()){
                    currentStreak++;
                    currentValue++;
                }

                maxStreak = max(maxStreak, currentStreak);
            }
        }

        return maxStreak;
    }
};
