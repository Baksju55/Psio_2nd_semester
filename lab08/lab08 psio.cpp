#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include<time.h>
class CustomRectangleShape : public sf::RectangleShape
{
public:
    CustomRectangleShape(sf::Vector2f size , sf::Vector2f position , sf::Vector2f predkosc2 = sf::Vector2f(0,0)) : sf::RectangleShape(size)
    {
        setPosition(position) ;
        setFillColor(sf::Color::Green);
        predkosc = predkosc2;
        blokada = false; 

    }
    int sprawdz_mysz(sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
           // std::cout << "LPM jest wcisniety!" << std::endl;
            return 1;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            //std::cout << "PPM jest wcisniety!" << std::endl;
            return 2;
        }
        else
        return 0;
    }
    sf::Vector2f sprawdz_klaw(sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f predkosc = sf::Vector2f(0, 0); 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
          //  std::cout << "A jest wcisniete" << std::endl;
            predkosc.x = -0.5;

        }
        else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            //std::cout << "D jest wcisniete" << std::endl;
            predkosc.x = 0.5;
        }
        else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            //std::cout << "W jest wcisniete" << std::endl;
            predkosc.y = -0.5;
        }
        else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            //std::cout << "S jest wcisniete" << std::endl;
            predkosc.y = 0.5;
        }
        else
            return predkosc; 
        
    }
    void move2(sf::RenderWindow& window)
    {
        sf::Vector2f predkosc = sprawdz_klaw(window); 
       
        move(predkosc); 
        if (getGlobalBounds().left + getGlobalBounds().width >= 800)
        {
            setPosition(800 - getGlobalBounds().width , getPosition().y); 

        }
        if (getGlobalBounds().left <= 0)
        {
            setPosition( 0  , getPosition().y);
        }
        if (getGlobalBounds().top + getGlobalBounds().height >= 600)
        {
            setPosition( getPosition().x, 600 - getGlobalBounds().height);
        }
        if (getGlobalBounds().top <= 0)
        {
            setPosition(getPosition().x, 0);
        }
       

    }


   void update(sf::Time czas , sf::RenderWindow& window)
   {
       sf::Event event; 
       if (blokada == true)
       {
           move2(window); 
       }
       
        
           
       if (sf::Mouse::getPosition(window).x > getGlobalBounds().left && sf::Mouse::getPosition(window).x < getGlobalBounds().left + getGlobalBounds().width && sf::Mouse::getPosition(window).y > getGlobalBounds().top && sf::Mouse::getPosition(window).y < getGlobalBounds().top + getGlobalBounds().height )
       {
          // std::cout << "wcisniete" << std::endl;
           if ( sprawdz_mysz(window) == true && blokada == false )
           {
               blokada = true; 
               setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
           }
           else if (sprawdz_mysz(window) == 2 && blokada == true)
           {
               blokada = false;
               setFillColor(sf::Color::Green);

           }
           
           
          

       }
      // std::cout<<czas.asSeconds()<<"    "<<predkosc.x<<std::endl;
       if(obrot < 1)
       obrot = obrot*1.01;
       if(getGlobalBounds().left + getGlobalBounds().width >= 800)
       {
           predkosc.x = - predkosc.x ;
       }
       if(getGlobalBounds().left <= 0   )
       {
           predkosc.x = - predkosc.x ;
       }
       if(getGlobalBounds().top + getGlobalBounds().height >= 600 )
       {
           predkosc.y = - predkosc.y ;
       }
       if(getGlobalBounds().top <= 0   )
       {
          predkosc.y = - predkosc.y ;
       }
       if (blokada == false)
       {
           move(predkosc);
       }
       if (blokada == true)
       {
        //   std::cout << "blokada";
       }
   }
protected:
    sf::Vector2f predkosc;
    sf::Vector2f predkosc2 ;
 float obrot = 0.1;
 int cos; 
 bool blokada = 0 ;

};

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // create some shapes
  std::vector<CustomRectangleShape> rectangles;
  std::srand(std::time(nullptr)); 
  for (int i = 0; i < 10; i++) 
  {
     
      float rand_x = rand() % 700; 
      float rand_y = rand() % 500;
      float rand_vx = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.1f;   
      float rand_vy = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 0.1f;
      rectangles.emplace_back(CustomRectangleShape(sf::Vector2f(50, 60), sf::Vector2f(rand_x, rand_y), sf::Vector2f(rand_vx, rand_vy)));
  }


   
     sf::Clock zegar ;
     sf::Time czas ;
     zegar.restart() ;
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        czas = zegar.getElapsedTime() ;
        // clear the window with black color
        window.clear(sf::Color::Magenta);
      for ( auto& rec : rectangles)
      {
          rec.update(zegar.getElapsedTime(), window); 
          window.draw(rec); 
      }

        // end the current frame
        window.display();
    }

    return 0;
}
