#include <EngX.h>

struct ExampleLayer : EngX::Layer
{
	ExampleLayer() : Layer("example") {};

	void OnUpdate() override
	{
		EX_INFO("Example Layer Update");
	}

	void OnEvent(EngX::Event& event) override
	{
		EX_TRACE("{0}", event);
	}

};


struct Sandbox : EngX::App
{
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

EngX::App* EngX::CreateApp() {
	return new Sandbox();
}