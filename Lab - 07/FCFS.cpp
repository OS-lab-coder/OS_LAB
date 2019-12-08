#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*b = *a;
	*a = temp;
}
	
float calculate_average(int t[], int n)
{
	int sum=0;
	for(int i=0; i<n; i++)
		sum += t[i];
	float avg = sum/n;
	return avg;
}

void sort_array(int a[], int b[], int Pid[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				swap(b[j], b[j+1]);
				swap(Pid[j], Pid[j+1]);
			}
		}
	}	
}


int main()
{	
	int n, i;
	double th;
	cout<<"Enter the number of process: ";
	cin>>n;
	cout<<endl;
	int at[n], bt[n], tat[n], ct[n], wt[n], rt[n], Pid[n];
	for(i=0; i<n; i++)
	{
		cout<<"Process id is "<<i<<endl;
		Pid[i]=i;
		cout<<"Enter the arrival time for process "<<i<<" : ";
		cin>>at[i];
		cout<<endl;
		cout<<"Enter the burst time for process "<<i<<" : ";
		cin>>bt[i];
		cout<<endl;
	}
	sort_array(at,bt,Pid,n);
	for(i=0; i<n; i++)
	{
		if(i==0)
			ct[i]=bt[i] + at[i];
		else if(at[i] > ct[i-1])
			ct[i]=bt[i] + at[i];
		else
			ct[i]=ct[i-1] + bt[i];
	}
	for(i=0; i<n; i++)
	{
		tat[i] = ct[i] - at[i];
	}
	for(i=0; i<n; i++)
	{
		wt[i] = tat[i] - bt[i];
		rt[i] = tat[i] - bt[i];
	}
	/*
	for(int i=0; i<n; i++)
	{
		cout<<endl<<"Procees id is "<<Pid[i]<<endl
			<<"Arrival Time is "<<at[i]<<endl
			<<"Burst time is "<<bt[i]<<endl
			<<"Completion time is "<<ct[i]<<endl
			<<"Turn around time is "<<tat[i]<<endl
			<<"Waiting time is "<<wt[i]<<endl
			<<"Response time is "<<rt[i]<<endl
			<<"----------------------------------------"<<endl;
	}
	*/
	cout<<endl<<"Pid\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<Pid[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<rt[i]<<endl;
	}	
	cout<<endl<<"Average Turn Around Time = "<<calculate_average(tat,n);
	cout<<endl<<"Waiting Time = "<<calculate_average(wt,n)<<endl;
	th = (float)n/(float)ct[n-1];
	cout<<"Throughput = "<<th<<endl;
}

