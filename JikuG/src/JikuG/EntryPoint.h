#pragma once

#ifdef JG_PLATFORM_WINDOWS

extern JikuG::Application* JikuG::CreateApplication();

int main(int argc, char** argv)
{
	JikuG::Log::Init();
	JG_CORE_WARN("Initialized Log!");
	int a = 5;
	JG_INFO("Hello! Var={0}", a);

	auto app = JikuG::CreateApplication();
	app->Run();
	delete app;
}

#endif

