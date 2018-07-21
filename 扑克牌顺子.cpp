class Solution {
public:
    bool IsContinuous( vector<int> numbers ) { //判断是不是“顺子”，五个元素,无重复数，计算零的个数，最大差值有限制
        int len = numbers.size();//空间换时间
        if(len == 0)
            return false;
        int count[14] = {0};
        int max = -1;
        int min = 14;
        for(int i=0;i<len ;i++)
        {   
            if(numbers[i] == 0)
              continue;
            count[numbers[i]]++;
            if(count[numbers[i]] > 1)
               return false;
            if(numbers[i] > max)
                max = numbers[i];
            if(numbers[i] < min)
                min = numbers[i];            
        }
        if(max - min < 5)
            return true;
        return false;
    }
};