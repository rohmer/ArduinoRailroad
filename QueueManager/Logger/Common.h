/*
 * Common.h
 *
 * Created: 1/28/2015 12:14:50 PM
 *  Author: rohmer
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#include "WString.h"

enum Severity { ERROR, WARNING, INFO };

typedef void (*logAppender)(Severity,String);

#endif /* COMMON_H_ */