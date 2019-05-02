#include <EngX.h>

struct Sandbox : EngX::App
{
};

EngX::App* EngX::CreateApp() {

	return new Sandbox();
}