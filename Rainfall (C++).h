//Rainfall (C++)

#include <string>
#include <vector>
#include <regex>

class Rainfall
{
private:
  static std::vector<double> f_sum_v3(std::string, const std::string&);
public:
    static double mean(std::string town, const std::string &strng);
    static double variance(std::string town, const std::string &strng);
};

double Rainfall::mean(std::string town, const std::string& str)
{
  std::vector<double> v = f_sum_v3(town, str);

  if (v[0] == -1)
    return -1;

  return v[1] / 12;
};

double Rainfall::variance(std::string town, const std::string& str)
{
  std::vector<double> v = f_sum_v3(town, str);
  double D12 = 0;

  if (v[0] == -1)
    return -1;

  for (int i = 2; i < v.size(); ++i)
    D12 += (v[i] - v[1] / 12)*(v[i] - v[1] / 12);

  return D12 / 12;
};

std::vector<double> Rainfall::f_sum_v3(std::string town, const std::string& str)
{
  std::cmatch mres;
  std::regex trx(town + ":");
  std::regex nrx("[0-9]{1,4}.[0-9]");
  std::vector<double> v(2, 0);

  if (std::regex_search(&str[0], mres, trx) == 1)
    while ((*mres[0].second != 10) && (*mres[0].second != 0))
    {
      std::regex_search(mres[0].second, mres, nrx);
      v.push_back(std::stod(mres[0]));
      v[1] += v.back();
    }
  else
    v[0] = -1;

  return v;
};