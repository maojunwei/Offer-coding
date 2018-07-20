class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
         vector<int> v;
        if(array.size()<=0 )
            return v;
        int len = array.size();
        for(int i= len-1;i>=0;i--)
        {
            int s;
            bool flag = false;
            int a1 = sum - array[i];
            for(int j=0;j<=i;j++)
                if(a1 == array[j])
                {
                    s = j;
                    flag = true;
                    break;
                }
            if(flag)
            {
                v.push_back(array[s]);
                v.push_back(array[i]);
                break;
            }
        }
        return v;
    }
};