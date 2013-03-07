#include "Checksum64Test.h"
#include "CppUnit/TestRunner.h"
#include <string>
#include <vector>

#include "Checksum64.h"
#include <stdio.h>


int main(int argc, char** argv)
{  
  Poco::Checksum64 crc;
  std::string localStr = "1234567890";
  crc.update(localStr);
  printf("1234567890 STR = %llx\n", crc.checksum());

  std::vector<std::string> args;
  for(unsigned int i = 0; i < static_cast<unsigned int>(argc); i++)
  {
    args.push_back(std::string(argv[i]));
  }
  CppUnit::TestRunner runner;
  runner.addTest("Checksum64Test_suite", Checksum64Test::suite());
  return runner.run(args);
  
}