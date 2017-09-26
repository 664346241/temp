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
#define LL long long
#define INF 0x7fffffff
#define exp 1e-5
#define FOR(i,e) for(int i=0;i<e;i++)
using namespace std;

int mins[400000];
int maxs[400000];
void build(int index,int left,int right){
    int temp;
    if(left>right)
        return ;
    if(left==right)
    {
        cin>>temp;
        mins[index]=maxs[index]=temp;
        return ;
    }
    int mid=(left+right)>>1;
    build(index*2,left,mid);
    build(index*2+1,mid+1,right);
    mins[index]=min(mins[index*2],mins[index*2+1]);
    maxs[index]=max(maxs[index*2],maxs[index*2+1]);
}
void update(int index,int left,int right,int xiu,int value){
    if(left==right){
        mins[index]=maxs[index]=value;
        return ;
    }
    int mid=(left+right)>>1;
    if(xiu>mid){
        update(index,mid+1,right,xiu,value);
    }else{
        update(index,left,mid,xiu,value);
    }
    mins[index]=min(mins[index*2],mins[index*2+1]);
    maxs[index]=max(maxs[index*2],maxs[index*2+1]);
    
}
LL querymin(int index,int left,int right,int l,int r){
   
    if(l>=right||r<=left){
        return 0;
    }
    if(l>=left&&r<=right){
        return mins[index];
    }else{
         int mid=(left+right)/2;
        return min(querymin(index*2,left,mid,l,r),querymin(index*2+1,mid+1,right,l,r));
    }
    
}
LL querymax(int index,int left,int right,int l,int r){
       if(l>=right||r<=left){
        return 0;
    }
    if(l>=left&&r<=right){
        return maxs[index];
    }else{
         int mid=(left+right)/2;
        return max(querymax(index*2,left,mid,l,r),querymax(index*2+1,mid+1,right,l,r));
    }
    
}
LL getMAX(LL a,LL b){
if(a>0){
    return a*a;
}else if(b<0){
    return b*b;
}    
return a*b;
}

int main() {
    int  T,M,N,a,b,c;
    cin>>T;
    while(T--){
        cin>>M;
        build(1,0,(1<<M)-1);
        cin>>N;
        FOR(i,N){
            cin>>a>>b>>c;
            if(a==1){
                cout<<getMAX(querymin(1,0,(1<<M)-1,b,c),querymax(1,0,(1<<M)-1,b,c))<<endl;
            }else{
                update(1,1,(1<<M)-1,b,c);
            }
        }
        
        
        
    }
    return 0;
}
