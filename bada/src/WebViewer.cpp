//==================================================================
// APP. Name   : WebViewer.cpp
// Version     : 1.0.0
// Vendor      : 
// Description : 
//==================================================================

#include "WebViewer.h"

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Locales;
using namespace Osp::System;
using namespace Osp::App;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Web::Controls;

#define AC_SOFTKEY_EXIT				0x1001

#define AC_BUTTON_WEB_BACK			0x3001
#define AC_BUTTON_WEB_FORWARD		0x3002
#define AC_BUTTON_WEB_LOAD			0x3003

WebViewer::WebViewer()
: __pMainForm(null), __pWeb(null), __pButton1(null), __pButton2(null), __pButton3(null), __pEdit(null)
{

}

WebViewer::~WebViewer()
{

}

Application* WebViewer::CreateInstance(void)
{
    // You can create the instance through another constructor.
    return new WebViewer();
}

bool WebViewer::OnAppInitializing(AppRegistry& appRegistry)
{
    result r = E_SUCCESS;

    r = __CreateWebForm();
    if (IsFailed(r))
    {
        AppLog("CreateMainForm() has failed.\n");
        goto CATCH;
    }

    // Uncomment the following statement to listen to the screen on/off events.
    //PowerManager::SetScreenEventListener(*this);

    return true;

CATCH:
    return false;
}

bool WebViewer::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
    // TODO:
    // Deallocate or close any resources still alive.
    // Save the application's current states, if applicable.
    // If this method is successful, return true; otherwise, return false.
    return true;
}

void WebViewer::OnForeground(void)
{

}

void WebViewer::OnBackground(void)
{

}

void WebViewer::OnLowMemory(void)
{
    // TODO:
    // Deallocate as many resources as possible.
}

void WebViewer::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{

}

result WebViewer::__CreateWebForm(void)
{
    result r = E_SUCCESS;
    Rectangle bound;
    IAppFrame* pAppFrame = GetAppFrame();

    if (NULL == pAppFrame)
    {
        AppLog("GetAppFrame() has failed.\n");
        goto CATCH;
    }

    /*form*/
    __pMainForm = new Form();
    r = __pMainForm->Construct(FORM_STYLE_SOFTKEY_1|FORM_STYLE_INDICATOR);
    TryCatch(r == E_SUCCESS, , "form is not constructed\n ");

    __pMainForm->SetBackgroundColor(Color(85,104,114));
    __pMainForm->SetSoftkeyText (SOFTKEY_1 , L"Accueil");
    __pMainForm->SetSoftkeyActionId (SOFTKEY_1, AC_SOFTKEY_EXIT);
    __pMainForm->AddSoftkeyActionListener (SOFTKEY_1, *this);

    pAppFrame->GetFrame()->AddControl(*__pMainForm);


    /*__pButton1 = new Button();
      r = __pButton1->Construct(Rectangle(0,0, 160, 80), L"Back");
      TryCatch(r == E_SUCCESS, ,"button is not constructed\n ");

      __pButton1->SetActionId(AC_BUTTON_WEB_BACK);
      __pButton1->AddActionEventListener(*this);
      r = __pMainForm->AddControl(*__pButton1);
      TryCatch(r == E_SUCCESS, ,"button is not attached\n ");


      __pButton2 = new Button();
      r = __pButton2->Construct(Rectangle(160,0, 160, 80), L"Forward");
      TryCatch(r == E_SUCCESS, , "button2 is not constructed\n ");

      __pButton2->SetActionId(AC_BUTTON_WEB_FORWARD);
      __pButton2->AddActionEventListener(*this);
      r = __pMainForm->AddControl(*__pButton2);
      TryCatch(r == E_SUCCESS, ,"button2 is not attached\n ");


      __pButton3 = new Button();
      r = __pButton3->Construct(Rectangle(320,0, 160, 80), L"Load");
      TryCatch(r == E_SUCCESS, ,"button1 is not constructed\n ");

      __pButton3->SetActionId(AC_BUTTON_WEB_LOAD);
      __pButton3->AddActionEventListener(*this);
      r = __pMainForm->AddControl(*__pButton3);
      TryCatch(r == E_SUCCESS, ,"button3 is not attached\n ");


      __pEdit = new EditField();
      r = __pEdit->Construct(Rectangle(5, 86, 470, 60), EDIT_FIELD_STYLE_URL_SMALL);
      TryCatch(r == E_SUCCESS, ,"editfield is not constructed\n ");
      __pEdit->AddTextEventListener(*this);
      __pEdit->SetText (Osp::Base::String("http://wap2.samsungmobile.com"));
      r = __pMainForm->AddControl(*__pEdit);*/

    /*Web*/
    __pWeb = new Web();
    r = __pWeb->Construct(Rectangle(0, 0, 480, 760));
    TryCatch(r == E_SUCCESS, ,"Web is not constructed\n ");

    r = __pMainForm->AddControl(*__pWeb);
    TryCatch(r == E_SUCCESS, ,"Web is not attached\n ");

    __pWeb->LoadUrl("http://www.google.com");

    __pWeb->SetFocus();

    return r;

CATCH:
    AppLog("Error = %s\n", GetErrorMessage(r));
    return r;
}

void WebViewer::OnActionPerformed(const Control& source, int actionId)
{
    result r = E_SUCCESS;
    __pWeb->SetZoomLevel(0.3);

    switch(actionId)
    {
        case AC_SOFTKEY_EXIT :
            __pWeb->LoadUrl("http://www.qmce.org/xmotor/index.php?device=bada");
            __pWeb->SetZoomLevel(0.3);
            break;
        default:
            break;
    }

    return;
}

void WebViewer::OnTextValueChangeCanceled(const Osp::Ui::Control &source)
{
    __pMainForm->SetFocus();
}

void WebViewer::OnTextValueChanged  (const Osp::Ui::Control &source)
{
    __pMainForm->SetFocus();
}

void WebViewer::OnScreenOn (void)
{
    // TODO:
    // Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void WebViewer::OnScreenOff (void)
{
    // TODO:
    //  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
    // Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
    // Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}
