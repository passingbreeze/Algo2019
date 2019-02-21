//
// Created by HongJeongmin on 2019-02-21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FOR(i,b,e) for((i)=(b); (i)<(e); ++i)

char** strArray(int strNum)
{
    char** result;
    int i;

    result = (char**)malloc(sizeof(char*)*strNum);
    result[0] = (char*)malloc(sizeof(char)*strNum*BUFSIZ);
    FOR(i,1,strNum)
        result[i] = result[i-1] + BUFSIZ;

    return result;
}

void delChr(char* str, char ch)
{
    for(;(*str)!='\0'; ++str){
        if(*str == ch){
            strcpy(str, str+1);
            str--;
        }
    }
}

bool chkPalin(const char* str)
{
    int mid=strlen(str)/2,i;
    FOR(i,0,mid)
        if(str[i] == str[strlen(str)-1-i])
            continue;
        else
            return false;
    return true;
}

bool reChkPalin(char* str)
{
    int mid=strlen(str)/2,i;
    FOR(i,0,mid){
        if(str[i] != str[strlen(str)-1-i]){
            delChr(str, str[strlen(str)-1-i]);
            break;
        }
    }

    if(chkPalin(str))
        return true;
    else
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
    char result[BUFSIZ] = "";

    fscanf(infp, "%d", &num);

    strList = strArray(num);

    FOR(i, 0, num)
        fscanf(infp, "%s", strList[i]);

    FOR(i,0,num){
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