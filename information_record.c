#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structname.h"
#include "Administrator_fun1&2.h"
#include <windows.h>

int transfer_num(char* s)
{
    int num=0;
    int len;
    len=strlen(s);
    int i,y=1;
    for(i=len-1;i>=0;i--)
    {
        num+=(s[i]-'0')*y;
        y*=10;
    }
    return num;
}


/*void information_record()
{
     int i;
    int operation;
    int step=0;
    for(i=0;i<10;i++)
        printf("*");
    printf("\n");
    printf("请选择信息类型：\n");
    printf("0.退回至前一个界面\n1.部门信息\n2.员工信息\n3.职位信息\n");
    while(1)
    {
        scanf("%d",&operation);
        if(operation>=0&&operation<=3)
        {
            switch(operation)
            {
            case 0: //退回上一个界面
            case 1: department_information_record();break;      //部门信息录入
            case 2: staff_information_record();break;           //员工信息录入
            case 3: pos_information_record();break;             //职位信息录入
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
}*/


void department_information_record()
{
    //SetConsoleOutputCP(65001);

    FILE *fp;
    char command_back_frontstep[]="Back"; //返回上一步
    char command_quit[]="Quit";   //退出当前页面
    char str[30];
    int command_step=1;
    struct Department mid;
    int step;
    char c;


    printf("输入\"Back\"返回上一步\n");
    printf("输入\"Quit\"退出当前页面并且不会保留任何信息\n");

    while(1)
    {
        if(command_step==0)
            break;
        else if(command_step==1){//输入部门编号
            while(1){
                    int flag=1;
                    for(step=0;step<10;step++){
                printf("请输入部门编号（8位）：");
                scanf("%29s",str);
                mid.Department_ID=str;
                if(strcmp(mid.Department_ID,command_back_frontstep)==0||strcmp(mid.Department_ID,command_quit)==0){
                    command_step=0;
                    flag=0;
                    break;
                }
                int len;
                len=strlen(mid.Department_ID);
                if(len==8){
                    command_step=2;
                    flag=0;
                    break;
                }
                else
                {
                    printf("输入不合规，请重新输入\n");
                    continue;
                }


                    }
                    if(flag==0)
                        break;
            }
        }

        else if(command_step==2){
            while(1)
            {
                c=getchar();
                printf("请输入部门名称：");
                char *name=read_information_fun();
                //printf("%s\n",name);
                if(name==NULL)
                {
                    printf("内存分配失败，请重新输入");
                    continue;
                }
                if(strcmp(name,command_back_frontstep)==0)
                {
                    command_step=1;
                    free(name);
                    break;
                }
                if(strcmp(name,command_quit)==0)
                {
                    command_step=0;
                    free(name);
                    break;
                }
                else
                {
                    command_step=3;
                    mid.Department_name=name;
                    break;
                }
            }

        }
        else if(command_step==3)
        {
            while(1)
            {
                //c=getchar();
                printf("请输入部门主管姓名：");
                char *m_name=read_information_fun();
                //printf("%s\n",m_name);
                if(m_name==NULL)
                {
                    printf("内存分配失败，请重新输入");
                    continue;
                }
                if(strcmp(m_name,command_back_frontstep)==0)
                {
                    command_step=2;
                    free(m_name);
                    break;
                }
                if(strcmp(m_name,command_quit)==0)
                {
                    command_step=0;
                    free(m_name);
                    break;
                }
                else
                {
                    command_step=4;
                    mid.Manager_name=m_name;
                    break;
                }
            }
        }



        else if(command_step==4)
                {
                    while(1)
                    {
                        //c=getchar();
                        printf("请输入部门成立时间：");
                        char *time=read_information_fun();
                        printf("%s\n",time);
                        if(time==NULL)
                        {
                            printf("内存分配失败，请重新输入");
                            continue;
                        }
                        if(strcmp(time,command_back_frontstep)==0)
                        {
                            command_step=3;
                            free(time);
                            break;
                        }
                        if(strcmp(time,command_quit)==0)
                        {
                            command_step=0;
                            free(time);
                            break;
                        }
                        else
                        {
                            command_step=5;
                            mid.Established_time=time;
                            break;
                        }
                    }
                }


        else if(command_step==5)
                {
                    while(1)
                    {
                        //c=getchar();
                        printf("请输入部门人数：");
                        char *de_num=read_information_fun();
                        printf("%s\n",de_num);
                        if(de_num==NULL)
                        {
                            printf("内存分配失败，请重新输入");
                            continue;
                        }
                        if(strcmp(de_num,command_back_frontstep)==0)
                        {
                            command_step=4;
                            free(de_num);
                            break;
                        }
                        if(strcmp(de_num,command_quit)==0)
                        {
                            command_step=0;
                            free(de_num);
                            break;
                        }
                        else
                        {
                            command_step=-1;
                            mid.Department_person_num=transfer_num(de_num);
                            //printf("%d\n",mid.Department_person_num);
                            break;
                        }
                    }
                }

        else if(command_step==-1)
            break;

    }


    if(command_step==-1)
    {
        printf("开始录入");
        fp=fopen("department information.txt","at+");
        fprintf(fp,"%s",mid.Department_ID);
        fprintf(fp,"%s",mid.Department_name);
        fprintf(fp,"%s",mid.Manager_name);
        fprintf(fp,"%s",mid.Established_time);
        fprintf(fp,"%d",mid.Department_person_num);
        free(mid.Department_ID);
        free(mid.Department_name);
        free(mid.Manager_name);
        free(mid.Established_time);
        free(mid.Department_person_num);
    }
    return 0;
}