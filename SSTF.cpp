#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> q;
  vector<int> tem;

  int n, num, head;
  int seek=0;
  cout << "Enter the size of Queue\t";
  cin >> n;
  cout << "Enter the Initial head position\t";
  cin >> head;

  for (int i = 0; i < n; i++)
  {
    cin >> num;
    q.push_back(num);
  }
  int count = n;
  int Min = 0;
  while (count)
  {
    tem.clear();
    Min = 0;
    for (auto it = q.begin(); it != q.end(); it++)
    {
      tem.push_back(abs(head - *it));
    }
    for (int i = 1; i < q.size(); i++)
    {
      if (tem[i] < tem[Min])
        Min = i;
    }
    seek = seek + abs(head - q[Min]);
    head = q[Min];
    q.erase(find(q.begin(), q.end(),q[Min]));
    count--;
  }
  cout << "Seek time:" << seek;
}