/*
Description

You have been given a grid of size N x N.
Each cell is either empty (.) or occupied (#).
Size of each cell is 1 x 1. In the connected component, 
you can reach any cell from every other cell in the
component by repeatedly stepping to adjacent cells in
the north, south, east, and west directions. 
Your task is to find the area and perimeter of 
the connected component having the largest area.
The area of a connected component is just the number
of '#' characters that are part of it. If multiple 
connected components tie for the largest area, find the 
smallest perimeter among them.


Each cell is labelled with a "component ID". Now 
we need to find the area and perimeter of each connected component.

Now you can find the area by counting the number of 
# in a connected component. For perimeter count the number
sides of the cell that have empty adjacent cells.



*/
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int N, R;
char grid[1002][1002]; // pad with .'s
int region[1002][1002], area[1000000], perimeter[1000000];

typedef pair<int,int> pii;
void visit(int i, int j, int r)
{
  stack<pii> to_visit;
  to_visit.push(make_pair(i,j));
  while (!to_visit.empty()) {
    pii current = to_visit.top();
    to_visit.pop();
    i = current.first; j = current.second;
    if (region[i][j] != 0 || grid[i][j]=='.') continue;
    region[i][j] = R;
    area[R]++;
    to_visit.push(make_pair(i-1,j));
    to_visit.push(make_pair(i+1,j));
    to_visit.push(make_pair(i,j-1));
    to_visit.push(make_pair(i,j+1));
  }
}

void find_perimeters(void)
{
  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++) {
      int r = region[i][j];
      if (r == 0) continue;
      if (region[i-1][j]==0) perimeter[r]++;
      if (region[i+1][j]==0) perimeter[r]++;
      if (region[i][j-1]==0) perimeter[r]++;
      if (region[i][j+1]==0) perimeter[r]++;
    }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> N;
  string s;
  for (int i=0; i<N+2; i++) grid[0][i] = grid[N+1][i] = '.';
  for (int i=1; i<=N; i++) {
    grid[i][0] = grid[i][N+1] = '.';
    cin >> s;
    for (int j=1; j<=N; j++) grid[i][j] = s[j-1];
  }

  for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
      if (grid[i][j] == '#' && region[i][j] == 0) visit(i,j,++R);

  find_perimeters();

  int best_a=0, best_p=0;
  for (int i=1; i<=R; i++)
    if (area[i] > best_a || (area[i] == best_a && perimeter[i] < best_p)) {
      best_a = area[i];
      best_p = perimeter[i];
    }

  cout << best_a << " " << best_p << "\n";
  return 0;
}
