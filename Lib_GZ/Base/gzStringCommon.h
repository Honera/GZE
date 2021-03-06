//This file is part of "GZE - GroundZero Engine"

//The permisive licence allow to use GZE for free or commercial project (Apache License, Version 2.0).
//For conditions of distribution and use, see copyright notice in Licence.txt, this license must be included with any distribution of the code.

//Though not required by the license agreement, please consider the following will be greatly appreciated:
//- We would like to hear about projects where GZE is used.
//- Include an attribution statement somewhere in your project.
//- If you want to see GZE evolve please help us with a donation.

#define ASS 1 
	
	#undef gzp_Additional_fAssign2
	#undef gzp_SearchIndex
	#undef gzp_RelSize 
	#undef gzp_RelSizeO 
	
	#undef gzp_Stride
	//#define gzp_Stride (sizeof(ASS) >> 1)
	#define gzp_Stride 0
	
	#define gzp_RelSize (gzp_DataSize >> gzp_Stride)
	#define gzp_RelSizeO gzp_DataSize >> gzp_Stride
	
//	#define gzp_SearchIndex _nIndex = _nIndex << m.aData->nStride;
	#define gzp_SearchIndex(Ex) (Ex << gzp_Stride)
	//#define gzp_SearchIndex ;
	//#define gzp_DataRelSize (gzp_DataSize >>  (sizeof(T) >> 1) )

//	#define gzp_Additional_fAssign2 gzDtThis->nPos = 0;gzDtThis->nIndex = 0;
	/*
	#define gzp_IsUTF8 (sizeof(ASS) == 1)
	#define gzp_IsUTF16 (sizeof(ASS) == 2)
	#define gzp_IsUTF32 (sizeof(ASS) == 4)
	*/
	
	#include "DataCowBase.h"

	
	
	#define gzp_NewAssing(_Func, _nMaxPossibleSize, _nStride)\
				gzDataRC* _aNewData =   GZ::fDataAlloc( _nMaxPossibleSize, _nMaxPossibleSize);\
				gzUIntX _nNewSize = _Func;\
				fRemoveInstance(m.aData);   \
				fAssignArray(_aNewData); \
				gzDtThis->m.aData->nSize = _nNewSize;\
				gzDtThis->m.nSubSize = _nNewSize;
			//	m.aData->nStride = _nStride; \
			
			
			
			
			
			
			
	/////////// TO UTF8 //////////
	inline void f_UTF16_2_UTF8() const{ //Protected?
		gzp_NewAssing( fConvertUTF16toUTF8( (gzUInt16*)m.aSubTab, gzp_DataSize, _aNewData->aTab) ,  m.nSubSize * 2 , 0); 
	}
	inline void f_UTF32_2_UTF8() const{ //Protected?
		//printf("Shift:%d", (sizeof(T) >> 1)); 
		//printf("size:%d", gzp_DataSize); 
		gzp_NewAssing( fConvertUTF32toUTF8(  (gzUInt32*)m.aSubTab, gzp_DataSize , _aNewData->aTab),  m.nSubSize, 0); 
	}
	
    #ifndef  gzp_IsUTF8
	gzStr8 fToUTF8() const;	
	 #endif
	////////////////////////////////////
	
	/////////// TO UTF16 //////////
	inline void f_UTF8_2_UTF16() const{ //Protected?
	
		gzp_NewAssing(fConvertUTF8toUTF16( (gzUInt8*)m.aSubTab, gzp_DataSize ,(gzUInt16*)_aNewData->aTab),  m.nSubSize * 4, 1); 
	}
	inline void f_UTF32_2_UTF16() const{ //Protected?
		gzp_NewAssing( fConvertUTF32toUTF16( (gzUInt32*)m.aSubTab, gzp_DataSize ,(gzUInt16*)_aNewData->aTab),  m.nSubSize, 1); 
	}

	 #ifndef  gzp_IsUTF16
	 gzStr16 fToUTF16() const;
	 #endif
	////////////////////////////////////
	
	/////////// TO UTF32 //////////
	inline void f_UTF8_2_UTF32() const{ //Protected?
		gzp_NewAssing(fConvertUTF8toUTF32( (gzUInt8*)m.aSubTab, gzp_DataSize ,(gzUInt32*)_aNewData->aTab),  m.nSubSize * 4, 1); 
	}
	inline void f_UTF16_2_UTF32() const{ //Protected?
		gzp_NewAssing( fConvertUTF16toUTF32( (gzUInt16*)m.aSubTab, gzp_DataSize ,(gzUInt32*)_aNewData->aTab),  m.nSubSize * 2, 2); 
	}
	
	#ifndef  gzp_IsUTF32
	gzStr32 fToUTF32() const;
	#endif
	////////////////////////////////////


	
	
	//////////////////////////
	 void fPrint() const {
		#ifdef gzp_IsUTF8
			fPrintData();
		#endif

		#ifdef gzp_IsUTF16
			gzStr8 _oNew((gzStr8*)gzDtThis);
			_oNew.f_UTF16_2_UTF8();
			_oNew.fPrintData();
		#endif
		
		#ifdef gzp_IsUTF32
			gzStr8 _oNew((gzStr8*)gzDtThis);
			_oNew.f_UTF32_2_UTF8();
			_oNew.fPrintData();
		#endif
	}

	/*gzUIntX nPos;
	gzUIntX nIndex;
	
	inline gzUInt8 fU8_next(gzUInt8* _sSrc) {
		return trailingBytesForUTF8[*_sSrc] + 1;
	}
	inline gzInt8 fU8_prev(gzUInt8* _sSrc) {
		int i = 0;
		(void)(isutf(_sSrc[--i]) || isutf(_sSrc[--i]) ||
			   isutf(_sSrc[--i]) || --i);
		return i;
	}

	inline void fNext(){
		nIndex++;
		nPos += fU8_next( &gzp_DataArray[nPos] );
	//	printf("val %d", );
	
	}
		
	inline void fPrev(){
		nIndex--;
		nPos += fU8_prev( &gzp_DataArray[nPos] );
			//	printf("aassss ");
	}
	*/
	
	
