#include "Twp.hpp"
#include <iostream>

static const std::string MessageError = "Not found!";

Twp::Twp(Page * Dest, const std::string & Name)
{
  mInput.open(Name.c_str());
  mParent = Dest;

  mContent.reserve(1024 * 50);
  mResult.reserve(1024 * 50);

  if (mInput.is_open())
  {
    while (getline(mInput, mResult))
    {
      mContent.append(mResult);
      mContent.append("\n");
    }
  
    mInput.close();
  }
/*  else
  {
    mContent.append("Not found file:" + Name + "\n");
  }*/

}

const std::string & Twp::Content()
{
  return mContent;
}

Page * Twp::Parent()
{
  return mParent;
}

void Twp::Var(const std::string & Key, const std::string & Value)
{
  std::unordered_map<std::string, std::string>::iterator i = mVars.find(Key);

  if (i == mVars.end())
  {
    mVars.insert(std::make_pair(Key, Value));
  }
  else
  {
    i->second = Value;
  }   
}

const std::string & Twp::Var(const std::string & Key)
{
  std::unordered_map<std::string, std::string>::iterator i = mVars.find(Key);

  if (i == mVars.end())
  {
    return MessageError;
  }
  else
  {
    return i->second;
  }   
}

void Twp::Parsing()
{
  std::string Ident;

  for (size_t i = 0; i < mContent.size(); i++)
  {
    if (mContent[i] == '$')
    {
      i++;

      Ident.clear();

      while (isalpha(mContent[i]) || isdigit(mContent[i]) || mContent[i] == '.')
      {
        Ident.push_back(mContent[i]);
        i++;
      }

      mResult.append(Var(Ident));
    }
    else if (mContent[i] == '%')
    {
      i++;

      Ident.clear();

      while (isalpha(mContent[i]) || isdigit(mContent[i]) || mContent[i] == '.')
      {
        Ident.push_back(mContent[i]);
        i++;
      }

      mResult.append(Parent()->GetPage(Ident)->Result());
    }

    mResult.push_back(mContent[i]);

  }
}

void Twp::Repeat()
{
  Parsing();
}

void Twp::Release()
{
  mResult.clear();
  Parsing();
}

const std::string & Twp::Result()
{
  return mResult;
}
