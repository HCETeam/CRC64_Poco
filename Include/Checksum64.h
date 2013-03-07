/*
 * This algorithm and table are based on the polynomial
 *
 * x^64 + x^62 + x^57 + x^55 + x^54 + x^53 + x^52 + x^47 + x^46 + x^45 +
 * x^40 + x^39 + x^38 + x^37 + x^35 + x^33 + x^32 + x^31 + x^29 + x^27 +
 * x^24 + x^23 + x^22 + x^21 + x^19 + x^17 + x^13 + x^12 + x^10 + x^9 +
 * x^7 + x^4 + x + 1
 *
 * which is borrowed from the DLT1 spec
 * (ECMA-182, available from http://www.ecma.ch/ecma1/STAND/ECMA-182.HTM)
 *
 * Portions Copyright (c) 1996-2009, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 */

#ifndef Foundation_Checksum64_INCLUDED
#define Foundation_Checksum64_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Mutex.h"

namespace Poco {

const unsigned int crc64_table_size = 256;

class Foundation_API Checksum64
        /// This class calculates CRC-64 checksums
        /// for arbitrary data.
        ///
        
{
public:

         Checksum64();
                /// Creates a CRC-64 checksum initialized to 0.

        ~Checksum64();
                /// Destroys the Checksum.

        void update(const char* data, unsigned int length);
                /// Updates the checksum with the given data.

        void update(const std::string& data);
                /// Updates the checksum with the given data.

        void update(char data);
                /// Updates the checksum with the given data.

        Poco::UInt64 checksum() const;
                /// Returns the calculated checksum.

private:
        static Poco::UInt64 initCRC64Val;
        static Poco::UInt64 finXORVal;
        Poco::UInt64 _value;
        static Poco::UInt64 crc_table[crc64_table_size];
private:
        void calcCrcTable();
};

inline void Checksum64::update(const std::string& data)
{
  update(data.c_str(), static_cast<unsigned int>(data.length()));
}

inline void Checksum64::update(char c)
{
  update(&c, 1);
}

inline Poco::UInt64 Checksum64::checksum() const
{
  return _value;
}


} // namespace Poco


#endif // Foundation_Checksum_INCLUDED
