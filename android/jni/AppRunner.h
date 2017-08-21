// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#ifndef APPRUNNER_H_
#define APPRUNNER_H_

#include "Graphics.h"
#include "AppHost.h"
#include "GlDisplayService.h"
#include "Types.h"

class AppRunner : Eegeo::NonCopyable
{
public:
	AppRunner(
	    AndroidNativeState* pNativeState
	);
	~AppRunner();

	void Pause();
	void Resume();
	void ActivateSurface();
	void Update(float deltaSeconds, const float headTansform[]);
	void StopUpdatingNativeBeforeTeardown();
    void HandleTouchEvent(const Eegeo::Android::Input::TouchInputEvent& message);
    
    void UpdateCardboardProfile(const float cardboardProfile[]);
    void MagnetTriggered();
    void ToggleNightMode(const bool turnOn);
    
private:
	AndroidNativeState* m_pNativeState;

	GlDisplayService m_displayService;
	void ReleaseDisplay();
	bool TryBindDisplay();
    AppHost* m_pAppHost;
    bool m_updatingNative;
	bool m_isPaused;
	void CreateAppHost();
};

#endif
