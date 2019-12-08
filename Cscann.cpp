#include <bits/stdc++.h>
using namespace std;

int main()
{
  int max, head, n, num;
  int seek = 0;
  int Min=0;
  vector<int> q;
  cout << "Enter the max range of disk";
  cin >> max;
  cout << "Enter the initial head position";
  cin >> head;
  cout << "Enter the size of queue request";
  cin >> n;
  cout << "Enter the queue\n";
  seek = seek + abs(head - max);
  seek = seek + (max - 0);
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    q.push_back(num);
  }
  sort(q.begin(), q.end()); 
  for (int i = 0; i < q.size(); i++)
  {
    if (q[i] < head)
      Min = i;
  }
  seek = seek + abs(0-q[Min]);
  cout << seek;
}