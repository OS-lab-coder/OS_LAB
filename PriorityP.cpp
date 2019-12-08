#include<iostream>
using namespace std;

int processes[100][5],NP,scheduler[1000],readyProcesses[100],nrp=0,completion[100],TAT[100];
unsigned int timee =0;

void getSystem()
{
  cout<<"Number of Processess:";
  cin>>NP;
  for (int i=0;i<NP;i++)
  {
		cout<<"Enter the priority for process "<<i<<":";
    cin>>processes[i][0];
    cout<<endl;
    cout<<"Enter the arrival time for process "<<i<<" : ";
		cin>>processes[i][1];
		cout<<endl;
		cout<<"Enter the burst time for process "<<i<<" : ";
		cin>>processes[i][2];
    processes[i][4]=processes[i][2];
  	cout<<endl;
  }
}

int exectionNeeded(){
  for (int i = 0; i < NP; i++)
  {
    if (processes[i][2]>0)
    {
      return 1;
    }
  }     
   return 0;
}

int getProcessTORUn(){

  if(nrp==0){
    return -1;
  }
  int index=readyProcesses[0];
  int minJob=processes[readyProcesses[0]][0];
  for (int i = 0; i < nrp; i++)
  {
      if (processes[readyProcesses[i]][0]>minJob)
      {
        minJob=processes[readyProcesses[i]][0];
        index=readyProcesses[i];
      }
  }
  return index;
}
void addReadyProcesses(){
  for (int i = 0; i < NP; i++)
  {
    if (timee==processes[i][1]&&processes[i][2]>0)
    {
      readyProcesses[nrp]=i;
      nrp++;
    }
  }
}
void removeProcessFromReadyArray(int p){

  int a[100],x=0;
  for (int i = 0; i < nrp; i++)
  {
    if (readyProcesses[i]!=p)
    {
      a[x]=readyProcesses[i];
      x++;
    }
  }
  nrp--;
  for (int i = 0; i < nrp; i++)
  {
    readyProcesses[i]=a[i];
  }
}

void schedule(){
int toRun,x;
while (exectionNeeded()){
  addReadyProcesses();
  toRun=getProcessTORUn();
  scheduler[timee]=toRun;
  processes[toRun][2]=processes[toRun][2]-1;
  timee++;
  if(toRun==-1)
  {
    scheduler[timee]=-1;
    timee++;
  }
  if(processes[toRun][2]==0)
  {
    removeProcessFromReadyArray(toRun);
  }
}
}


void printScheduler(){
cout<<"Scheduler"<<endl;
for (int i = 0; i < timee; i++)
{
  if (scheduler[i]==-1)
  {
   cout<<i<<"\t"<<"->"<<i+1<<"\t"<< "Idle"<<endl; 
  }
  else
  {
    cout<<i<<"\t"<<"->"<<i+1<<"\t"<<"P"<<scheduler[i]+1<<endl;
  }
}

}

void waitingTime()
{
  int release,t;
  for (int i = 0; i < NP; i++)
  {
    t=timee-1;
    release=-1;
    while (release==-1)
    {
      if (scheduler[t]==i)
      {
        release=t+1;
      }
      t--;
    }
    completion[i]=release;
    TAT[i]=release-processes[i][1];
    processes[i][3]=TAT[i]-processes[i][4];
  }  
}
void AvgWaitingTime(){
  int waitingTimeSum=0;
  float averageWaitingTime=0.0;
  for (int i = 0; i < NP; i++)
  {  
    waitingTimeSum+=processes[i][3];
  }
  averageWaitingTime=(float)waitingTimeSum/(float)NP;
  cout<<"averageWaitingTime\t"<<averageWaitingTime<<endl;
}

void final(){
cout<<"Pid\tPriority\tAT\tBT\tCT\tTAT\tWT"<<endl;
for (int i = 0; i < NP; i++)
{
  cout<<"P"<<i<<"\t"<<processes[i][0]<<"\t\t"<<processes[i][1]<<"\t"<<processes[i][4]<<"\t"<<completion[i]<<"\t"<<TAT[i]<<"\t"<<processes[i][3]<<endl;
}

}

int main(){
getSystem();
schedule();
printScheduler();
waitingTime();
final();
AvgWaitingTime();
}
