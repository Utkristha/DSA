#include <iostream>
using namespace std;

class linear
{
private:
    int row;
    int column;
    float **matrix;
public:

    linear(int r = 3,int c = 3):row(r),column(c)
    {
        matrix = new float*[row];
        for(int i=0;i<row;i++)
        {
            matrix[i] = new float[column];
        }
    }

    ~linear()
    {
        for(int i=0;i<row;i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    
    void input()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                cout<<"Enter data in "<< i+1 <<" row " << j+1 <<" column of matrix :";
                cin>>matrix[i][j];
            }
        }
    }

    void display()
    {
        int i;
        int j;
        for(i=0;i<row;i++)
        {

            for(j=0;j<column;j++)
            {
                cout<<matrix[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

    void rank()
    {


        for(int i = 0;i<row;i++)
        {
            int lead = 0;

            //finding pivot
            int r = i;
            while(matrix[r][lead] == 0)
            {
                r++;
                if(r == row)
                {
                    r = i;
                    lead++;
                    if(lead == column) return;
                }
            }

            //swapping rows
            for(int j = 0;j<row;j++)
            {
                swap(matrix[r][j],matrix[i][j]);
            }

            //normalize
            int temp = matrix[r][lead];
            for(int j = lead;j<column;j++)
            {
                matrix[r][j] /= temp;
            }

            //elimination
            for(int j = i+1;j<row;j++)
            {
                int temp = matrix[j][lead];
                for(int k = 0;k<column;k++)
                {
                    matrix[j][k] -= matrix[r][k] * temp;
                }
            }
            lead++;
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                if()
            }
        }
    }
};


int main()
{
    int x,y;
    cout<<"Enter rows and column of matrix:";
    cin>>x>>y;

    linear obj(x,y);
    obj.input();
    obj.rank();
    obj.display();

    //cout<<"The rank of matrix is :"<<obj.rank()<<endl;

    return 0;
}