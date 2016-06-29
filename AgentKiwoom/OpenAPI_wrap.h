#ifndef OPENAPI_WRAP_H_
#define OPENAPI_WRAP_H_

#include "stdafx.h"
#include "KHOpenAPICtrl.h"
#include "sibyl/server/Kiwoom/KiwoomAPI.h"

extern CKHOpenAPI openAPI;

namespace sibyl
{

extern void OpenAPI_wrap_initialize_maps();

extern MarketEventType Map_sRealType(LPCTSTR sRealType);
extern CSTR&           Map_sMsg     (LPCTSTR sMsg);

extern void  SetInputValue  (InputKey key, CSTR &val);
extern long  GetRepeatCnt   (CSTR &TR_name, CSTR &TR_code);
extern long  CommRqData     (CSTR &TR_name, CSTR &TR_code, bool carry, CSTR &scrno);
extern CSTR& GetCommData    (CSTR &TR_name, CSTR &TR_code, long idx, CommDataKey key);
    // CommDataKey::code_g  : strip first character
    // CommDataKey::ordtype : convert EUC-KR string to "1"/"-1" (use enum OrdType)
extern long  SendOrder      (CSTR &TR_name, CSTR &scrno, CSTR &accno, ReqType type, CSTR &code, PQ pq, CSTR &ordno_o);
extern long  SetRealReg     (CSTR &scrno, CSTR &codes, CSTR &FIDs);
extern CSTR& GetCommRealData(CSTR &code, long FID);
extern CSTR& GetChejanData  (long FID);
    // kFID::code           : strip first character
    // kFID::reqstat        : convert EUC-KR string to "0"/"1"/"2" (use enum ReqStat)
    // kFID::reqtype        : convert EUC-KR string to "1"/"2"/"3"/"4"/"5"/"6" (use enum ReqType)

}

#endif
