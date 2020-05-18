#include <stdio.h>
void count (char n){
    if (n==0) {
        return; //базовый случай
    }else{
        printf("n = %d \n", n);
        count(n-1); //рекурсивный случай
    }
}
int main()
{
    count(3);
    return 0;
}
