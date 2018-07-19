/*
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> v;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left=0,right = cols -1,up = 0,down = rows - 1 ;
        while(left<=right && up<=down)
        {
            for(int i = left;i<=right;i++)
                v.push_back(matrix[up][i]);
            for(int j = up+1;j<= down;j++)
                v.push_back(matrix[j][right]);
            for(int k=right-1;k>=left&&down!=up;k--)
                v.push_back(matrix[down][k]);
            for(int m=down-1;m>up&&right!=left;m--)
                v.push_back(matrix[m][left]);
            left++,right--;up++;down--;
             
             
        }
        return v;
 
    }
};