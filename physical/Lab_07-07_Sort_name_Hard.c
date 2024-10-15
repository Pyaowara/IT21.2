#include <stdio.h>
#include <ctype.h>
#include <string.h>

void totile(char str[]){
    int check = 0;
    for (int i = 0; i < strlen(str); i++){
        if (isspace(str[i]))
            check = 0;
        else{
            if (check == 0){
                str[i] = toupper(str[i]);
                check = 1;
            }
            else
                str[i] = tolower(str[i]);
        }
    }
}

void bubbleSort(char arr[][60], int n) {
    char temp[60];
    int swapped;
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main(){
    char temp[60];
    int n;
    scanf("%d", &n);
    char name[n][60];

    for (int i = 0; i < n; i++){
        scanf("\n%[^\n]s", name[i]);
        totile(name[i]);
    }
    bubbleSort(name, n);
    for (int i = 0; i < n; i++)
        printf("%s\n", name[i]);
}
