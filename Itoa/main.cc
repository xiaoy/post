#include <stdio.h>

char* my_itoa(int x, char* str, int base);

int main(){
    char buff[33];
    int i;
    scanf("%d", &i);
    my_itoa(i, buff, 10);
    printf("%d convert to str:%s\n", i, buff);

    my_itoa(i, buff, 2);
    printf("%d convert to binary str:%s\n", i, buff);

    my_itoa(i, buff, 8);
    printf("%d convert to october str:%s\n", i, buff);

    my_itoa(i, buff, 16);
    printf("%d convert to october str:%s\n", i, buff);
}

char* my_itoa(int x, char* str, int base){
    bool is_neg;
    if(x < 0){
        is_neg = true;
        x = -x;
    }

    int a;
    int num;
    int i;
    for(i = 0; x != 0; ++i){
        a = x / base;
        if(i == 0 && is_neg){
            str[i] = '-';
            i = i + 1;
        }
        num = x % base;
        if(num < 0xA)
            str[i] = num + '0';
        else
            str[i] = 'A' + num - 0xA;
        x = a;
    }
    str[i] = '\0';

    int str_len = i - 1;
    int swap_len;
    if(str_len > 1){
        swap_len = str_len / 2;
    }else{
        swap_len = str_len;
    }

    for(i = 0; i < swap_len; ++i){
        char temp;
        if(is_neg){
            temp = str[i + 1];
            str[i + 1] = str[str_len - i];
        }else{
            temp = str[i];
            str[i] = str[str_len - i];
        }
        str[str_len - i] = temp;
    }

    return str;
}
