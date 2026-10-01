
#ifndef SFML_GAME_H
#define SFML_GAME_H

#include <SFML/Graphics.hpp>

enum class Mode
{
	Menu,
	Game,
	GameOver
};


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseButtonPressed(const sf::Event::MouseButtonPressed* event);
  void mouseButtonReleased(const sf::Event::MouseButtonReleased* event);
  void keyPressed(const sf::Event::KeyPressed* event);
  void keyReleased(const sf::Event::KeyReleased* event);

 private:
  sf::RenderWindow& window;
  
  sf::Texture background_texture;
  sf::Sprite background = sf::Sprite(background_texture);
  sf::Texture bird_texture;
  sf::Sprite bird = sf::Sprite(bird_texture);

  sf::Font font;
  sf::Text text = sf::Text(font);
  sf::Text start = sf::Text(font);
  sf::Text quit = sf::Text(font);


  Mode mode = Mode::Menu;
};

#endif // SFML_GAME_H
