#include <SMENG.h>


class Sandbox : public SMENG::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
private:
};


SMENG::Application* SMENG::CreateApplication() {
	return new Sandbox();
}