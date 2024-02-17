#include <SFML/Graphics.hpp> // sfml is a graphics libraary for 
#include <iostream>
#include <cstdlib> // allows me to access the system cmd functions such as clear 
using namespace sf;
using namespace std;

void squaresSpiral() {
	float screenWidth = 800;
	float screenHeight = 800;
	RenderWindow window(VideoMode(screenWidth, screenHeight), "squares Spiral Animation");
	window.setPosition(Vector2i(0, 0)); //
	const int numOfSquares = 25;
	float xPosition[numOfSquares];
	float yPosition[numOfSquares];
	float sidelength[numOfSquares];

	//float sidelength = 50;
	RectangleShape squares[numOfSquares];
	//RectangleShape squares;
	
	
	for (int i = 1; i <= numOfSquares; i++) {
		squares[i - 1].setFillColor(Color::Transparent);
		squares[i-1].setOutlineColor(Color::White);
		squares[i-1].setOutlineThickness(2);
		
		if (i == 1) {
			xPosition[i-1] = 350;
			yPosition[i-1] = 350;
			sidelength[i - 1] = 50;

		}
		else {
			xPosition[i - 1] = xPosition[i - 2] - 50;
			yPosition[i - 1] = yPosition[i - 2] - 50;
			sidelength[i - 1] = sidelength[i-2]+100;


		}
		squares[i-1].setSize(Vector2f(sidelength[i-1], sidelength[i-1]));
		squares[i-1].setPosition(Vector2f(xPosition[i-1], yPosition[i-1]));

	}
	while (window.isOpen()) {
		for (int i = 0; i < numOfSquares; i++) {
			squares[i].setSize(Vector2f(sidelength[i], sidelength[i]));
			squares[i].setPosition(Vector2f(xPosition[i], yPosition[i]));
			sidelength[i] += 0.02; //sidelength has to grow at double the rate of the x and y vertex
			xPosition[i] -= 0.01;
			yPosition[i] -= 0.01;

		}
		
		Event event;
		while (window.pollEvent(event)) { // keeps checking to see if the user closed the windo
			if (event.type == Event::Closed) {
				window.close(); // closes the window
			}
		}
		
		window.clear();
		/*for (int i = 0; i < numOfSquares; i++) {
			/*sidelength[i] *= 10;
			squares[i].setSize(Vector2f(sidelength[i], sidelength[i]));
			xPosition = squares[i].getPosition().x - 50;
			yPosition = squares[i].getPosition().y - 50;
			squares[i].setPosition(Vector2f(xPosition, yPosition));
			
			window.draw(squares[i]);
		}
		*/
		for (int i = 0; i < numOfSquares; i++) {
			window.draw(squares[i]);
}
		window.display();
	}

}

int main() {
	squaresSpiral();
	return 0;
}