INCLUDES = -I$(top_srcdir)/src  -I$(top_builddir)/src -DPREFIX=\"@prefix@\"

bin_PROGRAMS = broker

include_HEADERS = Version.hpp

noinst_HEADERS = Broker.hpp 

broker_SOURCES = Broker_Main.cpp 
broker_LDFLAGS = 
                                         
TESTS = \
    Init_unittest 

check_PROGRAMS = $(TESTS)

Init_unittest_SOURCES = Init_unittest.cpp
Init_unittest_LDADD = $(CPPUNIT_LIBS)

