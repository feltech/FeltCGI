/* 
 * File:   Listener.h
 * Author: dave
 *
 * Created on 09 February 2014, 18:37
 */

#ifndef LISTENER_H
#define	LISTENER_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <fastcgi++/request.hpp>


class Listener : public Fastcgipp::Request<wchar_t> {
public:
	Listener();
	Listener(const Listener& orig);
	virtual ~Listener();
private:
	bool response();
};

#endif	/* LISTENER_H */

