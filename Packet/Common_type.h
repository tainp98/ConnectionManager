#ifndef COMMON_TYPE_H
#define COMMON_TYPE_H

#include <chrono>
#include <iostream>
#include <map>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;
/*
---------------------------------------------------
----------Key (K) --- Length (L)---- Value (V) type
---------------------------------------------------
*/

namespace Eye
{

    typedef short key_type; // 2 bytes
    typedef short length_type; // 2 bytes
    typedef unsigned char byte; // 1 byte
    /*
    ---------------------------------------------------
    ----------Data for calculate ---------------------
    ---------------------------------------------------
    */

    typedef double data_type; // 8 bytes
    typedef int pixel_type; // 4 bytes
    typedef int index_type; // 4 bytes
    typedef unsigned char label_type; // 1 byte

    typedef short int V_INT_16;  // 2 bytes           //!< Signed 16-bits integral type
    typedef unsigned short int V_UINT_16;   //!< Unsigned 16-bits integral type
    typedef long int V_INT_32;              //!< Signed 32-bits integral type
    typedef unsigned long int V_UINT_32;    //!< Unsigned 32-bits integral type
    typedef float V_REAL_32;                //!< 32-bits floating point type
    typedef double V_REAL_64;               //!< 64-bits floating point type

}

#endif
