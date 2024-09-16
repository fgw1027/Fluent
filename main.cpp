#include <iostream>

using namespace std;

// 交换两个元素
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最右边的元素作为枢轴
    int i = low - 1;        // i 表示小于枢轴的区域的最后一个元素的索引

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // 将小于枢轴的元素移动到左边
        }
    }
    swap(arr[i + 1], arr[high]);  // 将枢轴放到正确的位置
    return i + 1;  // 返回枢轴的位置
}

// 快速排序函数
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // 分区点
        quicksort(arr, low, pi - 1);  // 递归排序左半部分
        quicksort(arr, pi + 1, high);  // 递归排序右半部分
    }
}

//排序函数
void sort(int arr[],int size)
{
	quicksort(arr,0,size-1);
}

int main()
{
	int arr[]={10,8,3,4,7,98,1};
	int size=sizeof(arr)/sizeof(int);
	sort(arr,size);
	return 0;
}
