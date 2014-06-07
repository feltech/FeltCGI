/* 
 * File:   Listener.cpp
 * Author: dave
 * 
 * Created on 09 February 2014, 18:37
 */

#include "../include/Listener.h"

Listener::Listener()
{
}

Listener::Listener(const Listener& orig)
{
}

Listener::~Listener()
{
}

bool Listener::response() 
{
	out << "Content-Type: text/html; charset=utf-8\r\n\r\nTEST";
	return true;
}

