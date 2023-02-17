#include<stdio.h>
#define M 20
#define N 20
float A[M][N];
float B[M][N];
float C[M][N];
int i,j,m,n,p,q;
float y=1.0;
//菜单函数
void memu()
{
    printf("\t\t======================================================\n");
    printf("\t\t||          欢迎您使用矩阵函数包系统                ||\n");
    printf("\t\t||          *********************************       ||\n");
    printf("\t\t||          *           功能菜单          *         ||\n");
    printf("\t\t||          *********************************       ||\n");
    printf("\t\t||                  1.矩阵相加                      ||\n");
    printf("\t\t||                  2.矩阵相减                      ||\n");
    printf("\t\t||                  3.数乘矩阵                      ||\n");
    printf("\t\t||                  4.矩阵转置                      ||\n");
    printf("\t\t||                  5.逆矩阵                        ||\n");
    printf("\t\t||                  6.矩阵的上三角化                ||\n");
    printf("\t\t||                  7.退出                          ||\n");
    printf("\t\t||        *********************************         ||\n");
    printf("\t\t||         请选择您需要的运算，按回车键结束         ||\n");
    printf("\t\t======================================================\n");
}
//两个矩阵相加
void jianjian()
{
    printf("请输入矩阵A的行数和列数(用空格隔开):");
    scanf("%d %d",&i,&j);
    printf("请输入矩阵B的行数和列数(用空格隔开):") ;
    scanf("%d %d",&m,&n);
    if(i!=m||j!=n)
        printf("您输入的两个矩阵不能相加，j!=m,请重试.....\n");
    else
        printf("请输入矩阵A:\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            scanf("%f",&A[p][q]);
    printf("输出矩阵A：\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",A[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }
    printf("请输入矩阵B：\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            scanf("%f",&B[p][q]);

    printf("输出矩阵B：\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",B[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }
    printf("矩阵A+矩阵B为:\n"); //计算两个矩阵相加
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            C[p][q]=A[p][q]+B[p][q];
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",C[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }
}

//两个矩阵相减
void jiajia()
{
    printf("请输入矩阵A的行数和列数(用空格隔开):");
    scanf("%d %d",&i,&j);
    printf("请输入矩阵B的行数和列数(用空格隔开):") ;
    scanf("%d %d",&m,&n);
    if(i!=m||j!=n)
        printf("您输入的两个矩阵不能相加，j!=m,请重试.....\n");
    else printf("请输入矩阵A:\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            scanf("%f",&A[p][q]);
    printf("输出矩阵A:\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",A[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }
    printf("请输入矩阵B：\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            scanf("%f",&B[p][q]);
    printf("输出第矩阵B:\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",B[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }
    printf("矩阵A-矩阵B为：\n"); //计算两个矩阵相减
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            C[p][q]=A[p][q]-B[p][q];
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",C[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }

}

//数乘矩阵
void xiance()
{
    float k;
    printf("请输入矩阵A的行数和列数(用空格隔开):");
    scanf("%d %d",&i,&j);
    printf("请输入矩阵A\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            scanf("%f",&A[p][q]);
    printf("输出矩阵A\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",A[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }
    printf("请输入一个实数:\n");
    scanf("%f",&k);
    for(p=0;p<i;p++) //数乘矩阵
        for(q=0;q<j;q++)
            B[p][q]=k*A[p][q];
    printf("输出k乘矩阵A的结果\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",B[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }

}

//转置矩阵
void cj()
{
    printf("请输入矩阵A的行数和列数(用空格隔开):");
    scanf("%d %d",&i,&j);
    printf("请输入矩阵A:\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
            scanf("%f",&A[p][q]);
    printf("输出矩阵A\n");
    for(p=0;p<i;p++)
        for(q=0;q<j;q++)
        {
            printf("%10.2f",A[p][q]);
            if((q+1)%j==0)
                printf("\n");
        }
    for(p=0;p<i;p++) //转置
        for(q=0;q<j;q++)
            B[q][p]=A[p][q];
    printf("输出矩阵A的转置矩阵:\n");
    for(p=0;p<j;p++)
        for(q=0;q<i;q++)
        {
            printf("%10.2f",B[p][q]);
            if((q+1)%i==0)
                printf("\n");
        }
}

//逆矩阵
void njc()
{
    float a[M][2*M];
    float b[N][2*N];
    float t,x;
    int k,T;
    printf("输入方阵的维数：\n"); //请输入方阵，即行和列相等的矩阵。
    scanf("%d",&T);
    printf("请输入矩阵:\n");
    for(i=0;i<T;i++)
        for (j=0;j<T;j++)
            scanf("%f",&b[i][j]);
    printf("原矩阵为：\n");
    for (i=0;i<T;i++)
    {
        for (j=0;j<T;j++)
            printf("%10.3f",b[i][j]);
        printf("\n");
    }
    for(i=0;i<T;i++)
        for(j=0;j<(2*T);j++)
        {
            if (j<T)
                a[i][j]=b[i][j];
            else if (j==T+i)
                a[i][j]=1.0;
            else
                a[i][j]=0.0;
        }
    for(i=0;i<T;i++)
    {
        for(k=0;k<T;k++)
        {
            if(k!=i)
            {
                t=a[k][i]/a[i][i];
                for(j=0;j<(2*T);j++)
                {
                    x=a[i][j]*t;
                    a[k][j]=a[k][j]-x;
                }
            }
        }
    }
    for(i=0;i<T;i++)
    {
        t=a[i][i];
        for(j=0;j<(2*T);j++)
            a[i][j]=a[i][j]/t;
    }
    for(i=0;i<T;i++)
        y=y*a[i][i];
    if(y==0)
        printf("对不起，您输入的矩阵没有逆矩阵，请重新输入。\n");
    else
    {
        for(i=0;i<T;i++)
            for(j=0;j<T;j++)
                b[i][j]=a[i][j+T];
        printf("逆矩阵为：\n");
        for (i=0;i<T;i++)
        {
            for (j=0;j<T;j++)
                printf("%10.3f",b[i][j]);
            printf("\n");
        }
    }

}

//矩阵的上三角化
void sjcy()
{
    int i, j, k, v, hang, lie;
    double a[50][50], m;
    double b[50][50];  //定义可中途放置的地址
    double c[50][50] = { 0 }; //定义检查层的中途存放地址
    int num1, num2, num3, num4  ;//输入部分
    printf("请输入你想计算的行的个数：");
    scanf("%d", &hang);
    printf("请输入你想计算的列的个数：");
    scanf("%d", &lie);
    for (i = 0; i < hang; ++i)
    {
        printf("请输入第%d行元素：", i + 1);
        for (j = 0; j < lie; ++j)
            scanf("%lf", &a[i][j]);
    }
    //对角化部分
    for (k = 0; k < hang - 1; ++k)
    {
        for (i = k; i < hang - 1; ++i)
        {
            for (j = 0; j < lie; ++j)
            {
                //数组行交换
                if (a[k][k] == 0)
                {
                    for (num1 = k; num1 == k; ++num1)
                    {
                        for (num2 = 0; num2 < lie; ++num2)
                        {
                            c[num1][num2] = a[num1][num2];
                            a[num1][num2] = a[num1 + 1][num2];
                            a[num1 + 1][num2] = c[num1][num2];
                            for (v = 0; v < lie; ++v)
                                b[k][v] = a[k][v];
                        }
                    }
                }
                //矩阵换行结束
                m = a[i + 1][k] / (1.0*a[k][k]);
                b[i + 1][j] = a[i + 1][j] - (m)*a[k][j];
            }
        }
        //将寄存在b中的数据转到a中
        for (num3 = 1; num3 <= hang; ++num3)
            for (num4 = 0; num4 < lie; ++num4)
            {
                a[num3][num4] = b[num3][num4];
            }
    }
    //矩阵输出
    for (i = 0; i < hang; ++i)
    {
        {
            for (j = 0; j < lie; ++j)
                printf("%.2lf    ", a[i][j]);
        }
        printf("\n");
    }

}

//主函数
int main()
{

    int x;
    while(1)
    {
        memu();
        printf("\t\t>>>请选择1--6:");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                jianjian();//两个矩阵相加
                break;
            case 2:
                jiajia();  //两个矩阵相减
                break;
            case 3:
                xiance() ; //数乘矩阵
                break;
            case 4:
                cj();    //转置矩阵
                break;
            case 5:
                njc();  //逆矩阵
                break;
            case 6:
                sjcy();  //矩阵的上三角化
                break;
            case 7:;
                break;
            default:
                printf("\n-----选择错误，请重试-------\n");
                break;
        }
    }
    printf("-------次感谢您使用本系统------------");
    printf("\n");
    printf("******************************************************************\n");
}
