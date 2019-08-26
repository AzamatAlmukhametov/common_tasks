//Longest Common Subsequence (Performance version)

#include <vector>
#include <string>

using namespace std;

string  lcs(const string& x, const string& y)
{
  vector<vector<int> > v;

  for (int k = 0; k < y.length() + 1; k++)
    v.push_back(vector<int> (x.length() + 1));

  for (int i = y.length(); i >= 0; i--)
    for (int j = x.length(); j >= 0; j--)
      if (x[j] == '\0' || y[i] == '\0') v[i][j] = 0;
      else
        if (x[j] == y[i]) v[i][j] = 1 + v[i + 1][j + 1];
        else
          v[i][j] = max(v[i + 1][j], v[i][j + 1]);

  int lenghtOfCS = v[0][0], i = 0, j = 0;
  string s;

  while (lenghtOfCS != 0)
    if (v[i][j + 1] == lenghtOfCS)
      j++;
    else
      if (v[i + 1][j] == lenghtOfCS)
        i++;
      else
      {
        s += x[j];
        i++; j++; lenghtOfCS--;
      }
  
  return s;
 }
  