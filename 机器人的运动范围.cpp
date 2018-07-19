/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐
标和列坐标的数位之和大于k的格子。 例如，当k为18时，
机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，
它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold <0 || rows<=0 ||cols<=0)
            return 0;
        bool* flag = new bool[rows*cols];
        for(int i=0;i<rows*cols;i++)
            flag[i] = false;                
        int count = mcount(threshold,0,0,rows,cols,flag);
        return count;
    }
    int mcount(int k,int row,int col,int rows,int cols,bool* flag)
    {
        int count = 0;
        if(row>=0 && col>=0 && row<rows && col<cols && getnum(row)+getnum(col)<=k && (!flag[row*cols+col]))
        {
            flag[row*cols+col] = true;
            count = 1+ mcount(k,row+1,col,rows,cols,flag)+ mcount(k,row-1,col,rows,cols,flag)+  mcount(k,row,col+1,rows,cols,flag)+ mcount(k,row,col-1,rows,cols,flag);           
        }
        return count;
    }
        int getnum(int num)
        {
            int sum = 0;
            while(num>0)
            {
                sum += num%10;
                num /= 10;               
            }
            return sum;
        }
};