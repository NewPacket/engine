#include <EngX.h>

#include <imgui.h>

struct ExampleLayer : EngX::Layer
{
	ExampleLayer() : Layer("example") {};

	void OnAttach() 
	{
	}

	void OnUpdate() override
	{
		EX_INFO("Example Layer Update");
	}

	void OnEvent(EngX::Event& event) override
	{
		EX_TRACE("{0}", event);
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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