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
	float xPosition = 350;
	float yPosition = 350;
	const int numOfSquares = 13;
	//float sidelength[numOfSquares];
	float sidelength = 50;
	RectangleShape squares[numOfSquares];
	//RectangleShape squares;
	
	


	
	/*for (int i = 1; i <= numOfSquares; i++) {
			squaress[i-1].setSize(Vector2f(sidelength * i, sidelength * i));
			squaress[i - 1].setFillColor(Color::Transparent);
			squaress[i - 1].setOutlineColor(Color::White);
			squaress[i - 1].setOutlineThickness(5);

			if (i == 1) { squaress[i - 1].setPosition(xPosition, yPosition);
			cout <<"first \n"<< xPosition << endl;
			cout << yPosition << endl;

			}
			else {
				xPosition = squaress[i - 2].getPosition().x - 50;
				yPosition = squaress[i - 2].getPosition().y - 50;
			squaress[i - 1].setPosition(xPosition,yPosition);
			cout << "second \n" << xPosition << endl;
			cout << yPosition << endl;

			}
			*/
			
	/*
	for (int i = 0; i < numOfSquares; i++) {
		sidelength[i] = 50;
		squares[i].setSize(Vector2f(sidelength[i], sidelength[i]));
		squares[i].setOutlineThickness(5);
		squares[i].setFillColor(Color::Transparent);
		squares[i].setOutlineColor(Color::White);
		squares[i].setPosition(xPosition, yPosition);
	}*/
		
	RectangleShape square;
	

	square.setFillColor(Color::Transparent);
	square.setOutlineColor(Color::White);
	square.setOutlineThickness(2);

	while (window.isOpen()) {
		square.setSize(Vector2f(sidelength, sidelength));
		square.setPosition(Vector2f(xPosition, yPosition));
		sidelength += 0.02; //sidelength has to grow at double the rate of the x and y vertex
		xPosition -= 0.01;
		yPosition -= 0.01;
		
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
		window.draw(square);
		
		window.display();
	}

}

int main() {
	squaresSpiral();
	return 0;
}