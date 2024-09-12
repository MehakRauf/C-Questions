#include <iostream>
using namespace std;

int FixingCodeInProduction(int[], int);
int SelectingTheMedian(int[], int);
int bribedQueue();
int GoingOffTheCharts(int arr[], int size);
int main()
{
    // int arr[]={2, 4, 8, 16, 32, 64, 128, 256, 512};
    // FixingCodeInProduction(arr,9);
    // if(result !=-1){
    //     cout<<"The number is found at "<<result;
    // }
    // else{
    //     cout<<"Reuslt is not found";
    // }
    // int arr1[]={55, 64, 67, 76, 76, 80, 82, 88, 98};
    // cout<<SelectingTheMedian(arr1,9);
    // cout<<bribedQueue();
    // int arr[] = {7, 8, 9, 9, 8, 6, 7, 8, 8, 8, 10, 12, 6, 7, 7, 8};
    // cout << GoingOffTheCharts(arr, 16);
}    
// int GoingOffTheCharts(int arr[], int size)
// {

//     int max_wh[size];
//     int wh = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (arr[i] > 6)
//         {
//             wh++;
//             max_wh[i] = wh;
//         }
//         else
//         {
//             wh = 0;
//             max_wh[i] = 0;
//         }
//     }
//         int min = max_wh[0];
//         for (int i = 0; i < size; i++)
//         {
//             // cout<<max_wh[i]<<" ";
//             if (min < max_wh[i])
//             {
//                 min = max_wh[i];
//             }
//         }
//         return min;
//     }

// int bribedQueue(){
    // int totalBribes=0;
    // int first[]={1, 2, 3, 4, 5, 8, 6, 7};
    // int second[]={1, 2, 3, 4, 5, 6, 8, 7};
    // for (int i=0;i<8;i++){
    //     if (first[i]!=second[i]){
    //         totalBribes++;
    //     }
    // }
//     return totalBribes;
// }
// int FixingCodeInProduction(int arr[], int size){
//     int l=0, r=size;
//     for(int i=0; i<size; i++){
//         int mid=(l+r)/2;
//         if(arr[mid] == 128){
//             return mid;
//         }
//         if(arr[mid]>128){
//             r=mid;
//         }
//         else{
//             l=mid;
//         }
//     }
//     return -1;
// }

    
