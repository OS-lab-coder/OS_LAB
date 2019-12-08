#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter track starting value : ";
    int start_track;
    cin>>start_track;
    cout<<"Enter track End value : ";
    int end_track;
    cin>>end_track;
    cout<<"Enter Length of Refrence String : ";
    int N;
    cin>>N;
    cout<<"Enter Page Refrence string : ";
    int page_Refrence[N];
    for(int i=0;i<N;i++){
        cin>>page_Refrence[i];
        // cout<<page_Refrence[i]<<" ";
    }
    cout<<"Enter Head Position : ";
    int Head;
    cin>>Head;
    int flag[N] = {0};
    int answer = 0;
    for(int i=0;i<N;i++){
        int difference[N];
        for(int j=0;j<N;j++){
            if(!flag[j]){
                difference[j] = abs(Head-page_Refrence[j]);
            }else{
                difference[j] = 999999999;
            }
        }
        int min_index = 0;
        int min_diff = difference[0];
        for(int j=1;j<N;j++){
            if(min_diff >= difference[j]){
                min_diff = difference[j];
                min_index = j;
            }
        }
        flag[min_index] = true;
        answer += abs(Head-page_Refrence[min_index]);
        cout<<"("<<Head<<"-"<<page_Refrence[min_index]<<") - ";
        Head =  page_Refrence[min_index];
    }
    cout<<"\ntotal seek count is : "<<answer;
}