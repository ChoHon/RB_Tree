#include <stdio.h>

int hab(int x, int y);

void main() {

    int a, b, dab;
    printf("정수 a, b를 입력하시오");
    scanf("%d %d", &a, &b);
    dab = hab(a, b);
    printf("\n%d + %d = %d \n", a, b, dab);
}
int hab(int x, int y) {

    return (x + y);
}