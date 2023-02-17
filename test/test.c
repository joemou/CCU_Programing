    #include <stdio.h>
    
    int main(){
 
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