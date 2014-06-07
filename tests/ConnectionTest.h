/*
 * File:   ConnectionTest.h
 * Author: dave
 *
 * Created on 09-Feb-2014, 12:57:10
 */

#ifndef CONNECTIONTEST_H
#define	CONNECTIONTEST_H

#include <cppunit/extensions/HelperMacros.h>

class ConnectionTest : public CPPUNIT_NS::TestFixture {
	CPPUNIT_TEST_SUITE(ConnectionTest);

	CPPUNIT_TEST(testConnection);

	CPPUNIT_TEST_SUITE_END();

public:
	ConnectionTest();
	virtual ~ConnectionTest();
	void setUp();
	void tearDown();

private:
	void testConnection();
};

#endif	/* CONNECTIONTEST_H */

