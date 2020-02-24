#ifndef Page_hpp
#define Page_hpp

#include <string>
#include <map>
#include <unordered_map>

#include "Twp.hpp"

class Twp;

class Page
{
public:
  Page(const std::string & Path);
  Twp * GetPage(const std::string & Name);
  ~Page();
private:
  std::unordered_map<std::string, Twp*> mTemplates;
  std::string mResult;
  std::string mPath;
  std::string mFullPath;
};

#endif
