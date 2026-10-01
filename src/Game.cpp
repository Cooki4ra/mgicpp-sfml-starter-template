
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL)); //seeds random number generator with the current time
}

Game::~Game()
{

}

// We call this once after the game class is instantiated
bool Game::init()
{
	if (!background_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/background.png"))
	{
		std::cout << "Failed to load background texture \n" << std::endl;
	}
	background.setTexture(background_texture);
	background = sf::Sprite(background_texture);
	bird_texture.loadFromFile("../Data/Images/WhackaMole Worksheet/bird.png");
	bird.setTexture(bird_texture);
	bird = sf::Sprite(bird_texture);
	bird.setPosition({100,100});
	bird.setScale({ 0.5,0.5 });

	font.openFromFile("../Data/Fonts/OpenSans-Bold.ttf");
	text.setString("Whack a Mole");
	start.setString("Start");
	quit.setString("Quit");
	text.setCharacterSize(150);
	start.setCharacterSize(50);
	quit.setCharacterSize(50);
	text.setFillColor(sf::Color::Red);
	start.setFillColor(sf::Color::White);
	quit.setFillColor(sf::Color::White);
	text.setPosition({ window.getSize().x / 2 - text.getGlobalBounds().size.x / 2, window.getSize().y / 4 - text.getGlobalBounds().size.y });
	start.setPosition({ window.getSize().x / 2  - start.getGlobalBounds().size.x / 2, window.getSize().y / 2 - start.getGlobalBounds().size.y});
	quit.setPosition({ window.getSize().x / 2  - quit.getGlobalBounds().size.x / 2, window.getSize().y / 2 + start.getGlobalBounds().size.y});


	

  return true;
}

// Update runs after event polling and before rendering
// use it for everything that needs to update between frames
void Game::update(float dt)
{

}

// Runs after update, use it to tell the window what to draw this frame
void Game::render()
{
	switch (mode)
	{
		case Mode::Game:
			window.draw(background);
			window.draw(bird);
			break;
		case Mode::Menu:
			window.draw(text);
			window.draw(start);
			window.draw(quit);

			break;
	}
}

//Called by event polling when a MouseButtonPressed event is found
void Game::mouseButtonPressed(const sf::Event::MouseButtonPressed* event)
{
	// Event contains mouse position and which button was clicked

	// Don't need to extract position to a variable like this, this is just to show you it's a Vector2i
	sf::Vector2i position = event->position;

	// You can tell which button was pressed by comparing it to SFML's definitions of mouse buttons
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was pressed
	}
}

//Called by event polling when a MouseButtonReleased event is found
void Game::mouseButtonReleased(const sf::Event::MouseButtonReleased* event)
{
	//Works the same as MouseButtonPressed
	if (event->button == sf::Mouse::Button::Left)
	{
		//Left mouse button was released
	}
}

// Called by event polling when a KeyPressed event is found
void Game::keyPressed(const sf::Event::KeyPressed* event)
{
	// You can tell which button was pressed by the scancode to SFML's definitions of keyboard keys
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was pressed
	}
	if (event->scancode == sf::Keyboard::Scancode::Up)
	{
		// W was pressed
	}
}

// Called by event polling when a KeyReleased event is found
void Game::keyReleased(const sf::Event::KeyReleased* event)
{
	// Works the same way as KeyPressed
	if (event->scancode == sf::Keyboard::Scancode::W)
	{
		// W was released
	}

}


