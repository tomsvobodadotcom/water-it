/**
 * @brief: Water-it: Software for automated flower watering
 * @file: debug.h
 * @author: Tom Svoboda
 * @date: 12. 5. 2018
 */

#ifndef DEBUG_H
#define DEBUG_H

/* Enable debug */
#define DEBUG_ENABLED

/* Debug macro */
#ifdef DEBUG_ENABLED
    #include <iostream>
    #define DEBUG(module, msg) std::cerr << "[" << module << "] " << msg << std::endl
#else
    #define DEBUG(module, msg)
#endif

#endif
