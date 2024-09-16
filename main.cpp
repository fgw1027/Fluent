#include <iostream>

using namespace std;

// 交换两个元素
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 分区函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // 选择最右边的元素作为枢轴
    int i = low - 1; // i 表示小于枢轴的区域的最后一个元素的索引

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // 将小于枢轴的元素移动到左边
        }
    }
    swap(arr[i + 1], arr[high]); // 将枢轴放到正确的位置
    return i + 1; // 返回枢轴的位置
}

// 快速排序函数
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 分区点
        quicksort(arr, low, pi - 1);  // 递归排序左半部分
        quicksort(arr, pi + 1, high); // 递归排序右半部分
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};  // 示例数组
    int n = arr.size();

    quicksort(arr, 0, n - 1); // 对整个数组进行快速排序

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // 输出排序后的数组
    }
    cout << endl;

    return 0;
}
代码说明：
swap 函数：交换数组中的两个元素。
partition 函数：将数组按枢轴元素分区。枢轴选择的是当前数组的最后一个元素。i 指针表示小于枢轴的区域，遍历数组时将小于枢轴的元素交换到左侧。
quicksort 函数：递归地对数组的左右两部分进行快速排序。每次调用 partition 函数确定枢轴位置，并继续对左半部分和右半部分分别进行排序。
main 函数：创建一个示例数组并调用 quicksort 函数对其进行排序，然后输出排序结果。
示例输出：
bash
复制代码
Sorted array: 1 5 7 8 9 10
复杂度：
时间复杂度：
最坏情况：O(n^2)（当每次选择的枢轴是最大或最小元素时）
平均情况：O(n log n)（这是最常见的情况）
空间复杂度：O(log n)（递归调用的栈空间）。





您说：
不要用vector，用c语言的数据
ChatGPT 说：
ChatGPT
记忆已更新
这里是一个使用 C 风格的数组实现的 快速排序 版本的 C++ 代码：

cpp
复制代码
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
