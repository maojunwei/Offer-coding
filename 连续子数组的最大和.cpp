/*
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    int len = array.size();
        if(len == 0)
            return 0;
        int max = array[0];
        int sum=0;
        for(int i = 0;i<len;i++)
            for(int j = i;j<len;j++)
            {
                sum = getsum(array,i,j);
                if(sum>max)
                    max = sum;                    
            }
        return max;
    }
    int getsum(vector<int> n,int i, int j)
    {
        int s = 0;
        for(int k = i;k<=j;k++)
            s += n[k];
        return s;
    }
};