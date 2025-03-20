#include<stdio.h>
#include<stdlib.h>
int main(){
int arr[5];
int *pt=arr;
printf("%d",pt);
int *arp=realloc(pt,10*4);
printf("%d", arp);
}
