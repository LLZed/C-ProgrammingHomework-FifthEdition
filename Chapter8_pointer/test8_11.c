//在主函数中输入10个等长的字符串。用另一函数对它们排序。然后在主函数输出这10个已排好序的字符串。
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 int main(){
    char str[10][32];
    void sort(char s[10][32]);
    printf("please enter ten string:\n");
    for(int i=0;i<10;i++)
        scanf("%s",str[i]);
    sort(str);
    printf("\n");
    for(int i=0;i<10;i++){
        printf("%s",str[i]);    
        printf("\n");
    }
    system("pause");
    return 0;
 }
 void sort(char s[10][32]){
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(strcmp(s[i],s[j])>0){
                char tmp[32];
                strcpy(tmp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],tmp);
            }
 }