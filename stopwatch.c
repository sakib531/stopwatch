#include<stdio.h>
#define CYCLE 60
#ifdef _WIN32
#define sleep(x) Sleep(x*1000)
#define Clear_Screen system("cls")
#else
#define CLEAR_SCREEN printf("\e[1;1H\e[2J")
//#define clrscr() printf("\e[1;1H\e[2J")
#inclue<unistd.h>
#endif // _WIN32
int main() {
    int hour,minute,second;
    printf("enter the time");
    scanf("%d %d %d",&hour,&minute,&second);
    int h=0,m=0,s=0;
    while (1){
            Clear_Screen;
            printf("%.2d :%.2d :%.2d\n",h,m,s);
        if(h==hour && m==minute && s==second){
            break;
        }
        s++;
        sleep(1);
        if (s==CYCLE){
            m++;
            s=0;
        }
        if (m==CYCLE){
            h++;
            m=0;
        }
    }
    return 0;
}
