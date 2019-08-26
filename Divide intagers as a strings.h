//Divide integers as strings (C++)

#include <vector>
#include <string>

using namespace std;

vector<string> divide_strings(string, string);

vector<string> divide_simple_strings(string, string);

string subStr(string, string);

vector<string> divide_strings(string a, string b)
{
  if (a.length() < b.length())
    return { "0", a };

  string ca = '0' + a, buf, qu;
  vector<string> vsbuf;
  int fclen = b.length() + 1;
  int sh = 1;

  for (int i = 1; i - sh + fclen <= ca.length(); i++)
  {
    buf = ca.substr(i - sh, fclen);
    vsbuf = divide_simple_strings(buf, b);
    qu = qu + vsbuf[0];
    ca.replace(i - sh, fclen, vsbuf[1]);  
  }

  int k;

  for (k = 0; k < vsbuf[1].length();)
    if (vsbuf[1][k] == '0' && k != vsbuf[1].length() - 1)
      k++;
    else
      break;

  vsbuf[1].erase(0, k);

  for (k = 0; k < qu.length();)
    if (qu[k] == '0' && k != qu.length() - 1)
      k++;
    else
      break;

  qu.erase(0, k);

  return { qu, vsbuf[1]};
}

vector<string> divide_simple_strings(string a, string b)
{
  string cb(a.length() - b.length(), '0');

  cb += b;

  string curr, prev = a;
  int i = 0;

  while (true)
  {
    curr = subStr(prev, cb);
    if (curr == "-")
      break;
    prev = curr;
    i++;
  }

  return { to_string(i), prev };
}

string subStr(string a, string b)
{
  string c(a.length(), '0');
  int defF = 0;

  for (int i = a.length() - 1; i >= 0; i--)
  {
    c[i] = a[i] - b[i] - defF + 48;

    if (c[i] < '0')
    {
      c[i] += 10;
      defF = 1;
    }
    else
      defF = 0;

  }
  
  if (defF == 1)
    return "-";

  return c;
}

