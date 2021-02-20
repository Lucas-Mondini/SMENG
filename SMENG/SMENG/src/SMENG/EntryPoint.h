#pragma once

#ifdef SEG_PLATAFORM_WINDOWS

extern SMENG::Application* SMENG::CreateApplication();

int main(int argc, char** argv) {

	SMENG::Log::Init();
	SMENG_CORE_INFO("Initialized Log");
	SMENG_CORE_WARN("Creating application...");

	auto app = SMENG::CreateApplication();
	SMENG_CORE_INFO("Application created sucessfully");
	app->Run();
	delete app;
}

#endif // SEG_PLATAFORM_WINDOWS
