#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  float i = 0.1 ;
  float i2=0.05;
    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, -20.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setFillColor(sf::Color::Cyan);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Magenta);
        if(triangle.getPosition().x >= 800 )
        {
            i = -i ;
            triangle.setFillColor(sf::Color::Cyan);
        }
        if(triangle.getPosition().x <= 0 )
        {
            i = -i ;
            triangle.setFillColor(sf::Color::Black);
        }
        if(triangle.getPosition().y >= 600 )
        {
            i2 = -i2 ;
            triangle.setOutlineColor(sf::Color::Red);
        }
        if(triangle.getPosition().y <= 0 )
        {
            i2 = -i2;
            triangle.setOutlineColor(sf::Color::Blue);
        }


      triangle.setPosition(triangle.getPosition().x + i , triangle.getPosition().y + i2);


        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}
