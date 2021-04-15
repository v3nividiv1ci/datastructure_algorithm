//#include "linked_list.cpp"
#include "sorts.h"
#include "trees.h"
#include <iostream>
#define null NULL


int main() {
//    int arr[] = {null, 1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    int arr[] = {null, 7,1,5,4,3,2,6, 0};
    int len = sizeof(arr)/sizeof(arr[0]) - 1;
//    printf("the len is %d", len);
//    bubble_sort(arr, len);
//    insert_sort(arr, len);
//    q_sort(arr, 0, len - 1);
//    int arr_1[] = {null, 7,1,5,4,3,2,6};
//    int arr_1[] = {null, 1,2,3,4,5,6,7};
//    int len_1 = sizeof(arr_1)/sizeof(arr_1[0]) - 1;
    merge_sort(arr, 1, len);
//    heap_sort(arr_1, len_1);
//    printf("%d\n", len_1);
    for (int i = 1; i <= len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
