
#include "SmartPtr/gzSp.h"
#include "SmartPtr/gzWp.h"

#ifndef GZE_IMPORT
	#define GZE_IMPORT  __declspec(dllimport)
#endif



//// Minimal required libs ////
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///////////////////////////////

#include "Lib_GZ/Base/Containers.h" 
#include "GzOverplace.h"

#include "Macro.h"
#include "Lib_GZ/Lib_GZ.h"

    #include "Class.h"
    #include "StThread.h"




/*
//#ifndef tGZ_Use_Pch
    #include "Lib_GZ/Lib_GZ.h"
	#include "Lib_GZ/Lib.h"

	#include "Lib_GZ/DataArray.h"


    #include "GzBase.h"

    #include "Lib_GZ/DArray.h"
    #include "Lib_GZ/DArray2.h"
    #include "Lib_GZ/QArray.h"
    #include "Lib_GZ/Gate.h"

    #include "Lib_GZ/ThreadExt.h"


//#endif
*/