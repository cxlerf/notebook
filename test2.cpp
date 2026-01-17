#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "(AB(C(DE)F)(G((H)I J)K))";
    int len = strlen(str);
    
    // 准备一个栈，用来存放左括号所在的下标（索引）
    int stack[100]; 
    int top = 0;    // 栈顶指针，0 表示栈为空

    printf("字符串: %s\n", str);
    printf("括号配对关系如下：\n");

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            // 压栈：把当前左括号的位置存起来
            stack[top] = i;
            top++;
        } 
        else if (str[i] == ')') {
            // 出栈：取回最近存入的那个左括号位置
            if (top > 0) {
                top--;
                int left_index = stack[top];
                printf("右括号位置 %2d <---> 左括号位置 %2d\n", i, left_index);
            } else {
                printf("错误：右括号在位置 %d 处多余了！\n", i);
            }
        }
    }

    if (top > 0) {
        printf("错误：还有左括号未闭合！\n");
    }

    return 0;
}