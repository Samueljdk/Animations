#include <SFML/Graphics.hpp> // sfml is a graphics libraary for 
#include <iostream>
#include <cstdlib> // allows me to access the system cmd functions such as clear 
using namespace sf;
using namespace std;

void ResizableRectangle() {
	float screenWidth = 1000;
	float screenHeight = 600;
	float rectangleWidth = 50;
	float rectangleHeight = 50;
	
	RenderWindow window(VideoMode(screenWidth, screenHeight), "Resizable Rectangle");
	window.setPosition(Vector2i(0, 0)); //
	
	RectangleShape rectangle;
	rectangle.setFillColor(Color::Green);
	rectangle.setOutlineColor(Color::White);
	rectangle.setOutlineThickness(5);

	while (window.isOpen()) {
		rectangle.setSize(Vector2f(rectangleWidth, rectangleHeight));
		
		Event event;

		if (Keyboard::isKeyPressed(Keyboard::W)) {
		
			if(rectangleWidth < screenWidth-10)rectangleWidth+=0.1;
			if (rectangleHeight < screenHeight-10)rectangleHeight+=0.1;
	
		}
		
		if (Keyboard::isKeyPressed(Keyboard::N)) {
			if (rectangleWidth > 50)rectangleWidth-=0.1;
			if (rectangleHeight > 50)rectangleHeight-=0.1;

		}

		while (window.pollEvent(event)) { // keeps checking to see if the user closed the windo
			if (event.type == Event::Closed) {
				window.close(); // closes the window
			}
		}
		
		window.clear();
		window.draw(rectangle);
		window.display();
	}

}

int main() {
	ResizableRectangle();
	return 0;
}