// 5个英雄不同年龄大小，用冒泡排序把他们通过年龄大小排序

#include <iostream>
#include <string>
using namespace std;

// 定义英雄结构体
struct ying
{
    string name; // 姓名
    int age;     // 年龄
    string man;  // 性别
};

void paopao(struct ying xiong[], int len) // 冒泡排序
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            // 如果j元素的年龄大于j+1就交换
            if (xiong[j].age > xiong[j + 1].age)
            {
                struct ying temp = xiong[j];
                xiong[j] = xiong[j + 1];
                xiong[j + 1] = temp;
            }
        }
    }
}

// 打印排序后的
void printxiong(struct ying xiong[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout<<"排序后"<<endl;
        cout << "姓名: " << xiong[i].name << endl
             << " 年龄: " << xiong[i].age << endl
             << " 性别: " << xiong[i].man << endl;
    }
}

int main(void)
{
    // 录入5位英雄的数据
    struct ying xiong[5] =
        {
            {"刘备", 23, "男"},
            {"张飞", 20, "男"},
            {"赵云", 21, "男"},
            {"貂蝉", 19, "男"},
            {"关羽", 22, "男"},
        };

    int len = sizeof(xiong) / sizeof(xiong[0]);
    cout << "***************阶段性测试(必要)******************" << endl;
    cout<<"排序前"<<endl;
    for (int i = 0; i < len; i++)
    {
        cout << "姓名: " << xiong[i].name << endl
             << " 年龄: " << xiong[i].age << endl
             << " 性别: " << xiong[i].man << endl;
    }
    cout << "**********************************************" << endl<< endl << endl;

    // 进行排序
    paopao(xiong, len);

    // 打印排序后的结果
    printxiong(xiong, len);

    return 0;
}