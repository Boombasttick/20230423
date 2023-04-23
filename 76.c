// 二进制的形式写文件

#include <stdio.h>
#include <errno.h> 
#include <string.h>

struct S
{
    char name[20];
    int age;
    double score;
};


int main()
{
    //struct S s = {"zhangsan",20,55.6};
    struct S tmp = {0};
    FILE* pf = fopen("test1.txt","rb");
    if(pf == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    //fwrite(&s,sizeof(struct S),1,pf);
    fread(&tmp,sizeof(struct S),1,pf);
    printf("%s %d %.1lf",tmp.name,tmp.age,tmp.score);
    fclose(pf);
    pf = NULL;
    return 0;
}  

//stdin 标准输入流   键盘
//stdout 标准输出流    屏幕
//gets   直接从标准输入读取
//puts   直接从标准输出输出