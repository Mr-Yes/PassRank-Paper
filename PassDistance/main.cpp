#include<stdio.h>
#include<string.h>

/*递归计算编辑距离 删除、替换、插入 (i行,j列)*/
int dis(char *s,char *t,int j,int i){
	int a,b,c,min;
	if(i>0 && j>0){
		a=t[i-1]==s[j-1]?dis(s,t,j-1,i-1):dis(s,t,j-1,i-1)+1;
		b=dis(s,t,j,i-1)+1;
		c=dis(s,t,j-1,i)+1;
		min=a>b?b:a;
		return min>c?c:min;
	}else if(i==0 && j==0){
		return t[0]==s[0]?0:1;
	}else if(i==0){
		return j;
	}else if(j==0){
		return i;
	}
}
char p[40000][30];
int main(){
    FILE *fp, *fresult;
    if(fp=fopen("myspace.txt","r"))
        printf("Open");

    if(fresult=fopen("myspaceResult.asv","w+"))
        printf("Open");

    int totalNum=0;
    int i,j;
    for(i=0;i<40000;i++){
        fgets(p[i],30,fp);
        //printf("%s",p[i]);
        totalNum++;
    }
    printf("%d",totalNum);
    for(i=0;i<totalNum;i++){
        for(j=0;j<totalNum;j++){
        fprintf(fresult,"%d,",dis(p[i],p[j],strlen(p[i]),strlen(p[j])));
        }
        fputs("\n",fresult);
    }
	//char *s="acdx";
	//char *t="acxx";
	//printf("\nThe Edit Distance of %s  %s:%d\n\n",s,t,dis(s,t,strlen(s),strlen(t)));
    return 0;
}
//该代码片段来自于: http://www.sharejs.com/codes/cpp/7285
