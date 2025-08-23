#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i = 0; int j = size-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
     for(int k = 0; k<size ; k++)
    {
        cout<<arr[k]<<" ";
    }
}