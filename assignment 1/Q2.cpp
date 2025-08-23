#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    bool isduplicate = false;

    for(int i =0; i<size ;i++)
    {
        for(int j=i+1; j<size ; j++)
        {
        if(arr[i]==arr[j])
        {
        for(int k = j+1 ;k<size ;k++)
           {arr[k-1]=arr[k];
        }
        size--;
        j--;
        }
        }
    }
    for(int i = 0;i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }


}