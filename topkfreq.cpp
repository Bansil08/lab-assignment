class Solution {
public:
    vector<int> topKFrequent(vector<int>& numbers, int K) {
        map<int, int> frequencyMap;
        int length = numbers.size();

        for(int index = 0; index < length; index++) frequencyMap[numbers[index]]++;

        vector<pair<int, int>> freqPairs;
        for(auto& entry : frequencyMap) {
            freqPairs.push_back({entry.second, entry.first});
        }
        sort(freqPairs.begin(), freqPairs.end());
        
        vector<int> result;
        for(int index = freqPairs.size() - 1; index >= 0; index--) {
            if(K == 0) break;
            result.push_back(freqPairs[index].second);
            K--;
        }

        return result;
    }
};
