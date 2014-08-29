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
#define DEBUG_LOG_UI true
#define DEBUG_LOG_COLLISION false
#define DEBUG_LOG_TRASHGEN true
#define DEBUG_LOG_RESOLUTION true



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

#if ( DEBUG_LOG && DEBUG_LOG_TRASHGEN )
#define LOG_TRASHGEN(...) Log_msg("[TGN]",__VA_ARGS__)
#else
#define LOG_TRASHGEN(...)
#endif

#if ( DEBUG_LOG && DEBUG_LOG_RESOLUTION )
#define LOG_RESOLUTION(...) Log_msg("[RES]",__VA_ARGS__)
#else
#define LOG_RESOLUTION(...)
#endif



#endif /* defined(__rcycle__Log__) */
