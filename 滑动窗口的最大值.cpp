/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
	那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， 
{2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) //vector<int>类型的引用，(int 数组的引用)，num为实参的别名
        //const引用让变量拥有只读属性
    {
        int len = num.size();
        vector<int> vec;
        if(len == 0 || size ==0)
            return vec;
        for(int i=0;i<len-size+1;i++)
        {
            vector<int> v;
            for(int j = i;j<i+size;j++)
            {
                v.push_back(num[j]);
            }
            sort(v.begin(),v.end());
            vec.push_back(v[size-1]);
            
        }
        return vec;
    }
};