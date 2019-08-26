//Path Finder #2: shortest path (C++)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct coord
{
  int x, y;
};

int path_finder(string maze)
{
  int cols = 0; for (; maze[cols] != '\0' && maze[cols] != '\n'; cols++);
  int rows = (maze.length() + 1) / (cols + 1);

  if (rows == 1 && cols == 1) return 0;

  vector< vector<long> > v(rows, vector<long>(cols));

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (maze[i*(cols + 1) + j] == '.') v[i][j] = 0;
      else v[i][j] = -1;
  v[0][0] = 1;

  coord stepP, baseP;
  vector<coord> lastAdded = { {0, 0} };
  vector<coord> movCoordV = { { 0, 1 }, { 0,-1 }, { 1, 0 }, { -1, 0 } };

  while (!lastAdded.empty())
  {
    baseP.y = lastAdded.front().y; baseP.x = lastAdded.front().x;
    lastAdded.erase(lastAdded.begin());

    if (v[baseP.y][baseP.x] > 0)
      for (auto it : movCoordV)
      {
        stepP = { baseP.x + it.x, baseP.y + it.y };

        if (stepP.y == rows - 1 && stepP.x == cols - 1) return v[baseP.y][baseP.x]; 
        if (stepP.x >= 0 && stepP.y >= 0 && stepP.x < cols  && stepP.y < rows)
          if (v[stepP.y][stepP.x] == 0)
          {
            v[stepP.y][stepP.x] = v[baseP.y][baseP.x] + 1;
            lastAdded.push_back({ stepP.x, stepP.y });
          }
      }
  }

  return -1;
}