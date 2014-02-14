//
//  Log.h
//  rcycle
//
//  Created by Mikel on 08/02/14.
//
//

#ifndef __rcycle__Log__
#define __rcycle__Log__

#include "Common.h"

#include <cstdarg>

void Log_msg(const char *type,const char *msg, ... );

// master switch
#define DEBUG_LOG true
// log types switches
#define DEBUG_LOG_GENERAL true
#define DEBUG_LOG_CCB true
#define DEBUG_LOG_UI false
#define DEBUG_LOG_COLLISION false


#if ( DEBUG_LOG && DEBUG_LOG_GENERAL )
#define LOG(...) Log_msg("[G]",__VA_ARGS__)
#else
#define LOG(...)
#endif

#if ( DEBUG_LOG && DEBUG_LOG_CCB )
#define LOG_CCB(...) Log_msg("[CCB]",__VA_ARGS__)
#else
#define LOG_CCB(...)
#endif

#if ( DEBUG_LOG && DEBUG_LOG_UI )
#define LOG_UI(...) Log_msg("[UI]",__VA_ARGS__)
#else
#define LOG_UI(...)
#endif

#if ( DEBUG_LOG && DEBUG_LOG_COLLISION )
#define LOG_COLLISION(...) Log_msg("[COL]",__VA_ARGS__)
#else
#define LOG_COLLISION(...)
#endif



#endif /* defined(__rcycle__Log__) */
