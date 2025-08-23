#include<iostream>
using namespace std;
int main()
{ 
int m,n ;   
int sum_of_rows =0;   
int sum_of_column =0;   
int arr[2][2]={{1,2},{3,4}};
cout<<" enter rows and column of arr1"<< endl;
cin>> m>>n;
for (int i =0;i<m;i++){
    sum_of_rows = 0;
    for(int j=0 ; j<n ; j++)
    {
        sum_of_rows += arr[i][j] ;
       
    }
    cout<<"sum of row"<<i+1 << ":" <<sum_of_rows<<endl;
}
for (int j =0;j < n;j++){
    sum_of_column = 0;
    for(int i=0 ; i<n ; i++)
    {
        sum_of_column += arr[i][j] ;
       
    }
    cout<<"sum of column "<<j+1 << ":" <<sum_of_column <<endl;
}
// cout<<sum_of_column<<endl;
// cout<<sum_of_rows<<endl;
}