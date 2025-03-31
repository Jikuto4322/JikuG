#pragma once

#ifdef JG_PLATFORM_WINDOWS

extern JikuG::Application* JikuG::CreateApplication();

int main(int argc, char** argv)
{
	auto app = JikuG::CreateApplication();
	app->Run();
	delete app;
}

#endif

