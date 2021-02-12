#pragma once

#ifdef SEG_PLATAFORM_WINDOWS

extern SMENG::Application* SMENG::CreateApplication();

int main(int argc, char** argv) {
	printf("Entry Point");
	auto app = SMENG::CreateApplication();
	app->Run();
	delete app;
}

#endif // SEG_PLATAFORM_WINDOWS
