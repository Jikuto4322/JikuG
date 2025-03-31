#include <JikuG.h>

class Sandbox : public JikuG::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

JikuG::Application* JikuG::CreateApplication()
{
	return new Sandbox();
}