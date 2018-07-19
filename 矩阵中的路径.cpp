/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下
移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个
格子之后，路径不能再次进入该格子。
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