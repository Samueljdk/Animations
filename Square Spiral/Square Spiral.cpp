#include <SFML/Graphics.hpp> // sfml is a graphics libraary for 
#include <iostream>
#include <cstdlib> // allows me to access the system cmd functions such as clear 
using namespace sf;
using namespace std;

void squareSpiral() {
	float screenWidth = 800;
	float screenHeight = 800;
	RenderWindow window(VideoMode(screenWidth, screenHeight), "Square Spiral Animation");
	window.setPosition(Vector2i(0, 0)); //
	float xPosition = screenWidth / 2;
	float yPosition = screenHeight / 2;
	const int numOfSquares = 10;
	float sidelength = 100;
	RectangleShape squares[numOfSquares];

	
	for (int i = 1; i <= numOfSquares; i++) {
			squares[i-1].setSize(Vector2f(sidelength * i, sidelength * i));
			squares[i - 1].setFillColor(Color::Transparent);
			squares[i - 1].setOutlineColor(Color::White);
			squares[i - 1].setOutlineThickness(5);

			if (i == 1) { squares[i - 1].setPosition(xPosition, yPosition);
			cout <<"first \n"<< xPosition << endl;
			cout << yPosition << endl;

			}
			else {
				xPosition = squares[i - 2].getPosition().x - 50;
				yPosition = squares[i - 2].getPosition().y - 50;
			squares[i - 1].setPosition(xPosition,yPosition);
			cout << "second \n" << xPosition << endl;
			cout << yPosition << endl;

			}

			


		
	}

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) { // keeps checking to see if the user closed the windo
			if (event.type == Event::Closed) {
				window.close(); // closes the window
			}
		}
		window.clear();
		for (int i = 0; i< numOfSquares; i++) {
			window.draw(squares[i]);
}
		window.display();
	}

}

int main() {
	squareSpiral();
	return 0;
}