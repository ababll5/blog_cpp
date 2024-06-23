#include <iostream>
using namespace std;

// 冒泡排序函数  参数1：首地址  参数2：函数长度
void maopao(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            // j大于j+1就交换
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 打印数组
void sb(int *arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

int main(void)
{
    // 1、先创建数组
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};

    // 数组长度
    int len = sizeof(arr) / sizeof(arr[0]);
    // 2 创建函数 实现冒泡排序
    maopao(arr, len);

    // 3 打印排序后的数组
    sb(arr, len);

    return 0;
}