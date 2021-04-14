#include "sorts.h"
#include <iostream>
//#define INF ((unsigned) ~0)
#define INF 100000000
//为什么找了半天没有找到inf...

//冒泡排序
//复杂度 O(n^2)
//空间复杂度 O(1)
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int array[], int len) {
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
}

//插入排序
//复杂度 O(n^2)
//空间复杂度 O(1)
void insert_sort(int array[], int len){
    if (len == 1 || len == 0)
        return;
    for (int i = 1; i < len; i++){
            int temp = array[i];
            int j = i;
            while(array[j-1] > temp && j >=1)
            {
                array[j] = array[j-1];
                j--;
            }
            array[j] = temp;
     }
}

//快速排序
//时间复杂度：最好情况：O(nlogn); 最坏情况：O(n^2)
//空间复杂度：O(log2n)
void q_sort(int array[], int left, int right){
    if (left >= right)
        return;
//    初始：left = 0, right = len - 1
    int temp = array[left];
    int i = left;
    int j = right;
    while (i != j){
        while (j > i && array[j] >= temp)
            j--;
        swap(&array[i], &array[j]);
        while (i < j && array[i] <= temp)
            i++;
        swap(&array[i], &array[j]);
    }
    swap(&temp, &array[i]);
    temp = i;
    printf("temp = %d\n", temp);
    for (int i = 0; i < right - left + 1; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
    q_sort(array, left, temp - 1);
    q_sort(array, temp + 1, right);

}

//归并排序
//时间复杂度：O(nlog2n)
//空间复杂度：O(n)
void merge(int array[], int left, int right, int mid){
    int n1 = mid - left + 1;
//    arr2是从mid+1 到 right
    int n2 = right - mid;
    int* arr1 = (int *)malloc(sizeof(int) * (n1+2));
    int* arr2 = (int *)malloc(sizeof(int) * (n2+2));
    for (int temp = left; temp <= mid; temp++)
        arr1[temp - left + 1] = array[temp];
    arr1[n1+1] = INF;
//    printf("arr1[n1+1] is %d", arr1[n1+1]);
    for (int temp = mid + 1; temp <= right; temp++)
        arr2[temp - mid] = array[temp];
    for (int i = 1; i <= n1 + 1; i++)
        printf("%d ", arr1[i]);
    printf("\n");
    for (int i = 1; i <= n2 + 1; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    arr2[n2+1] = INF;
    int i = 1, j = 1;
    for (int k = left; k <= right; k++){
        if (arr1[i] <= arr2[j]) {
            array[k] = arr1[i];
            i ++;
        }
        else {
            array[k] = arr2[j];
            j ++;
        }
    }
}

//分治
void merge_sort(int array[], int left, int right){
    printf("inf is %d", INF);
    if (left < right) {
        int mid = (right + left) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, right, mid);
    }
}

//堆排序
//时间复杂度：O(nlog2n)
//空间复杂度：O(1)
//对堆的调整，维护最大堆性质的关键，由于调整之前的两个子树都是自底向上构建的最大堆，故只需要调整交换的节点所对应的堆就行，我觉得可以理解为一个自顶向下的过程
void max_heapify(int array[], int i, int heap_size){
    int l = i * 2;
    int r = l + 1;
    int largest = 0;
    if ((l <= heap_size) && (array[l] > array[i]))
        largest = l;
    else largest = i;

    if ((r <= heap_size) && (array[r] > array[largest]))
        largest = r;
    if (largest != i){
        swap(&array[i], &array[largest]);
        max_heapify(array, largest, heap_size);
    }

}

//从无序的输入数据数组中构造一个最大堆，自底向上构建，保证了每次调用max_heapify之前的两个子树都是最大堆
void build_max_heap(int array[], int heap_size){
    for (int i = heap_size/2; i >= 1; i --)
        max_heapify(array, i, heap_size);
}

//对数组进行原址排序，每次找到最大的，即堆顶，放到数组最后面，形成从后向前排好序的序列，所以是选择排序
void heap_sort(int array[], int len){
    int heap_size = len;
    build_max_heap(array, heap_size);
//    for (int i = len; i >=2; i -- ){
//        swap(&array[1], &array[i]);
//        heap_size -= 1;
//        max_heapify(array, 1, heap_size);
//    }
}