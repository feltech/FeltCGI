/*
 * File:   ConnectionTest.cpp
 * Author: dave
 *
 * Created on 09-Feb-2014, 12:57:10
 */
#include <boost/asio.hpp>

#include "ConnectionTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ConnectionTest);

ConnectionTest::ConnectionTest()
{
}

ConnectionTest::~ConnectionTest()
{
}

void ConnectionTest::setUp()
{
//	system("/usr/bin/spawn-fcgi -a 127.0.0.1 -p 7000 -- /home/dave/Documents/development/qt/Felt/FeltCGI/dist/Debug/GNU-Linux-x86/feltcgi &");
}

void ConnectionTest::tearDown()
{
	
}

void ConnectionTest::testConnection()
{
	boost::asio::io_service io_service;
 	boost::system::error_code error;

	using boost::asio::ip::tcp;
	tcp::resolver resolver(io_service);
    tcp::resolver::query query("127.0.0.1", "7001");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    tcp::socket socket(io_service);
	struct timeval tv;
	tv.tv_sec  = 2; 
	tv.tv_usec = 0;         
	setsockopt(socket.native(), SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
	setsockopt(socket.native(), SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));	

	try {
		boost::asio::connect(socket, endpoint_iterator);
	
		while (true)
		{
			boost::array<char, 128> buf;

			size_t len = socket.read_some(boost::asio::buffer(buf), error);
			if (error == boost::asio::error::eof)
			  break; // Connection closed cleanly by peer.
			else if (error)
			  throw boost::system::system_error(error); // Some other error.

		  std::cout.write(buf.data(), len);
		}	

	}
	catch (std::exception& e)
	{
	  std::cerr << e.what() << std::endl;
	}
	
	
	CPPUNIT_ASSERT_EQUAL(error, (boost::system::error_code)boost::asio::error::eof);
}

