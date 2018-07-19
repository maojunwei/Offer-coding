/*
������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������
������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ��
�������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ�
�����ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
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