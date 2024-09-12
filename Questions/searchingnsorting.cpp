#include <iostream>
using namespace std;

// void linearSearch(int arr[], int toSearch, int size);
// int binarySearch(int, int, int *arr, int);
// void linearSearch(int *arr,int, int);
// void selectionsort(int [],int);
// void bubbleSort(int [], int);
 void insertionSort(int [], int);
int main()
{
    // int arr[]={1,3,2,4,5,1,1,1,18,7,9};
    // linearSearch(arr,1,11);
    // int toSearch;
    // int size;
    // cout << "Enter the size of your array: ";
    // cin >> size;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter your element: ";
    //     cin >> arr[i];
    // }
    // cout << "Enter the number you want to search: ";
    // cin >> toSearch;
    // linearSearch(arr, toSearch, size);

    // int toSearch;
    // int size;
    // cout << "Enter the size of your array: ";
    // cin >> size;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter your element: ";
    //     cin >> arr[i];
    // }
    // cout << "Enter the number you want to search: ";
    // cin >> toSearch;
    // binarySearch(0,size,arr,size,toSearch);

    // int toSearch;
    // int size;
    // cout << "Enter the size of your array: ";
    // cin >> size;
    // int arr[size];
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter your element: ";
    //     cin >> arr[i];
    // }
    // cout << "Enter the number you want to search: ";
    // cin >> toSearch;
    // int result = binarySearch(0, size, arr, toSearch);
    // if (result != 1)
    // {
    //     cout << "Number is not found.";
    // }
    // else
    // {
    //     cout << "Number is found at " << result;
    // }
    //     int arr[]={2,3,1,6,5,4};
    //     selectionsort(arr,6);
    //  int arr[]={2,3,1,6,5,4};
    // bubbleSort(arr, 6);
    int arr[] = {11,4,3,6,5,2,7};
    insertionSort(arr, 7);
}
void insertionSort(int arr[], int size)
{
    int hold, gap;
    for (int i = 1; i <= size; i++)
    {
        hold = arr[i];
        gap = i -1;
        while (gap >= 0 && hold< arr[gap])
        {
            int temp = arr[gap + 1];
            arr[gap + 1] = arr[gap];
            arr[gap] = temp;
            gap--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
// void bubbleSort(int arr[], int size){
//     for(int i=0; i<size;i++){
//         for(int j=0;j<size-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
//     for(int i=0; i<size; i++){
//         cout<<arr[i];
//     }
// }
// void selectionsort(int arr[], int size){
//     for (int i=0; i<size-1; i++){
//         int minpos=i;
//         for(int j=0; j<size;j++){
//             if(arr[j]<arr[i]){
//                 minpos=j;
//             }
//         }
//         int temp= arr[i];
//         arr[i]=arr[minpos];
//         arr[minpos]=temp;
//     }
//     for(int i=0;i<size; i++){
//         cout<<arr[i]<<" ";
//     }
// }
// void binarySearch(int l,int r,int arr[],int size, int toSearch){
//     int flag, index, count;
//     for(int i=0;i<size;i++){
//         int mid=(l+r)/2;
//         if(arr[mid]==toSearch){
//             flag=1;
//             index=mid;
//         }
//         if(arr[mid]>toSearch){
//             r=mid;
//         }
//         else{
//             l=mid;
//         }
//         count++;
//     }
//     if(flag!=1){
//         cout<<"Number is not found.";
//     }
//     else{
//         cout<<"Number is found at: "<<index<<" in "<<count<<" steps.";
//     }
// }
// int binarySearch(int l, int r, int arr[], int toSearch)
// {

//     int mid = (l + r) / 2;
//     if (arr[mid] == toSearch)
//     {
//         return mid;
//     }
//     if (arr[mid] > toSearch)
//     {
//         binarySearch(mid, r, arr, toSearch);
//     }
//     else
//     {
//         binarySearch(l, mid, arr, toSearch);
//     }
//     return -1;
// }
// void linearSearch(int arr[], int toSearch, int size)
// {
//     int index;
//     int flag = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == toSearch)
//         {
//             index=i;
//             flag = 1;
//             break;
//         }
//     }
//     if (flag != 1)
//     {
//         cout << "Number not found.";
//     }
//     else
//     {
//         cout << "Number found at"<<index;
//     }

// }
// void linearSearch(int arr[], int toSearch, int size)
// {
//     int count=0;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] == toSearch)
//         {
//             count++;
//             cout << "the number is found at " << i<<endl;
//         }
//     }
//     cout << "The number is present " << count << " times"<<endl;
// }