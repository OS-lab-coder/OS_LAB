#include <iostream>
using namespace std;

int processes[100][4], NP, scheduler[1000], readyProcesses[100], nrp = 0, completion[100], TAT[100];
unsigned int timee = 0;
int response[100];

void getSystem()
{
  cout << "Number of Processess:";
  cin >> NP;
  for (int i = 0; i < NP; i++)
  {
    cout << "Enter the arrival time for process " << i << " : ";
    cin >> processes[i][0];
    cout << endl;
    cout << "Enter the burst time for process " << i << " : ";
    cin >> processes[i][1];
    processes[i][2] = processes[i][1];
    cout << endl;
  }
}

int exectionNeeded()
{
  int b = 0;
  for (int i = 0; i < NP; i++)
  {
    if (processes[i][2] > 0)
    {
      b = 1;
    }
  }
  return b;
}

int getProcessTORUn()
{

  if (nrp == 0)
  {
    return -1;
  }
  int index = readyProcesses[0];
  int minJob = processes[readyProcesses[0]][2];
  for (int i = 0; i < nrp; i++)
  {
    if (processes[readyProcesses[i]][2] < minJob)
    {
      minJob = processes[readyProcesses[i]][2];
      index = readyProcesses[i];
    }
  }
  return index;
}
void addReadyProcesses()
{
  for (int i = 0; i < NP; i++)
  {
    if (processes[i][0] == timee)
    {
      readyProcesses[nrp] = i;
      nrp++;
    }
  }
}
void removeProcessFromReadyArray(int p)
{

  int a[100], x = 0;
  for (int i = 0; i < nrp; i++)
  {
    if (readyProcesses[i] != p)
    {
      a[x] = readyProcesses[i];
      x++;
    }
  }
  nrp--;
  for (int i = 0; i < nrp; i++)
  {
    readyProcesses[i] = a[i];
  }
}

void schedule()
{
  int toRun, x;
  while (exectionNeeded())
  {
    addReadyProcesses();
    toRun = getProcessTORUn();
    scheduler[timee] = toRun;
    processes[toRun][2] = processes[toRun][2] - 1;
    timee++;
    if (toRun == -1)
    {
      scheduler[timee] = -1;
      timee++;
    }
    if (processes[toRun][2] == 0)
    {
      removeProcessFromReadyArray(toRun);
    }
  }
}

void printScheduler()
{
  cout << "Scheduler" << endl;
  for (int i = 0; i < timee; i++)
  {
    if (scheduler[i] == -1)
    {
      cout << i << "\t"
           << "->" << i + 1 << "\t"
           << "Idle" << endl;
    }
    else
    {
      cout << i << "\t"
           << "->" << i + 1 << "\t"
           << "P" << scheduler[i] + 1 << endl;
    }
  }
}

void waitingTime()
{
  int release, t;
  for (int i = 0; i < NP; i++)
  {
    t = timee - 1;
    release = -1;
    while (release == -1)
    {
      if (scheduler[t] == i)
      {
        release = t + 1;
      }
      t--;
    }
    completion[i] = release;
    processes[i][3] = release - processes[i][0] - processes[i][1];
    TAT[i] = release - processes[i][0];
  }
}
void AvgWaitingTime()
{
  int waitingTimeSum = 0;
  float averageWaitingTime = 0.0;
  for (int i = 0; i < NP; i++)
  {
    waitingTimeSum += processes[i][3];
  }
  averageWaitingTime = (float)waitingTimeSum / (float)NP;
  cout << "averageWaitingTime\t" << averageWaitingTime << endl;
}

void responsetime()
{
  int release, t;
  for (int i = 0; i < NP; i++)
  {
    t = 0;
    release = -1;
    while (release == -1)
    {
      if (scheduler[t] == i)
      {
        release = t + 1;
      }
      t++;
    }
    response[i] = release-1;
  }
}
void final()
{
  cout << "Pid\tAT\tBT\tCT\tTAT\tWT\tRT" << endl;
  for (int i = 0; i < NP; i++)
  {
    cout << "P" << i << "\t" << processes[i][0] << "\t" << processes[i][1] << "\t" << completion[i] << "\t" << TAT[i] << "\t" << processes[i][3] << "\t" << response[i] << endl;
  }
}

int main()
{
  getSystem();
  schedule();
  printScheduler();
  waitingTime();
  responsetime();
  final();
  AvgWaitingTime();
}
