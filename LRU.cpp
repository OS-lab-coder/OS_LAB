#include <bits/stdc++.h>
using namespace std;

bool check_availabel(vector<int> FIFO,int page,int F){
    bool flag= false;
    for(int i=0;i<F;i++){
        if(FIFO[i] == page){
            flag = true;
            break;
        }
    }
    return flag;
}

int main(){
    cout<<"Enter Length Page reference :";
    int N;
    cin>>N;

    int page_reference[N];
    cout<<"Enter page String :";
    for(int i=0;i<N;i++){
        cin>>page_reference[i];
    }
    cout<<"Enter Length of Frame :";
    int F;
    cin>>F;
    int Hit_count =0;
    int miss_count = 0;
    // int ref_to_first = 0;
    vector<int> FIFO(F,-1);
    for(int i=0;i<N;i++){
        if(check_availabel(FIFO,page_reference[i],F)){
            Hit_count++;
            vector<int>::iterator it = find(FIFO.begin(),FIFO.end(),page_reference[i]);
            FIFO.erase(it);
            FIFO.push_back(page_reference[i]);
        }else{
            miss_count++;
            vector<int>::iterator it = FIFO.begin();
            FIFO.erase(it);
            FIFO.push_back(page_reference[i]);
        }
        for(int j=0;j<F;j++){
            cout<<FIFO[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Hit :"<<Hit_count<<endl;
    cout<<"Miss : "<<miss_count<<endl;
}