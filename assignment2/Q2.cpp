#include<iostream>
using namespace std;
int main()
{   

    int arr[]={64,34,25,12,22,11,90};
   int size = sizeof(arr)/sizeof(arr[0]);
   bool isswapped = false;
    for(int i =0; i<size-1 ;i++)
    {
        for(int j= 0 ; j<size-i-1;j++)
        {   if(arr[j]>arr[j+1])
            {swap(arr[j],arr[j+1]);
            isswapped = true ;}
        }
      if(isswapped !=true)
      break;
    }
      for(int i = 0;i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }




}