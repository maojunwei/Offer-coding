/*
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ�����
�ƶ�һ�����ӡ����һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ� 
���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·����
���Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ���
����֮��·�������ٴν���ø��ӡ�
*/
class Solution {
     private:
    bool ispash(char *matrix,char* str,bool* flag,int row,int col,int rows,int cols)
    {
        if(row<0 || col <0 || row>rows-1 || col>cols-1)
            return false;
               char a = matrix[row*cols + col];
        if(a == *str && (!flag[row*cols + col] ))
        {
            flag[row * cols + col] = true;
            if(!str[1])
                return true;
            bool condition = (ispash(matrix,str+1,flag,row,col+1,rows,cols)||
                ispash(matrix,str+1,flag,row+1,col,rows,cols)||
                ispash(matrix,str+1,flag,row-1,col,rows,cols)||
                ispash(matrix,str+1,flag,row,col-1,rows,cols));
            if(condition == false)
                flag[row * cols + col] = false;
            return condition;
             
        }
        else
            return false;
    }
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool *flag = new bool[rows*cols];
        for(int i = 0;i<rows*cols;i++)
            flag[i] = false;
        bool condition = false;
        for(int i =0;i<rows;i++)
            for(int j=0;j<cols;j++)
            {
                condition = (condition || ispash(matrix,str,flag,i,j,rows,cols));
                 
            }
        return condition;
    }
 
};