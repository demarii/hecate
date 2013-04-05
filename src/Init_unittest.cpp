/**
 Hecate Distributed Server

 Copyright (C) 2013 Sean Ryan <sryan@evercrack.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 */

/*
 * Local Includes
 */

/*
 * System Includes
 */
#include <cppunit/TestCase.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <cassert>

class Init_unittest : public CppUnit::TestCase
{
    CPPUNIT_TEST_SUITE(Init_unittest);
    CPPUNIT_TEST(stubTest);
    CPPUNIT_TEST_SUITE_END();
  public:
    Init_unittest() { }

    void stubTest() {
       CPPUNIT_PASS("Stub Test")
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(MetaServer_unittest);


int main()
{
    CppUnit::TextTestRunner runner;
    CppUnit::Test* tp =
            CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    runner.addTest(tp);

    if (runner.run()) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * Method Stubs
 */
void
MetaServerPacket::setAddress(const boost::asio::ip::address& a)
{

}

void
MetaServerPacket::setPacketType(const NetMsgType& nmt)
{
}

unsigned int
MetaServerPacket::addPacketData(boost::uint32_t d)
{
	return 1;
}

unsigned int
MetaServerPacket::addPacketData(const std::string& s)
{
	return 1;
}

const std::string
MetaServerPacket::getPacketMessage(unsigned int offset) const
{
	return "";
}

MetaServerPacket::~MetaServerPacket()
{
}

std::ostream& operator<<(std::ostream &os, const MetaServerPacket &mp)
{
	return os << mp.getSequence();
}

char*
MetaServerPacket::unpack_uint32(uint32_t *dest, char *buffer) const
{
    uint32_t netorder;

    memcpy(&netorder, buffer, sizeof(uint32_t));
    *dest = ntohl(netorder);
    return buffer+sizeof(uint32_t);

}
