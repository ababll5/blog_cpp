// 包含iostream头文件，使用std命名空间
#include <iostream>
using namespace std;

// 定义Student结构体，包含name、age、score三个成员变量
struct Student
{
    string name;
    int age;
    int score;
};

// 定义Teacher结构体，包含name、age、salary、stu四个成员变量
struct Teacher
{
    string name;
    int age;
    int salary;
    Student stu;
};

// 主函数，程序从这里开始执行
int main()
{
    using namespace std;
    // 定义Teacher类型的变量t1，并初始化其成员变量
    Teacher t1 = {"张三", 38, 5000, {"李四", 18, 90}};

    // 输出t1的成员变量
    cout << "姓名：" << t1.name << endl;
    cout << "年龄：" << t1.age << endl;
    cout << "工资：" << t1.salary << endl;
    cout << "姓名：" << t1.stu.name << endl;
    cout << "年龄：" << t1.stu.age << endl;
    cout << "成绩：" << t1.stu.score << endl;

 

    // 函数返回值为0，表示程序正常结束
    return 0;
}