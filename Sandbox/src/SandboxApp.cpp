#include <JikuG.h>

class ExampleLayer : public JikuG::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	}

	void OnUpdate() override
	{
		JG_INFO("ExampleLayer::Update");
	}

	void OnEvent(JikuG::Event& event) override
	{
		JG_TRACE("{0}", event);
	}
};

class Sandbox : public JikuG::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

JikuG::Application* JikuG::CreateApplication()
{
	return new Sandbox();
}