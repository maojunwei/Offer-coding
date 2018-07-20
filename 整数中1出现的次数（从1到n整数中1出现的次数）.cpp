class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n == 0)
           return 0;
        int count = 0;
        for(int i = 1;i<=n;i++)
        {
            int n = i;
            while(n)
              {
                if(n%10 == 1)
                    count++;
                n = n/10;
              }
        }
        return count;
    }
};