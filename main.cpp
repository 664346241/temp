/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: byy
 *
 * Created on 2017年9月8日, 下午3:37
 */

#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<functional>
#include<string.h>
#include<stack>
#define CC( a , x ) memset ( a , x , sizeof(a) )
#define ll long long
#define INF 0x7fffffff
#define exp 1e-5
#define FOR(i,e) for(int i=0;i<e;i++)
using namespace std;
int M,beg,te;
int v[100000],ne[100000];
int link[100000];
bool cmp(int a,int b){
    return v[a]<v[b];
}
int main() {
    cin>>M>>beg;
    FOR(i,M){
        cin>>te;
        cin>>v[te]>>ne[te];
    }
    if(beg==-1){
        
        printf("0 -1\n");
        return 0;
    }
     if(M==0){
        
        printf("0 %05d\n",beg);
        return 0;
    }
    te=beg;
    int index=0;
    while(te!=-1){
        link[index++]=te;
        te=ne[te];    
    }
    sort(link,link+index,cmp);
    cout<<index<<" "<<link[0]<<endl;
    FOR(i,index-1){
        printf("%05d %d %05d\n",link[i],v[link[i]],link[i+1]);
        
    }
     printf("%05d %d -1\n",link[index-1],v[link[index-1]]);
    return 0;
}
