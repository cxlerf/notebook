#include <stdio.h>
#include <string.h>

// 1. 定义一个简单的结构体
typedef struct {
    int id;
    char name[20];
} User;

int main() {
    // 2. 创建一个结构体变量 和一个 指向它的指针变量
    User user_A = { 101, "Alice" };
    User *p_user = &user_A; // p_user 指向了 user_A

    printf("修改前:\n");
    printf("ID: %d, Name: %s\n", user_A.id, user_A.name);
    printf("--------------------------\n");

    // 3. 正确的赋值方式：必须使用括号
    // 我们想要先通过 *p_user 拿到整个 user_A 变量，然后再访问它的 id 成员
    (*p_user).id = 202;
    strcpy((*p_user).name, "Bob");

    printf("修改后 (使用括号):\n");
    printf("ID: %d, Name: %s\n", p_user->id, p_user->name);
    printf("--------------------------\n");


    // 4. 错误的赋值方式：不使用括号 (这行代码会导致编译错误)
    // 如果你取消下面这行的注释，程序将无法编译
    // *p_user.id = 303; 

    printf("程序运行完毕。\n");

    return 0;
}