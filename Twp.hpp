#ifndef Twp_hpp
#define Twp_hpp

#include <string>
#include <fstream>
#include <map>
#include <unordered_map>

#include "Page.hpp"

class Page;

class Twp
{
public:
  Twp(Page * Dest, const std::string & Name);
  const std::string & Content();
  void Var(const std::string & Key, const std::string & Value);
  const std::string & Var(const std::string & Key);
  void Release();
  void Parsing();
  void Repeat();
  const std::string & Result();
  Page * Parent();
private:
  Page * mParent;
  std::unordered_map<std::string, std::string> mVars;
  std::ifstream mInput;
  std::string mContent;
  std::string mResult;
};

#endif
