//
// Copyright (c) 2008-2010, Vincent Gable.
// http://vincentgable.com
//
// Modified by MonsieurDart aka Mathieu Godart - L'atelier du mobile to extract only the LOG_EXPR code.
//
// Based off http://www.dribin.org/dave/blog/archives/2008/09/22/convert_to_nsstring/
//

#import <Foundation/Foundation.h>


#define LOG_EXPR(EXPR)      LOG_EXPR_WITH(NSLog, EXPR)


#define LOG_EXPR_WITH(LOGGER, EXPR)                                     \
do {                                                                    \
    __typeof__(EXPR) TYPE = (EXPR);                                     \
    const char *TYPE_CODE = @encode(__typeof__(EXPR));                  \
    NSString *MSG = VTPG_DDToStringFromTypeAndValue(TYPE_CODE, &TYPE);  \
    if (MSG)                                                            \
        LOGGER(@"%s = %@", #EXPR, MSG);                                 \
    else                                                                \
        LOGGER(@"Unknown TYPE_CODE: %s for expression %s",              \
                TYPE_CODE, #EXPR);                                      \
} while(0)


extern NSString *VTPG_DDToStringFromTypeAndValue(const char *typeCode, void *value);
