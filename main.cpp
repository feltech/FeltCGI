/* 
 * File:   main.cpp
 * Author: dave
 *
 * Created on 09 February 2014, 12:55
 */

#include <fcgiapp.h>
//#include <fcgi_stdio.h>
//#include <fastcgi++/manager.hpp>
//#include "include/Listener.h"
#include <exception>
#include <iostream>
int main()
{
	try
	{
		int fd = FCGX_OpenSocket(":7000", 500);
		FCGX_Init();
		FCGX_Request request;
		FCGX_InitRequest(&request, fd, 0);
//		FCGX_Stream* in;
//		FCGX_Stream* out;
//		FCGX_Stream* err;
//		FCGX_ParamArray params;
		
//		int resp = FCGX_Accept(&in, &out, &err, &params);
		while (FCGX_Accept_r(&request) >= 0)
		{
			FCGX_PutS("Content-type: text/html\r\n"
				"\r\n"
				"<title>It worked</title>"
				"<h1>Finally!</h1>\n", request.out);
		}
//		Fastcgipp::Manager<Listener> fcgi(fd);
//		fcgi.handler();
	}
	catch(std::exception& e)
	{
		std::cerr  << e.what() << std::endl;
		return -1;
	}
	return 0;
}
