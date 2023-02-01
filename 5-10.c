#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char **head = argv;
    char c;

    int result = 0;
    int index = 0;
    int started = 0;
    while (--argc > 0) {
        c = **++argv;
        switch (c) {
            case '+':
                if (started)
                    result += atoi(*(head + --index));
                else{
                    started = 1;
                    result = atoi(*(head + index)) + atoi(*(head + --index));
                }
                break;
            case 'x':
                if (started)
                    result *= atoi(*(head + --index));
                else{
                    started = 1;
                    result = atoi(*(head + index)) * atoi(*(head + --index));
                }
                break;
            case '-':
                if (started)
                    result -= atoi(*(head + --index));
                else{
                    started = 1;
                    result = atoi(*(head + index)) - atoi(*(head + --index));
                }
                break;
            case '/':
                if (started)
                    result /= atoi(*(head + --index));
                else{
                    started = 1;
                    result = atoi(*(head + index)) / atoi(*(head + --index));
                }
                break;
            case '%':
                if (started)
                    result %= atoi(*(head + --index));
                else{
                    started = 1;
                    result = atoi(*(head + index)) % atoi(*(head + --index));
                }
                break;
            default:
                index++;
                break;
        }
    }
    printf("Result: %d \n", result);
    return 0;
}


