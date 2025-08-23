#include<iostream>
using namespace std;
int main()
{   int multi[2][2];
    int m , n ,p ,q ;
    int arr1[2][2]={{1,2},{3,4}};
    int arr2[2][2]={{1,2},{3,4},};
    cout<<" enter rows and column of arr1"<< endl;
    cin>> m>>n;
    cout<<" enter rows and column of arr2"<<endl;
    cin>> p>>q ;


    // multiplication of ek ki row dusre ka column and their sum
    for(int i =0; i<m  ;i++)
    {
        for(int j= 0 ; j<q ;j++)
        {  multi[i][j]=0;
            for(int k =0; k<n; k++)
           multi[i][j] += arr1[i][k]* arr2[k][j];
        }
    }
    for(int i =0 ; i<m ; i++)
    {
        for(int j =0 ; j<q;j++)
        {
            cout<<multi[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"this is a comment"<< endl;



}