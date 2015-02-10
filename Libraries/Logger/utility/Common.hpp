/*
 * Common.h
 *
 * Created: 1/28/2015 12:14:50 PM
 *  Author: rohmer
 */ 


#ifndef COMMON_HPP_
#define COMMON_HPP_

#include "WString.h"

enum Severity { ERROR, WARNING, INFO };

typedef void (*logAppender)(Severity,String);

#endif /* COMMON_HPP_ */