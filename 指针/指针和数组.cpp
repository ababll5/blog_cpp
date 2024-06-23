#include <iostream>
using namespace std;

int main(void)
{
    //****** 指针和数组 ***** */
    // 利用指针访问数组的元素
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "第一个元素 " << arr[0] << endl;
    int *p = arr; // arr就是数组的首地址
    cout << "指针访问第一个元素 " << *p << endl;
     
    cout<<endl<<endl<<endl;          //全是空行不用理


     cout<<"利用指针访问所有"<<endl;
     int *p2 = arr;
     for(int i;i<10;i++)
     {
      cout<<"指针访问第"<<i<<"个元素:"<<*p2<<endl;
      p2++;

     }


    return 0;
}
