#ifndef Checksum64Test_INCLUDED
#define Checksum64Test_INCLUDED

#include "CppUnit/TestCase.h"

class Checksum64Test: public CppUnit::TestCase
{
public:
        Checksum64Test(const std::string& name);
        ~Checksum64Test();

        void testChecksum64();

        void setUp();
        void tearDown();

        static CppUnit::Test* suite();

private:
};

#endif