#include <stdio.h>
#include <string.h>
#define psNum 20000000
char pswd[psNum][30];
int dist;
int psLen[psNum];

#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
int levenshtein(char *s1, char *s2);

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
    //To Detect any passwd longer than 30
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
        //printf("Cmping Line:%d \n",i);
        for(j=i+1;j<totalNum;j++){
            //printf("Cmping:%d and %d\n",i,j);
            int dist= levenshtein(pswd[i],pswd[j]);
            //printf("The Dist of (%s,%s): %d\n",pswd[i],pswd[j],dist);
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

int levenshtein(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = MIN3(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));

    return(matrix[s2len][s1len]);
}



/*
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
}*/

