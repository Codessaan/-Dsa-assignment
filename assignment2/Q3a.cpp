#include<iostream>
using namespace std;
int main()
{   int n ;
    int arr[]={1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"enter n :"<<endl;
    cin>>n;
    bool found = false;
    
    for(int i =0; i <= n-1;i++)
    {
        if(arr[i]!=i+1)
        {cout<<"found the missing number i.e :"<<i+1<<endl;;
        break;
        found = true;
        }
    }
    if(found!=true)
    {
        cout<<"found the missing number i.e :"<<n;
    }
}