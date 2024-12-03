#include <stdio.h>

void calculator();

int main() {
    printf("사칙연산 계산기\n");
    printf("사용법: 연산자를 선택하고 두 숫자를 입력하세요.\n");
    printf("예: + 2 3\n");
    printf("종료하려면 'q'를 입력하세요.\n\n");
    calculator();
    return 0;
}

void calculator() {
    char operator;
    double num1, num2, result;

    while (1) {
        printf("연산자와 두 숫자를 입력하세요 (예: + 2 3): ");
        int input_status = scanf(" %c", &operator);

        if (input_status != 1 || operator == 'q') {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        if (operator == '+' || operator == '-' || operator == '*' || operator == '/') {
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("잘못된 입력입니다. 다시 시도하세요.\n");
                while (getchar() != '\n'); // 입력 버퍼 비우기
                continue;
            }

            switch (operator) {
                case '+':
                    result = num1 + num2;
                    printf("결과: %.2lf\n", result);
                    break;
                case '-':
                    result = num1 - num2;
                    printf("결과: %.2lf\n", result);
                    break;
                case '*':
                    result = num1 * num2;
                    printf("결과: %.2lf\n", result);
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("0으로 나눌 수 없습니다.\n");
                    } else {
                        result = num1 / num2;
                        printf("결과: %.2lf\n", result);
                    }
                    break;
            }
        } else {
            printf("유효하지 않은 연산자입니다. 다시 입력하세요.\n");
        }
    }
}
