#include <stdlib.h>
#include <stdio.h>
#include "Administrator_fun1&2.h"


void information_management()    //管理员功能一：信息管理
{
    int i;
    int operation;
    int step=0;
    for(i=0;i<10;i++)
        printf("*");
    printf("\n");
    printf("请选择您想进行的操作：\n");
    printf("0.退回至前一个界面\n1.录入信息\n2.删除信息\n3.修改信息\n");
    while(1)
    {
        scanf("%d",&operation);
        if(operation>=0&&operation<=3)
        {
            switch(operation)
            {
            case 0: //退回上一个界面
            case 1: information_record();break;
            case 2: information_delete();break;
            case 3: information_change();break;
            }
            break;
        }
        else
        {
            if(step>=10)
            {
                printf("请输入0-3选择您想要的功能\n");
            }
            else if(step>=15)
            {
                //跳回主界面
            }
            printf("不存在该功能,请重新输入\n");
            step++;
        }
    }

}
