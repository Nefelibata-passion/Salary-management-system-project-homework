#include <stdlib.h>
#include <stdio.h>
#define MAX_CAPACITY 256

char* read_information_fun()
{
    int capacity=16;  //初始容量
    int len=0;        //初始长度
    char *buffer=(char*)malloc(capacity*sizeof(char));
    if(buffer==NULL)
        return NULL;    //内存分配失败
    int c;
    while((c=getchar())!='\n'&&c!=EOF)
    {
        if(len+1>=capacity) //检查并预留'\0'
        {
            int new_capacity=capacity*=2;
            if(capacity>MAX_CAPACITY||new_capacity<capacity)
            {
                free(buffer);
                return NULL;
            }
            char *temp=(char*)realloc(buffer,new_capacity);
            if(temp==NULL)
            {
                free(buffer);
                return NULL;    //扩容失败
            }
            buffer=temp;
        }
        buffer[len++]=(char)c;

    }
    buffer[len]='\0';
    return buffer;
}
