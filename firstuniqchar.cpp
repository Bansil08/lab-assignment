class Solution {
public:
    int firstUniqChar(string str) {
        int len = str.size();
        vector<int> freq(26, 0);

        for(int idx = 0; idx < len; idx++) freq[str[idx] - 'a']++;

        for(int idx = 0; idx < len; idx++) {
            if(freq[str[idx] - 'a'] == 1) {
                return idx;
            }
        }

        return -1;
    }
};
