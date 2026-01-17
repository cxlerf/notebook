#include <stdio.h>
#include <stdlib.h> // 必须包含这个头文件以使用 malloc 和 free

int main() {
    int n;
    int *ptr;
    int sum = 0;

    // 1. 询问用户需要多少空间
    printf("请输入想要输入的整数个数: ");
    scanf("%d", &n);

    // 2. 动态分配内存
    // sizeof(int) 确保跨平台兼容性（Windows/Ubuntu 的 int 通常都是 4 字节）
    ptr = (int*)malloc(n * sizeof(int));

    // 3. 检查内存是否分配成功
    if (ptr == NULL) {
        printf("内存分配失败！程序退出。\n");
        return 1; 
    }

    printf("成功为 %d 个整数分配了内存。\n", n);

    // 4. 使用分配的内存
    for (int i = 0; i < n; i++) {
        printf("输入第 %d 个数: ", i + 1);
        scanf("%d", &ptr[i]); // 也可以写成 scanf("%d", ptr + i);
        sum += ptr[i];
    }

    printf("你输入的总和是: %d\n", sum);

    // 5. 释放内存（非常重要！）
    free(ptr);
    ptr = NULL; // 防止变成野指针

    printf("内存已成功释放。\n");

    return 0;
}