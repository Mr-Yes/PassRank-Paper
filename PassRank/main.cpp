#include <stdio.h>
#include <string.h>
//char s1[1000],s2[1000];
#define psNum 20000000
char pswd[psNum][30];
int dist;
int psLen[psNum];

/**/
int editDistance(char *s,char *t,int j,int i){
    int a,b,c,min;
    if(i>0 && j>0){
        a=t[i-1]==s[j-1]?editDistance(s,t,j-1,i-1):editDistance(s,t,j-1,i-1)+1;
        b=editDistance(s,t,j,i-1)+1;
        c=editDistance(s,t,j-1,i)+1;
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

int main()
{
    FILE *fpin;
    FILE *fpout;
    if(fpin=fopen("E:\\PassRankDataSet\\phpbb.txt","r"))
        puts("phpbb\n");
    else
        puts("Open Failed\n");

    int distCnt1=0;
    int distCnt2=0;
    int distCnt3=0;
    int distCnt4=0;
    int totalNum=0;

    int maxLen =0;
    while(fscanf(fpin,"%s",pswd[totalNum]) != EOF){
        psLen[totalNum]=strlen(pswd[totalNum]);
        if(psLen[totalNum]>maxLen){
            maxLen=psLen[totalNum];
            printf("Line: %d \n",totalNum+1);
            printf("%s :Lenth is %d\n",pswd[totalNum],psLen[totalNum]);
        }
        //printf("%s : Lenth is %d\n",pswd[totalNum],psLen[totalNum]);
        totalNum++;
    }
    printf("The totalNum is: %d\n",totalNum);
    printf("The maxLen is: %d\n",maxLen);
    int i,j;
    for(i=0;i<totalNum;i++){
        printf("Cmping Line:%d \n",i);
        for(j=i+1;j<totalNum;j++){
            //printf("Cmping:%d and %d\n",i,j);
            int dist=editDistance(pswd[i],pswd[j],psLen[i],psLen[j]);
            switch(dist){
                case 1:distCnt1++;break;
                case 2:distCnt2++;break;
                case 3:distCnt3++;break;
                case 4:distCnt4++;break;
            }
            if(dist<4)
                break;
        }
    }

	printf("The totalNum is: %d\n",totalNum);
	printf("1: %lf\n",distCnt1/(double)totalNum);
	printf("2: %lf\n",distCnt2/(double)totalNum);
	printf("3: %lf\n",distCnt3/(double)totalNum);
	printf("4: %lf\n",distCnt4/(double)totalNum);
	printf("All ratio is: %lf\n",(distCnt1+distCnt2+distCnt3+distCnt4)/(double)totalNum);

    fclose(fpin);
    fclose(fpout);
}
