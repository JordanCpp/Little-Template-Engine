#include "Page.hpp"

Page::Page(const std::string & Path)
{
  mPath = Path;
}

Twp * Page::GetPage(const std::string & Name)
{
  std::unordered_map<std::string, Twp*>::iterator i = mTemplates.find(Name);

  Twp * p = NULL;

  if (i == mTemplates.end())
  {
    mFullPath.clear();
    mFullPath.append(mPath);
    mFullPath.append("\\");
    mFullPath.append(Name);

    p = new Twp(this, mFullPath);

    mTemplates.insert(std::make_pair(Name, p));
  }
  else
  {
    p = i->second;
  }   

  return p; 
}

Page::~Page()
{
  for (std::unordered_map<std::string, Twp*>::iterator i = mTemplates.begin(); i != mTemplates.end(); i++)
  {
    delete i->second;
  }
}
