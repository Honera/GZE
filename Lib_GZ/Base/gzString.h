//This file is part of "GZE - GroundZero Engine"

//The permisive licence allow to use GZE for free or commercial project (Apache License, Version 2.0).
//For conditions of distribution and use, see copyright notice in Licence.txt, this license must be included with any distribution of the code.

//Though not required by the license agreement, please consider the following will be greatly appreciated:
//- We would like to hear about projects where GZE is used.
//- Include an attribution statement somewhere in your project.
//- If you want to see GZE evolve please help us with a donation.


#if !( defined tHDef_Lib_GZ_Str)
#define tHDef_Lib_GZ_Str

#include "DataRC.h"
#include "Utf8.h"


#define gzp_nS  *_nS

//#RULE #1 DataCow are always readonly
//#RULE #2 DataCow never have ptr (Always pods) (like string)
//#RULE #3 DataCow never have weak_ptr


#define _gzStr const _gzeStr8&
#define _gzStr8 const _gzeStr8&
#define _gzStr16 const _gzeStr16&
#define _gzStr32 const _gzeStr32&


	class gzStr8;
	class gzStr16;
	class gzStr32;
	
	
typedef  gzStr8 gzStr;

/////////////////////////////////////////////////////////
/////////////////////   UTF8  ///////////////////////////
/////////////////////////////////////////////////////////
#undef gzp_ReturnType 
#define gzp_ReturnType gzUTF8

#undef gzp_nByte
#define gzp_nByte 1
#define gzp_IsUTF8
	
	class _gzeStr8;
	
	class gzStr8 {
	public:
		#undef gzp_DataType
		#define gzp_DataType gzStr8
		
		 gzp_DataType(const _gzeStr8& _sReturn){
			m = ((gzStr8*)(&_sReturn))->m;
		}
		
		#include "gzStringCommon.h"
		#include "gzStringBaseConstuct.h"
	};

	class _gzeStr8 {
	public:
		#undef gzp_DataType
		#define gzp_DataType _gzeStr8
		
		#define gzp_PARAM
		
			gzp_DataType(gzStr8* _pOther){
			//  m = _pOther->m;
			  
			  	  	m.aData = _pOther->m.aData;
			 	m.aSubTab =	_pOther->m.aSubTab;
				m.nSubSize =	_pOther->m.nSubSize;
				m.nSubLimit =	_pOther->m.nSubLimit;
			}
			
			gzp_DataType( gzStr8 _oOther){  //ReOwn
			  m = _oOther.m;
			  
			  	  	m.aData = _oOther.m.aData;
			 	m.aSubTab =	_oOther.m.aSubTab;
				m.nSubSize =	_oOther.m.nSubSize;
				m.nSubLimit =	_oOther.m.nSubLimit;
			}

			#include "gzStringCommon.h"
			#include "gzStringBaseConstuct.h"
			
		#undef gzp_PARAM

	};
	
#undef gzp_IsUTF8
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
/////////////////////   UTF16  ///////////////////////////
/////////////////////////////////////////////////////////
#undef gzp_ReturnType 
#define gzp_ReturnType gzUTF16

#undef gzp_nByte
#define gzp_nByte 2
#define gzp_IsUTF16
	
	class _gzeStr16;
	
	class gzStr16 {
	public:
		#undef gzp_DataType
		#define gzp_DataType gzStr16
		
		 gzp_DataType(const _gzeStr16& _sReturn){
			m = ((gzStr16*)(&_sReturn))->m;
		}
		
		#include "gzStringCommon.h"
		#include "gzStringBaseConstuct.h"
	};

	class _gzeStr16 {
	public:
		#undef gzp_DataType
		#define gzp_DataType _gzeStr16
		
		#define gzp_PARAM
		
			gzp_DataType(gzStr16* _pOther){
			 m = _pOther->m;
			  

			}
			
			gzp_DataType( gzStr16 _oOther){  //ReOwn
			  m = _oOther.m;
			  
			}

			#include "gzStringCommon.h"
			#include "gzStringBaseConstuct.h"
			
		#undef gzp_PARAM

	};
	
#undef gzp_IsUTF16
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////
/////////////////////   UTF16  ///////////////////////////
/////////////////////////////////////////////////////////
#undef gzp_ReturnType 
#define gzp_ReturnType gzUTF32

#undef gzp_nByte
#define gzp_nByte 4
#define gzp_IsUTF32
	
	class _gzeStr32;
	
	class gzStr32 {
	public:
		#undef gzp_DataType
		#define gzp_DataType gzStr32
		
		 gzp_DataType(const _gzeStr32& _sReturn){
			m = ((gzStr32*)(&_sReturn))->m;
		}
		
		#include "gzStringCommon.h"
		#include "gzStringBaseConstuct.h"
	};

	class _gzeStr32 {
	public:
		#undef gzp_DataType
		#define gzp_DataType _gzeStr32
		
		#define gzp_PARAM
		
			gzp_DataType(gzStr32* _pOther){
			  m = _pOther->m;
			}
			
			gzp_DataType( gzStr32 _oOther){  //ReOwn
			  m = _oOther.m;
			}

			#include "gzStringCommon.h"
			#include "gzStringBaseConstuct.h"
			
		#undef gzp_PARAM

	};
	
#undef gzp_IsUTF32
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


gzStr8 gzStrC(const char* _Array);
gzStr8 gzStrC(gzInt* _Array);
gzStr8 gzStrC(const char* _Array, gzUInt _nCount);
gzStr8 gzStrUI(gzUInt64 _nEntier);


#undef gzp_nS



#endif
