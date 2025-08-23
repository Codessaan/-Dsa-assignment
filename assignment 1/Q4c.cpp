#include<iostream>
using namespace std;
int main()
{   int multi[2][2];
    int m , n ,p ,q ;
    int arr1[2][2]={{1,2},{3,4}};

    cout<<" enter rows and column of arr1"<< endl;
    cin>> m>>n;
    for(int i =0; i<m  ;i++)
    {
        for(int j= 0 ; j<n;j++)
        {   if(i<j)
            swap(arr1[i][j],arr1[j][i]);
        }
    }
    for(int i =0 ; i<m ; i++)
    {
        for(int j =0 ; j<n;j++)
        {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }



}