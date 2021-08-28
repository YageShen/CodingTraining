class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int numOfZero = 0;
        while(numbers[numOfZero] == 0) ++numOfZero;
        for(int i = numOfZero; i < 4; ++i) {
            if(numbers[i] == numbers[i+1])
                return false;
        }
        if(numbers[4] - numbers[numOfZero] < 5)
            return true;
        else 
            return false;
    }
};