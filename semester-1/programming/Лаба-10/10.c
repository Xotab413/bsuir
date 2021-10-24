#include <stdio.h>
int recurs_nod(int a, int b){//Алгоритм Евклида(можно через остаток))
    if(a==b)
        return (a);
    if(a>b)
        return recurs_nod(a-b,b);
    if(a<b)
        return recurs_nod(a,b-a);
}
int main(){
    int x,y;
    puts("Enter a count");
    scanf("%d",&x);
    scanf("%d",&y);
    printf("your first count is %d and second is %d NOD is %d",x,y,recurs_nod(x,y));
    return 0;
}
