#include <stdio.h>

int main()
{

  int processes, resources;
  printf("Enter the Number of process:\n");
  scanf("%d", &processes);
  printf("Enter the Number of Resources:\n");
  scanf("%d", &resources);

  int Allo[processes][resources];
  int Avail[resources], Maxneed[processes][resources], Total[resources], Remain[processes][resources];

  int finallist[processes];

  printf("Enter the Allocation Matrix:\n");
  for (int i = 0; i < processes; i++)
  {
    for (int j = 0; j < resources; j++)
    {
      scanf("%d", &Allo[i][j]);
    }
  }
  printf("Enter the Maxneed Matrix:\n");
  for (int i = 0; i < processes; i++)
  { 
    for (int j = 0; j < resources; j++)
    {
      scanf("%d", &Maxneed[i][j]);
    }
  }

  printf("Enter Total Resoureces:\n");
  for (int i = 0; i < resources; i++)
  {
    scanf("%d", &Total[i]);
  }

  int sum = 0;
  for (int j = 0; j < resources; j++)
  {
    sum = 0;
    for (int i = 0; i < processes; i++)
    {
      sum += Allo[i][j];
    }
    Total[j] = Total[j] - sum;
    Avail[j] = Total[j];
  }

  for (int i = 0; i < processes; i++)
  {
    for (int j = 0; j < resources; j++)
    {
      Remain[i][j] = Maxneed[i][j] - Allo[i][j];
    }
  }

  int count = 0;
  int f = 0;
  int co = processes;
  while (co != 0)
    for (int i = 0; i < processes; i++)
    {
      count = 0;
      for (int j = 0; j < resources; j++)
      {
        if (Remain[i][j] <= Avail[j])
        {
          count++;
        }
      }
      if (count == resources)
      {
        finallist[f] = i + 1;
        f++;
        co--;
        for (int j = 0; j < resources; j++)
        {
          Avail[j] += Allo[i][j];
          Remain[i][j] = 9999;
        }
      }
    }

  for (int i = 0; i < processes; i++)
  {
    printf("P%d->\t", finallist[i]);
  }
}
