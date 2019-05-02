#pragma once
#ifdef EX_PLATFORM_WIN

extern EngX::App* EngX::CreateApp();

int main(int argc, char** argv) {
	auto app = EngX::CreateApp();
	app->Run();
	delete app;
	return 0;
}
#endif