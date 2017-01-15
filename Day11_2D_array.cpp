/**
    @file   : Day11_2D_array.cpp
    @date   : 01.15.2017
    @author : Hyungjun Lee
    @mail   : hjlee1765@gmail.com
    @refer  : Hacker Rank
*/

#include <iostream>
#include <cstring>
#define MAX 16

using namespace std;

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *s, int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i ; j++){
            if(s[j] < s[j+1])
                swap(s[j],s[j+1]);
        }
    }
}

void sumCal(int *sum, int (*h_arr)[6]){
    int len = 0;
     for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sum[len++] = h_arr[i][j] + h_arr[i][j+1] + h_arr[i][j+2] + h_arr[i+1][j+1] + h_arr[i+2][j] + h_arr[i+2][j+1] + h_arr[i+2][j+2];
        }
    }
}

int main(){
    int h_arr[6][6] = {0};
    int *sum = new int[MAX];
    memset(sum, 0, MAX * sizeof(int));
    int len=0;
    
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cin >> h_arr[i][j];
        }
    }

    sumCal(sum, h_arr);
    
    bubbleSort(sum,MAX); 
    
    cout << sum[0];

    return 0;
}
