#include <stdio.h>
#include <string.h>
int main (int ac, char *arc[])
{
    // ac ��ʾ����������*arc[]ָ�����飬ÿһ��ָ��ָ��һ���ַ��� 
    
    FILE *fp;//�ļ���ַ 
    
    int cnt = 0; // ͳ���� ����ʼ��Ϊ0 
    
    if ((fp=fopen(arc[2], "r")) == NULL)//����ܷ���ļ������ܣ���ȡtxt�ļ�������������������� 
    {
        puts("���ļ�ʧ��!\n");
        return 0;
    }
    
    
    
    if (arc[1][1] == 'w') // ������Ϊ��w����ʵ��ͳ�Ƶ��� 
    {
        char s[1024];
        
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("��������=%d\n", cnt);
    }
    
    
    else if (arc[1][1] == 'c') //������Ϊ��c����ʵ��ͳ���ַ� 
    {
        char c;
        
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("�ַ�����=%d", cnt);
    }
    
    fclose(fp);//�ر��ļ� 
    
    return 0;
}


