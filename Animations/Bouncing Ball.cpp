#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
    RenderWindow window(VideoMode(800, 600), "SFML Circle Example");

    CircleShape circle(50); // radius of 50
    circle.setPosition(375, 275); // position on the window

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        //mango
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
