#ifndef __WebViewer_H__
#define __WebViewer_H__

#include <FUi.h>
#include <FWeb.h>
#include <FBase.h>
#include <FApp.h>
#include <FSystem.h>


class WebViewer :
    public Osp::App::Application,
    public Osp::System::IScreenEventListener,
    public Osp::Ui::IActionEventListener,
    public Osp::Ui::ITextEventListener
{
    public:
        // The application must have a factory method that creates an instance of the application.
        static Application* CreateInstance(void);


    public:
        WebViewer();
        ~WebViewer();


    public:
        // This method is called when the application is on initializing.
        bool OnAppInitializing(Osp::App::AppRegistry& appRegistry);

        // This method is called when the application is on terminating.
        bool OnAppTerminating(Osp::App::AppRegistry& appRegistry, bool forcedTermination = false);

        // Thie method is called when the application is brought to the foreground
        void OnForeground(void);

        // This method is called when the application is sent to the background.
        void OnBackground(void);

        // This method is called when the application has little available memory.
        void OnLowMemory(void);

        // This method is called when the device's battery level is changed.
        void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);

        void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

        void OnTextValueChangeCanceled(const Osp::Ui::Control& source);
        void OnTextValueChanged(const Osp::Ui::Control& source);

        //	Called when the screen turns on.
        void OnScreenOn (void);

        //	Called when the screen turns off.
        void OnScreenOff (void);


    private:
        result __CreateWebForm(void);

        Osp::Ui::Controls::Form* __pMainForm;
        Osp::Web::Controls::Web* __pWeb;
        Osp::Ui::Controls::Button* __pButton1;
        Osp::Ui::Controls::Button* __pButton2;
        Osp::Ui::Controls::Button* __pButton3;
        Osp::Ui::Controls::EditField* __pEdit;
};

#endif
