#include <stdio.h>
#include <string.h>
int main (int ac, char *arc[])
{
    // ac 表示参数个数，*arc[]指针数组，每一个指针指向一个字符串 
    FILE *fp;
    int cnt = 0; // 统计数 
    if ((fp=fopen(arc[2], "r")) == NULL)
    {
        puts("打开文件失败!\n");
        return 0;
    }
    if (arc[1][1] == 'w') // 统计单词 
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
    else if (arc[1][1] == 'c') // 统计字符 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符数量=%d", cnt);
    }
    fclose(fp);
    return 0;
}


