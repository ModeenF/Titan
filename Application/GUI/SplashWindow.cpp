#include "SplashWindow.h"

#include "EMBitmap.h"
#include "EMFactory.h"
#include "EMMessages.h"
#include "EMResourceRepository.h"
#include "EMWindow.h"
#include "EMView.h"
#include "ResourceIDs.h"


const int32 LABEL_HEIGHT = 15;

SplashWindow::SplashWindow() :
m_opWindow(EMFactory::Instance() -> CreateEMWindow(EMRect(0, 0, 475, 349 + LABEL_HEIGHT), "Splash Screen", EM_WINDOW_SPLASH)),
m_opView(EMFactory::Instance() -> CreateView(EMRect(0, 0, 475, 349 + LABEL_HEIGHT), false)),
m_oVersionNumber("")
{
}

SplashWindow::~SplashWindow()
{
	delete m_opWindow;
	delete m_opView;
}

void SplashWindow::Display()
{
	if(m_opWindow -> Lock())
	{
		m_opWindow -> Show();

		m_opView -> BeginPaint();
		m_opView -> DrawBitmap(m_opSplashBitmap, 0, 0);
		m_opView -> EndPaint();

		m_opWindow -> Unlock();
	}
}

void SplashWindow::DisplayInfo(const char* p_vVersionNumber, bool p_vIsCrippled)
{
	m_oVersionNumber = p_vVersionNumber;
	m_vIsCrippled = p_vIsCrippled;

	if(m_opView -> LockWindow())
	{
		m_opView -> BeginPaint();
		Draw();
		m_opView -> EndPaint();
		m_opView -> UnlockWindow();
	}
}

void SplashWindow::DisplayText(const char* p_vText)
{
	m_oText = p_vText;

	if(m_opView -> LockWindow())
	{
		m_opView -> BeginPaint();
		m_opView -> SetHighColor(EMColor(230, 230, 230, 255));
		m_opView -> FillRect(EMRect(0, 349, 475, 349 + LABEL_HEIGHT));
		m_opView -> SetHighColor(EMColor(0, 0, 0, 255));
		m_opView -> DrawString(5, 360, m_oText.c_str());
		m_opView -> EndPaint();

		m_opView -> UnlockWindow();
	}
}

void SplashWindow::Draw()
{
	m_opView -> DrawBitmap(m_opSplashBitmap, 0, 0);
	m_opView -> SetHighColor(EMColor(230, 230, 230, 255));
	m_opView -> FillRect(EMRect(0, 349, 475, 349 + LABEL_HEIGHT));
	m_opView -> SetHighColor(EMColor(0, 0, 0, 255));
	m_opView -> DrawString(5, 360, m_oText.c_str());
	if(m_oVersionNumber != "")
	{
		char vpVersionString[80];
		sprintf(vpVersionString, "Version %s", m_oVersionNumber.c_str());
		m_opView -> DrawString(380, 20, vpVersionString);
		if(m_vIsCrippled)
			m_opView -> DrawString(380, 30, "Unregistered");
	}
}

void SplashWindow::Hide()
{
	if(m_opWindow -> Lock())
	{
		m_opWindow -> Hide();
		m_opWindow -> Unlock();
	}
}

void SplashWindow::Init()
{
	m_opWindow -> AddChild(m_opView);
	m_opView -> AddListener(this);
	m_opSplashBitmap = EMResourceRepository::GetBitmap(RES_SPLASH);
}

bool SplashWindow::MessageReceived(EMListenerRepository* p_opSender, uint32 p_vMessage)
{
	if(p_vMessage == EM_DRAW)
	{
		Draw();
		return true;
	}

	return false;
}

void SplashWindow::CenterWindow()
{
	m_opWindow -> MoveTo(vX, vY);
}
