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
    int page_Refrence[N+3];
    for(int i=0;i<N;i++){
        cin>>page_Refrence[i];
        // cout<<page_Refrence[i]<<" ";
    }
    page_Refrence[N] = start_track;
    page_Refrence[N+1] = end_track;
    cout<<"Enter Head Position : ";
    int Head;
    cin>>Head;
    // int flag[N] = {0};
    int answer = 0;
    int insert_flag = true;
    for(int i=0;i<N+2;i++){
        if(Head == page_Refrence[i]){
            insert_flag = false;
            break;
        }
    }
    if(insert_flag){
        page_Refrence[N+2] = Head;
        N = N+1;
    }
    sort(page_Refrence,page_Refrence+N+2);
    int head_index = 0;

    for(int i=0;i<N+2;i++){
        // cout<<page_Refrence[i]<<" ";
        if(Head==page_Refrence[i]){
            head_index = i;
        }
    }
    // cout<<endl;
    int first = head_index;
    int second;
    for(int i=0;i<N+1;i++){
        second = (first +1)%(N+2);
        answer += abs(page_Refrence[first]-page_Refrence[second]);
        cout<<"("<<page_Refrence[first]<<"-"<<page_Refrence[second]<<") - ";
        first = (first+1)%(N+2);
    }
    cout<<"\ntotal head movement :"<<answer<<endl;
    return 0;
}