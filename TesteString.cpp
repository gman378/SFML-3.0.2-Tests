#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Keyboard Test Game");

  const sf::Font Fonte ("/home/derek/Documents/C++ Projects/Visual Studio Code/src/Fontes/OldeEnglish.ttf");

  int Vida = 100;

  sf::Text Texto(Fonte);

  sf::Text Texto2(Fonte, "Ola Mundo!", 50);

  Texto2.setPosition({500, 100});

  sf::RectangleShape Boneco;

  Boneco.setSize({50, 50});
  Boneco.setFillColor(sf::Color::Red);
  Boneco.setPosition({500, 500});

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    Texto.setString("Vida:" + std::to_string(Vida));
    Texto.setCharacterSize(50);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
  {
    Boneco.move({0.0, -0.1});
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    Boneco.move({0.0, 0.1});
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    Boneco.move({-0.1, 0.0});

  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    Boneco.move({0.1, 0.0});
  }
  


  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){

    Vida -= 10;

    //Teste para brincar com a vida do boneco.

  }

  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)){

 Vida += 10;


  }
  

  if (Vida == 0)
  {
    Texto.setFillColor(sf::Color::Red);
  }
  
  


    window.clear();
    window.draw(Texto);
    window.draw(Boneco);
    window.draw(Texto2);
    window.display();
  }
}