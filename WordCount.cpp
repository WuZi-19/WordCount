#include <stdio.h>
#include <string.h>
int main (int ac, char *arc[])
{
    // ac 表示参数个数，*arc[]指针数组，每一个指针指向一个字符串 
    
    FILE *fp;//文件地址 
    
    int cnt = 0; // 统计数 量初始化为0 
    
    if ((fp=fopen(arc[2], "r")) == NULL)//检测能否打开文件，若能，读取txt文件，不能则输出下列内容 
    {
        puts("打开文件失败!\n");
        return 0;
    }
    
    
    
    if (arc[1][1] == 'w') // 若参数为“w”则实现统计单词 
    {
        char s[1024];
        
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("单词数量=%d\n", cnt);
    }
    
    
    else if (arc[1][1] == 'c') //若参数为“c”则实现统计字符 
    {
        char c;
        
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符数量=%d", cnt);
    }
    
    fclose(fp);//关闭文件 
    
    return 0;
}


