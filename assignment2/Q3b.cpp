#include<iostream>
using namespace std;
int main()
{   int n ;
    int arr[]={1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"enter n :"<<endl;
    cin>>n;
    bool found = false;
    int low =0;
    int high = n-2;
    int mid = (low+high)/2;
    while(low<=high)
    {
        if(arr[mid]== mid+1)
        {
            low= mid+1;
        }
        else 
        high = mid-1;

    }
    cout<<"found the missing number i.e :"<<low+1;
}