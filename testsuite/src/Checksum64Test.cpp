#include "Checksum64.h"
#include "Checksum64Test.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include <string>
#include <string.h>

Checksum64Test::Checksum64Test(const std::string& name): CppUnit::TestCase(name)
{
}

Checksum64Test::~Checksum64Test()
{
}

void Checksum64Test::testChecksum64()
{
  Poco::Checksum64 checksum64_0;
  Poco::Checksum64 checksum64_1;
  Poco::UInt64 crc64_0 = 0;
  Poco::UInt64 crc64_1 = 0;
  Poco::UInt64 crc64_2 = 0;
  Poco::UInt64 crc64_3 = 0;
  Poco::UInt64 crc64_4 = 0;
  Poco::UInt64 crc64_5 = 0;
  Poco::UInt64 crc64_6 = 0;
  Poco::UInt64 crc64_7 = 0;
  std::string str     = "Hello world!!!";
  const char c_str[]  = "Hello People!!!";
  const char c_str1[] = "Hello world!!!";
  const char c_str2[] = "b";
  const char c_str3[] = "c";
  char ch = 'c';
//------------------------------------------- Start tests  ------------------------
  checksum64_0.update(str);
  crc64_0 = checksum64_0.checksum();               // crc64 of "Hello world!!!"
  checksum64_0.update(c_str, strlen(c_str));
  crc64_1 = checksum64_0.checksum();               // crc64 of "Hello People!!!"
  assert(crc64_0 != crc64_1);
  
  checksum64_0.update(ch);
  crc64_2 = checksum64_0.checksum();               // crc64 of 'c'
  assert(crc64_0 != crc64_2);
  
  assert(crc64_1 != crc64_2);
  
  checksum64_0.update(c_str1);
  crc64_3 = checksum64_0.checksum();               // crc64 of "Hello world!!!"
  assert(crc64_0 == crc64_3);
  
  str = "c";
  checksum64_0.update(str);
  crc64_4 = checksum64_0.checksum();              // crc64 of "c", fetching from checksum64_0 object
  checksum64_1.update(ch);
  crc64_5 = checksum64_1.checksum();              // crc64 of 'c', fetching from checksum64_1 object
  assert(crc64_4 == crc64_5);
  
  checksum64_0.update(c_str2, strlen(c_str2));
  crc64_6 = checksum64_0.checksum();              // crc64 of "b", fetching from checksum64_0 object  
  assert(crc64_5 != crc64_6);
  
  checksum64_0.update(c_str3, strlen(c_str3));
  crc64_7 = checksum64_0.checksum();              // crc64 of "c", fetching from checksum64_0 object  
  assert(crc64_5 == crc64_7); 
}

void Checksum64Test::setUp()
{
}


void Checksum64Test::tearDown()
{
}


CppUnit::Test* Checksum64Test::suite()
{
  CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("Checksum64Test");
  CppUnit_addTest(pSuite, Checksum64Test, testChecksum64);
  return pSuite;  
}