#include "Engine.h"
#include "Resources.h"
#include "Snake.h"
#include "Menu.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine* engine = new Engine();

	engine->window->Mode(WINDOWED);
	engine->window->Size(500, 500);
	engine->window->Color(25, 25, 25);
	engine->window->Title("Snake");
	engine->window->Icon(IDI_ICON);
	//engine->window->Cursor(IDC_CURSOR);

	int status = engine->Start(new Menu());

	delete engine;
	return status;
}