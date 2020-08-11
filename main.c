/*//HELLO WORLD
#include<stdio.h>

int main(){
    printf("hello world!");
}*/

/*//T001.A+B
#include <stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",a+b);
}*/

/*//T002.圆及圆球的相关计算
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.141592653
int main(){
    float r,h;
    scanf("%f%f",&r,&h);
    float l=2*pi*r,s=pi*r*r,sq=4*pi*r*r,vq=4/3*pi*r*r*r,vz=pi*r*r*h;
    printf("%0.2f\n%0.2f\n%0.2f\n%0.2f\n%0.2f\n",l,s,sq,vq,vz);
    return 0;
}*/

/*//T003.计算成绩
#include <stdio.h>
int main(){
    float math,eng,c,mul,avg;
    scanf("%f%f%f",&math,&eng,&c);
    mul=math+eng+c;
    avg=mul/3;
    printf("%.6f\n%.6f",mul,avg);
    return 0;
}*/

/*//T004.找最大数
#include <stdio.h>
int main(){
    int a,b,c,i;
    scanf("%d%d%d",&a,&b,&c);
    if (a>b)
        i=a;
    else i=b;
    if (i<c)
        i=c;
    printf("%d",i);
    return 0;
}*/

/*//T005.找幸运数
#include <stdio.h>
int main(){
    int luck1,a,b,c,d,luck2;
    scanf("%d",&luck1);
    a=luck1/1000;
    b=(luck1-1000*a)/100;
    c=(luck1-1000*a-100*b)/10;
    d=(luck1-1000*a-100*b-10*c)/1;

    if (luck1 >9999)    //计算逆序数的值
        printf("wrong number.");
    else if (luck1 > 999)
        luck2=1000*d+100*c+10*b+a;
    else if (luck1 > 99)
        luck2=100*d+10*c+b;
    else if (luck1 > 9)
        luck2=10*d+c;
    else luck2=d;

    if (luck1==luck2)   //对比逆序前后是否相等
        printf("yes");
    else
        printf("no");
    return 0;
}*/

/*//T005.找幸运数
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i=0,a[5],j;
    scanf("%d",&n);

    if(n==0)
        n=1;

    while(n>=1) {          //定义一个整型数组，取出整数N的每一项存在数组中
        a[i] = n % 10;
        n /= 10;
        i++;
    }

    for(j = 0 ; j<= i/2; j++){
        if(a[j] != a[i - 1- j]) {       //判断整数N首尾对应位置的数是否相等
            printf("no");
            return 0;                  //只要有一个不等，就输出no，并且结束程序
        }

        if(j == (i-1)/2){
            printf("yes");
        }
    }
    return 0;
}*/

/*//T005.找幸运数
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d,e,m,n;
    scanf("%d",&m);
    a=m%10;
    b=((m-a)%100)/10;
    c=((m-a-10*b)%1000)/100;
    d=((m-a-10*b-100*c)%10000)/1000;
    e=((m-a-10*b-100*c-1000*d)%100000)/10000;

    if(e==0)
        if(d==0)
            if(c==0)
                if(b==0)
                    if(a==0)
                        n=0;
                    else
                        n=a;
                else
                    n=10*a+b;
            else
                n=100*a+10*b+c;
        else
            n=1000*a+100*b+10*c+d;
    else
        n=10000*a+1000*b+100*c+10*d+e;
    if(m==n)
        printf("yes");
    else
        printf("no");
    return 0;
}*/

/*//T006.奖金发放
#include <stdio.h>
int main(){
    float lr;
    scanf("%f",&lr);
    if (lr<=10)
        lr=lr*0.1;
    else if (lr<=20)
        lr=10*0.1+(lr-10)*0.075;
    else if (lr<=40)
        lr=10*0.1+10*0.075+(lr-20)*0.05;
    else if (lr<=60)
        lr=10*0.1+10*0.075+20*0.05+(lr-40)*0.03;
    else if (lr<=10)
        lr=10*0.1+10*0.075+20*0.05+20*0.03+(lr-60)*0.015;
    else
        lr=10*0.1+10*0.075+20*0.05+20*0.03+40*0.015+(lr-60)*0.001;
    printf("%f",lr);
    return 0;

}*/

/*
//T007.出租车费
#include <stdio.h>
int main(){
    float price,kilo;
    scanf("%f",&kilo);

    if (kilo-(int)kilo>0)   //向上取整
        kilo=(int)kilo+1;

    if (kilo>15)
        printf("%.6f",7+13*1.5+(kilo-15)*2.1);
    else if (kilo>2)
        printf("%.6f",7+(kilo-2)*1.5);
    else
        printf("7.000000");
    return 0;
}*/

/*//T008.是该年的第几天
#include <stdio.h>
#include <stdbool.h>

bool run(int now);

int main(){
    int year,month,day;
    scanf("%d-%d-%d",&year,&month,&day);
    printf("%d,%d,%d\n",year,month,day);
    int a,b,c=31,d=30;

    if (run(year))  //判断闰年修改2月天数
    {printf("yes!");b=29;}
    else
    {printf("no");b=28;}

    switch (month) {
        case 1:
            a=day;break;
        case 2:
            a=c+day;break;
        case 3:
            a=c+b+day;break;
        case 4:
            a=c+b+c+day;break;
        case 5:
            a=c+b+c+d+day;break;
        case 6:
            a=c+b+c+d+c+day;break;
        case 7:
            a=c+b+c+d+c+d+day;break;
        case 8:
            a=c+b+c+d+c+d+c+day;break;
        case 9:
            a=c+b+c+d+c+d+c+c+day;break;
        case 10:
            a=c+b+c+d+c+d+c+c+d+day;break;
        case 11:
            a=c+b+c+d+c+d+c+c+d+c+day;break;
        default:
            a=c+b+c+d+c+d+c+c+d+c+d+day;break;
    }
    printf("%d",a);

}

bool run(int now) {

    if((now%400==0)||(now%100!=0&&now%4==0))
        return true;
    else
        return false;
}*/


/*
//T009.成绩转换
#include <stdio.h>
int main(){
    int s=scanf("%d",&s);
    if (s>90)
        printf("%c",'A');
    else if (s>80)
        printf("%c",'B');
    else if (s>70)
        printf("%c",'C');
    else if (s>60)
        printf("%c",'D');
    else
        printf("%c",'E');
    return 0;
}*/

/*//T010.求建筑高度
#include <stdio.h>
int main(){
    double x,y;
    scanf("%lf%lf",&x,&y);
    if ((x-2)*(x-2)+(y-2)*(y-2)<=1||(x+2)*(x+2)+(y-2)*(y-2)<=1||(x-2)*(x-2)+(y+2)*(y+2)<=1||(x+2)*(x+2)+(y+2)*(y+2)<=1)
        printf("0");
    else
        printf("10");
    return 0;
}*/

/*//T011.两个整数之间的所有素数
#include <stdio.h>
int sushu(int a);

int main(){
    int a,b,i;
    scanf("%d%d",&a,&b);

    if (a>b){   //调整a小b大
        i=a;
        a=b;
        b=i;
    }

    for(i=a+1;i<b;i++){
        if(sushu(i)!=0&&i!=1)
            printf("%d ",i);
    }
}
int sushu(int a){   //素数验证
    for(int i=2;i<a;i++){
        if(a%i==0)
            return 0;
    }
}*/

/*//T012.完全数
#include <stdio.h>
int main(){
    int a;
    for(int i=6;i<1001;i++) {   //设置范围1-1000
        a = 0;
        for (int j = 1; j < i; j++) {   //找出完全数
            if (i % j == 0)
                a += j;
        }
        if (a == i) {
            printf("%d=", a);
            for (int k = 1; k < i; k++) {   //输出因子相加
                if (i % k == 0) {
                    if (k<a/2)
                        printf("%d+", k);
                    else
                        printf("%d\n",k);
                }
            }
        }
    }
}*/


/*
//T013.整数位数
#include <stdio.h>
int main(){
    float a;
    int b,i;
    scanf("%f",&a);
    b=(int)a;
    for (i=1;;i++){
        b/=10;
        if(b<1)
            break;
    }
    printf("%d",i);
    return 0;
}*/

/*//T014.多项式的猜想 某级数的前两项A1=1，A2=1，以后各项具有如下关系：
//An=An-2+2An-1
//要求依次对于整数M=100，1000和10000求出对应的n值，使其满足：Sn＜M且Sn+1≥M，这里Sn=A1+A2+…+An
#include <stdio.h>
int m(int num);
int main(){
    printf("%d\n",m(100));
    printf("%d\n",m(1000));
    printf("%d",m(10000));
}
int m(int num){
    int a=1,b=1,add=2;
    for (int i=3;;i++){
        a=b;
        b=a+2*b;
        add+=b;
        if (add>num) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}*/

/*
//T015.大学乒乓球比赛
#include <stdio.h>
int main(){
    char A,B,C,D[3]={'X','Y','Z'};
    for (int i = 0;i < 3;i++) {
        A = D[i];
        for (int j = 0;j < 3;j++){
            B = D[j];
            for (int k = 0;k < 3;k++){
                C = D[k];
                if (A != 'X' && B == 'Y' && A != B && B != C && A != C) {
                    printf("A=%c\n", A);
                    printf("B=%c\n", B);
                    printf("C=%c\n", C);
                }
            }
        }
    }
}*/

/*//T016.你会存钱吗
#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c,d,e,a2,b2,c2,d2,e2;
    double f=0;
    for (a=0;a<=2;a++) {
        for (b = 0; b <= 4; b++) {
            for (c = 0; c <= 6; c++) {
                for (d = 0; d <= 10; d++) {
                    for (e = 0; e <= 10; e++) {
                        if (e==20-(8*a)-(5*b)-(3*c)-(2*d)) {    //判定当前收益比上一次大，并保存各个值
                            if (f < 2000 * pow(1 + 0.0084 * 12 * 8, a) * pow(1 + 0.0075 * 12 * 5, b) *
                                    pow(1 + 0.0069 * 12 * 3, c) * pow(1 + 0.0066 * 12 * 2, d) * pow(1 + 0.0063 * 12, e)){
                                f = 2000 * pow(1 + 0.0084 * 12 * 8, a) * pow(1 + 0.0075 * 12 * 5, b) *
                                    pow(1 + 0.0069 * 12 * 3, c) * pow(1 + 0.0066 * 12 * 2, d) * pow(1 + 0.0063 * 12, e);
                                a2=a;
                                b2=b;
                                c2=c;
                                d2=d;
                                e2=e;
                            }

                        }
                    }
                }
            }
        }
    }
    printf("%d %d %d %d %d\n%.2lf\n",a2,b2,c2,d2,e2,f);
    return 0;
    }*/


/*
//T017.奇特的分数数列
#include <stdio.h>
int main(){
    float a=2,b=1,c=0,f=2;

    for (int i = 1;i<20;i++){   //循环得出每一个的值和数列和
        c=a+b;
        b=a;
        a=c;
        f+=a/b;
    }
    printf("%.6lf\n",f);
    return 0;
}*/

/*
//T018.迭代求根
#include <stdio.h>
#include <math.h>
int main(){
    float a=1,b=0;
    int c;
    scanf("%d",&c);
    for (int i=1;;i++){
        b=a;
        a=0.5*(a+c/a);
        if (fabs(a-b)<0.000001) {   //判断绝对值小于10^-5
            printf("%lf", a);
            break;
        }
        return 0;
    }
}*/

/*
//T019.最次方数
#include <stdio.h>
int main(){
    __int64 x,a,b;
    scanf("%lld%lld",&x,&a);
    b=x;
    for (int i=1;i<a;i++){  //硬循环，用64位int算最终值，另一种简单的办法是每次只需要每次循环只要最后三位，因为是乘法
        b*=x;
        printf("%lld\n",b);
    }
        printf("%lld",b%1000);

    return 0;
}*/


/*
//T020.二分法求根
#include <stdio.h>
double fun();
int main(){
    double a,b,c;
    scanf("%lf%lf",&a,&b);
    for(int i=0;;i++){    //for循环不断二分，通过取值点左右异号的性质进行判定
        c=(a+b)/2;
        if (fun(c)>0)
            a=c;
        else if (fun(c)<0)
            b=c;
        else
            break;
    }
    printf("%.2lf",c);
}

double fun(double x){
    return 2*x*x*x-4*x*x+3*x-6;
}*/

/*
//T021.子序列的和
#include <stdio.h>
int main(){
    int n,m;
    float x,f=0;
    scanf("%d%d",&n,&m);
    for(int i=n;i<=m;i++){
        x=i;
        float l=1/(x*x);    //数据陷进，int型作为分母时该式值会失去精度值为0
        printf("%lf,%lf\n",x,l);
        f+=l;
    }
    printf("%lf",f);
    return 0;
}*/

/*//T022.解不等式
#include <stdio.h>
int main(){
    int a,b,c=0;
    float g=0,h=0;
    scanf("%d%d",&a,&b);
    for (int i=0;;i++){
        c+=1;
        float f=c;  //避免数据陷进，需要把int值类型转换为double型，否则后面计算得到的小数均会失去精度
        g=g+1/f;
        h+=1/g;
        //printf("%d,%lf,%lf,%lf\n",c,f,g,h);
        if (h>a&&h-1/g<=a)
            printf("%d",c);
        else if (h<b&&h+1/(g+1/(f+1))>b)
            printf(" %d", c);
        else if (h>b)
            break;
    }
    return 0;
}*/

/*
//T023.幸运数字7
#include<stdio.h>
int main(){
    int n,m,o=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        m=i;
        */
/*if (i%7==0)   //方法1两步判断，先判断7的倍数再判断某位有7
            printf("%d ",i);
        else{*//*

            for (int j = 0;j<5; j++) {  //方法2同时判断7的倍数或某位有7
                o=m%10;
                if (i%7==0||o==7){
                    printf("%d ",i);
                    break;
                }
                m=m/10;

         //}
     }
    }
    return 0;
}*/

//t024.羊羊聚会
#include <stdio.h>
#include <math.h>
int main(){
    int x,y,a,b,L;
    scanf("%d%d%d%d%d",&x,&y,&a,&b,&L);


}
}