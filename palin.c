//
// Created by HongJeongmin on 2019-02-21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define FOR(i,b,e) for((i)=(b); (i)<(e); ++i)
#define reFOR(i,e,b) for((i)=((e)-1); (i)>=(b); --i)

char** strArray(int strNum)
{
    char** result;
    int i;

    result = (char**)malloc(sizeof(char*)*strNum);
    result[0] = (char*)malloc(sizeof(char)*strNum*(BUFSIZ*100));
    FOR(i,1,strNum)
        result[i] = result[i-1] + (BUFSIZ*100);

    return result;
}

char* delChr(char* str, char ch)
{
    char *temp = (char*)malloc(sizeof(char)*(BUFSIZ*100));
    strcpy(temp,str);
    for(;(*temp)!='\0'; ++temp){
        if(*temp == ch){
            strcpy(temp, temp+1);
            temp--;
        }
    }
    return temp;
}

bool chkPalin(const char* str)
{
    int mid = strlen(str)/2;
    int i;
    FOR(i,0,mid)
        if(str[i] != str[strlen(str)-1-i])
            return false;
    return true;
}

bool reChkPalin(char* str)
{
    int mid = strlen(str)/2;
    int i;

    char *fPart = (char*)malloc(sizeof(char)*(BUFSIZ*100));
    char *bPart = (char*)malloc(sizeof(char)*(BUFSIZ*100));
    char *fSub = (char*)malloc(sizeof(char)*(BUFSIZ*100));
    char *bSub = (char*)malloc(sizeof(char)*(BUFSIZ*100));
    strncpy(fPart, str, mid);

    reFOR(i,strlen(str), mid)
        bPart[strlen(str)-1-i] = str[i];

//    printf("%s || %s\n%d || %d\n", fPart, bPart, strlen(fPart), strlen(bPart));

    FOR(i,0,mid){
        if(fPart[i] != bPart[i]){
            strcpy(fSub, delChr(fPart, fPart[i]));
            strcpy(bSub, delChr(bPart, bPart[i]));
            printf("%s %s\n", fSub, bSub);
            if(strstr(bPart, fSub) || strstr(fPart, bSub)){

                if(fSub != NULL)
                    free(fSub);

                if(bSub != NULL)
                    free(bSub);

                free(bPart);
                free(fPart);
                return true;
            }
        }
    }

    if(fSub != NULL)
        free(fSub);

    if(bSub != NULL)
        free(bSub);

    free(bPart);
    free(fPart);
    return false;
}

int main()
{
    FILE *infp, *outfp;
    infp = fopen("palin.inp", "rb");
    outfp = fopen("palin.out", "wb");

    if(infp == NULL){
        printf("Input file not Found.\n");
        return EXIT_FAILURE;
    }

    int i, num;
    char **strList;
    char result[11] = "";

    fscanf(infp, "%d", &num);

    strList = strArray(num);

    FOR(i, 0, num)
        fscanf(infp, "%s", strList[i]);

    FOR(i, 0, num){
        printf("%s\n", strList[i]);
        if(chkPalin(strList[i]))
            strcat(result,"1\n");
        else{
            if(reChkPalin(strList[i]))
                strcat(result,"2\n");
            else
                strcat(result,"3\n");
        }
    }

    result[strlen(result)-1] = '\0';
    fprintf(outfp, "%s", result);

    fclose(outfp);
    fclose(infp);
    free(strList[0]);
    free(strList);
    return EXIT_SUCCESS;
}