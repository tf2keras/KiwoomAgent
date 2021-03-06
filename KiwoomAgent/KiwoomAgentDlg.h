/*
   Copyright 2016 Hosang Yoon

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

// KiwoomAgentDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "sibyl/util/Config.h"
#include "sibyl/server/Kiwoom/Kiwoom.h"
#include "sibyl/server/NetServer.h"

// CKiwoomAgentDlg 대화 상자
class CKiwoomAgentDlg : public CDialogEx
{
// 생성입니다.
public:
    CKiwoomAgentDlg(CWnd* pParent = NULL);    // 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_AGENTKIWOOM_DIALOG };
#endif

    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// my stuff
private:
    static CKiwoomAgentDlg *this_;
    static sibyl::CSTR& TimeStr();
    void UpdateWindowTitle();
    void Launch();
    
    sibyl::Config config;
    sibyl::Kiwoom kiwoom;
    sibyl::KiwoomServer server;

// 구현입니다.
protected:
    HICON m_hIcon;

    // 생성된 메시지 맵 함수
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    DECLARE_EVENTSINK_MAP()
    void OnEventConnect(long nErrCode);
    virtual void OnOK();
    virtual void OnCancel();
    afx_msg void OnBnClickedButtonExit();
    CButton m_bnRun;
    afx_msg void OnBnClickedButtonRun();
    void OnReceiveTrData(LPCTSTR sScrNo, LPCTSTR sRQName, LPCTSTR sTrCode, LPCTSTR sRecordName, LPCTSTR sPrevNext, long nDataLength, LPCTSTR sErrorCode, LPCTSTR sMessage, LPCTSTR sSplmMsg);
    void OnReceiveRealData(LPCTSTR sRealKey, LPCTSTR sRealType, LPCTSTR sRealData);
    void OnReceiveMsg(LPCTSTR sScrNo, LPCTSTR sRQName, LPCTSTR sTrCode, LPCTSTR sMsg);
    void OnReceiveChejanData(LPCTSTR sGubun, long nItemCnt, LPCTSTR sFIdList);
};
