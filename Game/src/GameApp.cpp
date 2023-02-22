#include <Schlutzkrapfen.h>

class Game : public Schlutzkrapfen::Application {
public:
	Game()
	{

	}

	~Game() {

	}
};

Schlutzkrapfen::Application* Schlutzkrapfen::CreateApplication()
{
	return new Game();
}