//This file is part of "GZE - GroundZero Engine"

//The permisive licence allow to use GZE for free or commercial project (Apache License, Version 2.0).
//For conditions of distribution and use, see copyright notice in Licence.txt, this license must be included with any distribution of the code.

//Though not required by the license agreement, please consider the following will be greatly appreciated:
//- We would like to hear about projects where GZE is used.
//- Include an attribution statement somewhere in your project.
//- If you want to see GZE evolve please help us with a donation.


#if !( defined tHDef_Lib_GZ_DataRC)
#define tHDef_Lib_GZ_DataRC



#define GZ_tDebug



#include "GzTypes.h"
#include "GzBaseFunc.h"
#include "GzMem.h"

#define GZ_Array_Expand_Factor 2


#ifdef GZ_tDebug
    #define GZ_Assert_Array(expr)   if( !(expr )){\
                printf("\nE:FatalArrayError: %s:%d", __FILE__, __LINE__);while(1){} \
            }
#else
    #define GZ_Assert_Array(expr)
#endif




//#define gzNewData(_aData) ((gzDataRoot){ gzNewDataOnly(_aData),0,0 })
//#define gzNewData(_aData)    fStackDataCopyAlloc((gzUInt8*)(gzConcat(gzS8 ,_aData)), (gzUIntX)(sizeof(gzConcat(gzS8 ,_aData))-1))
//#define gzNewData(_aData)    fStackDataCopyAlloc((gzUInt8*)(_aData), (gzUIntX)(sizeof(_aData)))



#define gzNewData8(_aData)    ::GZ::fStackDataCopyAlloc((gzUInt8*)(gzConcat(gzS8 ,_aData)), (gzUIntX)(sizeof(gzConcat(gzS8 ,_aData))-1))
#define gzNewData16(_aData)   ::GZ::fStackDataCopyAlloc((gzUInt8*)(gzConcat(gzS16 ,_aData)), (gzUIntX)(sizeof(gzConcat(gzS16 ,_aData))-2))
#define gzNewData32(_aData)   ::GZ::fStackDataCopyAlloc((gzUInt8*)(gzConcat(gzS32 ,_aData)), (gzUIntX)(sizeof(gzConcat(gzS32 ,_aData))-4))

#define gzNewDataOnly(_aData) ::GZ::fStackDataCopyAlloc((gzUInt8*)(_aData), (gzUIntX)(sizeof(_aData)-1))

#define gzDtThis const_cast<gzp_DataType*>(this)

#define Gz_fMalloc(_type, _size) ((_type*)malloc(sizeof(_type) * _size));
#define GZ_fAnyMalloc(_size) (malloc(_size)) ;
#define GZ_fAnyCalloc(_size) (malloc(_size)) ;
//#define GZ_fFree(_ptr) (free(_ptr)) ;


#ifndef u8
	#define gzS8
#else
	#define gzS8 u8
#endif

#define gzS16 u
#define gzS32 U


#define gzData8(_aData)   ((gzDataRC){(gzUInt8*)(gzConcat(gzS8 ,_aData)),(gzUIntX)(sizeof(gzConcat(gzS8 ,_aData))-1), (gzUIntX)sizeof(gzConcat(gzS8 ,_aData))-1  ,0,0,0,0})
#define gzData16(_aData)  ((gzDataRC){(gzUInt8*)(gzConcat(gzS16,_aData)),(gzUIntX)(sizeof(gzConcat(gzS16,_aData))-2), (gzUIntX)sizeof(gzConcat(gzS16,_aData))-2 ,0,0,0,0})
#define gzData32(_aData)  ((gzDataRC){(gzUInt8*)(gzConcat(gzS32,_aData)),(gzUIntX)(sizeof(gzConcat(gzS32,_aData))-4), (gzUIntX)sizeof(gzConcat(gzS32,_aData))-4 ,0,0,0,0})

#define gzStaticU8(_sName, _aData)  static gzStr8(  gzData8(_aData)  ) _sName;
#define gzStaticU16(_sName, _aData) static gzStr16(  gzData16(_aData) ) _sName;
#define gzStaticU32(_sName, _aData) static gzStr32(  gzData32(_aData) ) _sName;

#define gzU8(_aData)  gzStr8(  gzNewData8(_aData)  )
#define gzU16(_aData) gzStr16(  gzNewData16(_aData) )
#define gzU32(_aData) gzStr32(  gzNewData32(_aData) )

/*
#define gzNewData(_sType, _sName, ...)  \
_sType _sName##_dat[] = {__VA_ARGS__};\
gzDataRC  _sName = GzToDataRC(_sName##_dat);
*/
#define gzData(_sType, _sName, ...)  \
_sType _sName##_dat[] = {__VA_ARGS__};\
gzDataRC  _sName = GzToDataRC(_sName##_dat);

#define gzConstData(_sType, _sName, ...)  \
const _sType _sName##_dat[] = {__VA_ARGS__};\
gzDataRC  _sName = GzToDataRC_const(_sName##_dat);

#define gzStaticData(_sType, _sName, ...)  \
static _sType _sName##_dat[] = {__VA_ARGS__};\
static gzDataRC  _sName = GzToDataRC(_sName##_dat);


#define gzU8(_aData)  gzStr8(  gzNewData8(_aData)  )




//inli
//#define gzStrC(_aData)  gzStr8()




/*
#define gzLStr8(_aData)   gzString8(  gzData8(_aData)  )
#define gzLStr16(_aData) gzString16(  gzData16(_aData) )
#define gzLStr32(_aData) gzString32(  gzData32(_aData) )
*/
#define GzToDataRC_const(_aData) ((gzDataRC){(gzUInt8*)(_aData),(gzUIntX)sizeof(_aData),     (gzUIntX)sizeof(_aData),0,0,0,0})
#define GzToDataRC(_aData) ((gzDataRC){(gzUInt8*)(_aData),(gzUIntX)sizeof(_aData),     (gzUIntX)sizeof(_aData),0,1,0,0})

class gzDataRC;
namespace GZ {
inline gzDataRC* fDataCopyAlloc( gzUInt8* _aData, gzUIntX _nCopySize, gzUIntX _nNewSize,  gzUIntX _nLimit );
};

gzUInt GZ_nArrayTotalFree = 0;
gzUInt GZ_nArrayTotalAlloc = 0;

class gzDataRC {
public:
	gzUInt8* aTab;
	gzUIntX nSize;
	gzUIntX nLimit;
	gzUIntX nSpaceBef;
	gzUInt8 nType; //0 = const / readOnly  (never free)  // 1 =  modifiable (never free)   / 2 = volatile, must free of pure data / 3 =  volatile, must free of sub struct/ptr
	//gzUInt8 nStride;
	gzUInt nInst; //If not readonly
	gzUInt nWeakInst; //If not readonly

	inline void fPrint() const {
		//for(gzUInt i = 0; i < nSize >>  nStride; i++){
		for(gzUInt i = 0; i < nSize; i++){
			putchar(aTab[i]);
		}
		printf("\n");
	}



	inline void fAddInstance() {
		nInst++;
		//printf("\nAdd: %d  ", nInst);fPrint();
	}
	
	inline ~gzDataRC(){
		//printf("\n---------Delete");
	}

	inline  gzDataRC* fCloneToHeap(){
		return GZ::fDataCopyAlloc(aTab, nSize,nSize,nLimit );
	}
	
	/*
	inline void fRemoveInstance_Weak(){
		//printf("\nSub: %d  ", nInst);fPrint();
		nWeakInst--;
		if(nWeakInst == 0 && nInst == 0  ){//nType > 2 Heap data -> must be freed
			Free();
		}
	}*/

};


namespace GZ {
/*
inline static gzDataRC* fEmptyArray(gzUInt _nSize ) {
	return fDataAlloc( _nSize, _nSize * GZ_Array_Expand_Factor );
}*/

inline static gzDataRC*  fDataAlloc(  gzUIntX _nSize,  gzUIntX _nLimit ){
	gzDataRC* _oRc =  (gzDataRC*)GZ_fAnyMalloc(sizeof(gzDataRC)); GZ_nArrayTotalAlloc++;  //Can be optimised with malloc if we be sure that all data are memcpy
	_oRc->aTab = (gzUInt8*)GZ_fAnyCalloc( _nLimit ); GZ_nArrayTotalAlloc++;

	memset( &_oRc->aTab[_nSize], 0, _nLimit - _nSize);//Zero all other
	

	
	_oRc->nSize = _nSize;
	_oRc->nType = 2; //Heap type
	_oRc->nLimit = _nLimit;
	_oRc->nSpaceBef = 0;

	_oRc->nInst = 0;
	_oRc->nWeakInst = 0;
	//_oRc->nStride = 0;
	return _oRc;
}




inline gzDataRC* fDataCopyAlloc( gzUInt8* _aData, gzUIntX _nCopySize, gzUIntX _nNewSize,  gzUIntX _nLimit ){

	gzDataRC* _oRc  = fDataAlloc(_nNewSize,_nLimit );


	memcpy( _oRc->aTab, _aData, _nCopySize);


	return _oRc;
	// new Gz_fMalloc
}

inline  gzDataRC* fStackDataCopyAlloc(gzUInt8* _aData, gzUIntX _nSize){
	return fDataCopyAlloc(_aData, _nSize,_nSize,_nSize );
}


}//GZ
//////////////////////////////////////

struct GZ_DataCOW{
	gzDataRC* aData;

	gzUInt8* aSubTab;
	gzUIntX nSubSize;
	gzUIntX nSubLimit; //(m.aData->nLimit - (m.aSubTab - m.aData->aTab))
}m;

#endif
