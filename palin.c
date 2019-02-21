//
// Created by HongJeongmin on 2019-02-21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FOR(i,b,e) for((i)=(b); (i)<(e); ++i)

int length(const char* str)
{
    int len=0,i;
    for(i=0;str[i]!='\0';++i)
        ;
    len = i;
    return len;
}

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

bool chkPalin(char* str)
{
    int mid=length(str)/2,i;
    printf("%s : length = %d, mid index = %d\n", str, length(str), mid);
    FOR(i,0,mid)
        if(str[i] == str[length(str)-1-i])
            continue;
        else
            return false;
    return true;
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
            strcat(result,"not pandlin.\n");
        }
    }

    result[length(result)-1] = '\0';
    fprintf(outfp, "%s", result);

    fclose(outfp);
    fclose(infp);
    free(strList[0]);
    free(strList);
    return EXIT_SUCCESS;
}