/*1) Develop a Menu driven program to demonstrate the following operations of Arrays 
——MENU——- 
1.CREATE 
2. DISPLAY 
3. INSERT 
4. DELETE 
5. LINEAR SEARCH 
6. EXIT */
#include<iostream>
using namespace std ;
//Array create function 
void arr_create(int arr[],int &n)
{  cout<<"enter the number of elements"<<endl;
    cin>>n;
     cout<< "Enter the elements :"<<endl;
    for(int i=0 ;i<n ; i++)
    {
        cin>>arr[i];
    }
}
//Array display function
void display_arr(int arr[],int n)
{
    cout<<" the array is "<<endl;
    for(int i=0 ;i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}
//Insert element in array function
void insert_element(int arr[], int &n , int element , int pos)
{
    for (int i = n ; i>=pos ;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos-1]= element;
    n++;
}
void delete_element(int arr[], int &n , int pos )
{
    for (int i = pos-1; i<n-1 ;i++)
    {
        arr[i] = arr[i+1];
    }
    n--;
}
void linearsearch(int arr[],int n , int target)
{
    for (int i =0 ;i<n ;i++)
    {
        if(arr[i]==target)
        {cout<<"element found at position :"<< i+1 <<endl;
        break;}
    }
}

int main ()
{int choice ;
    int arr[100]={1,2,3,4,5,6,7,8,9,0};
    int n;
    int pos , target , element ;
    cout<<"the array is ";
    for (int i;i<=9;i++){
        cout<<arr[i]<< endl;
    }
    while (true)
   
   { cout<< "the options are :"<<endl;
    cout <<"1. Create "<<endl;
    cout <<"2. Display"<<endl;
    cout <<"3. Insert"<<endl;
    cout <<"4. Delete "<<endl;
    cout <<"5. linear search "<<endl;
    cout <<"6. exit"<<endl;
    cout<<"enter ur choice "<<endl;
    cin>> choice ;

    switch (choice)
    {
        case 1: 
        arr_create(arr,n);
        break;
        case 2 :
        display_arr(arr,n);
        break;
        case 3 :
        cout<<" enter the position" << endl;
        cin>>pos;
        cout<<"enter the element to be inserted :"<<endl;
        cin >> element ;
        insert_element(arr,n,element,pos);
        break;
        case 4 : 
        cout<<" enter the position" << endl;
        cin>>pos;
        delete_element(arr,n,pos);
        break;
        case 5 :
        cout<<"enter the element to search :"<<endl;
        cin>>target;
        linearsearch(arr, n , target);
        break;
        case  6:
        return 0 ;
        default:
        cout<<"invalid choice , enter number from 1-6"<<endl;
     
    }
    


}
}