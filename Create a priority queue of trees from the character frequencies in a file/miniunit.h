#ifndef __MINIUNIT_H__
#define __MINIUNIT_H__

#include <stdbool.h>
#include "clog.h"

#define mu_start() int __mu_line_num_first_fail = 0

#define mu_check(condition) if(!(condition) && __mu_line_num_first_fail \
		== 0) \
	(__mu_line_num_first_fail = __LINE__);

#define mu_run(function) if( function() )\
(fprintf(stderr,ANSI_RED "Test failed: %s at line %d\n" ANSI_RESET \
		 , #function, function())); \
else \
(fprintf(stderr,ANSI_GREEN "Test Passed: %s\n" ANSI_RESET,#function)); 

#define mu_end() return(__mu_line_num_first_fail)

#endif
