#include <SFML/Graphics.hpp> // sfml is a graphics libraary for 
#include <iostream>
using namespace sf;
using namespace std;

void squaresSpiral() {
	//setting the window dimensions and title
	const float windowWidth = 800;
	const float windowHeight = 800;
	RenderWindow window(VideoMode(windowWidth, windowHeight), "squares Spiral Animation");
	window.setPosition(Vector2i(0, 0)); // placing the window at the top left corner of the screen
	
	//setting the number of squares
	const int numOfSquares = 25;
	//arrays to hold the characteristics of the squares
	float xPosition[numOfSquares]; // array of x positions
	float yPosition[numOfSquares]; // array of y positions
	float sidelength[numOfSquares]; // array of sides

	//array of squares
	RectangleShape squares[numOfSquares];
	
	/*going through the array to set the characterisitcs of the squares
	the counter i starts from 1 and we use i-1 to refer to each square
	in relation to the square before it.
	
	At the first square, the dimensions are set by me,
	at subsequent squares, the dimensions will be calculated in relation to the 
	dimensions of previous squares
	*/
	for (int i = 1; i <= numOfSquares; i++) {
		//characteristics that all the squares will have
		squares[i - 1].setFillColor(Color::Transparent);
		squares[i-1].setOutlineColor(Color::White);
		squares[i-1].setOutlineThickness(2);
		
		// initial characterisitics of the first square
		if (i == 1) {
			xPosition[i-1] = 350;
			yPosition[i-1] = 350;
			sidelength[i - 1] = 50;

		}
		//characteristics of subsequent squares
		else {
	/*the x and y positions go to the left at 50 pixels in relation to the
	previous square*/
			xPosition[i - 1] = xPosition[i - 2] - 50;
			yPosition[i - 1] = yPosition[i - 2] - 50;
			
	/*the sidelength of each square has to increase by 100
	pixels to make sure the previous square fits inside of the current square
	*/
			sidelength[i - 1] = sidelength[i-2]+100;

		}

		//setting the characterists mentioned above for all squares
		squares[i-1].setSize(Vector2f(sidelength[i-1], sidelength[i-1]));
		squares[i-1].setPosition(Vector2f(xPosition[i-1], yPosition[i-1]));

	}

	while (window.isOpen()) {
// a second for loop to update the dimensions at every iteration

		for (int i = 0; i < numOfSquares; i++) {
			squares[i].setSize(Vector2f(sidelength[i], sidelength[i]));
			squares[i].setPosition(Vector2f(xPosition[i], yPosition[i]));
		
			sidelength[i] += 0.02; //sidelength has to grow at double the rate of the x and y vertex
			xPosition[i] -= 0.01;
			yPosition[i] -= 0.01;

		}
		
		// keeps checking to see if the user closed the window
		Event event;
		while (window.pollEvent(event)) { 
			if (event.type == Event::Closed) {
				window.close(); // closes the window
			}
		}
		
		window.clear();
		
// drawing the squares in the squares array
		for (int i = 0; i < numOfSquares; i++) {
			window.draw(squares[i]);
}
		window.display(); // displays the window
	}

}

int main() {
	squaresSpiral();
	return 0;
}