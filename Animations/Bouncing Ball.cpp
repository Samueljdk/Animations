#include <SFML/Graphics.hpp> // sfml is a graphics libraary for drawing the shapes
#include <iostream>
#include <cstdlib> // allows me to access the system cmd functions such as clear 
using namespace sf;
using namespace std;

void bouncingBall() {
 
     int screenWidth = 600;
     int screenHeight = 600;
     RenderWindow window(VideoMode(screenWidth,screenHeight), "Bouncing Ball Animation");
     float horizontalPosition = 0;
     float verticalPosition =0;
     float hChange = 0;
     float vChange = 0;
     // drawing the circle

     CircleShape circle(50); // radius of 50
     
     bool stopBouncing = false;
     while (!stopBouncing && window.isOpen()) {
         hChange += 0.01;
         vChange += 0.01;
         circle.setPosition(horizontalPosition+hChange, (horizontalPosition*(-1)+vChange)); // position on the window

         
         
         Event event;
         while (window.pollEvent(event)) { // keeps checking to see if the user closed the windo
             if (event.type == Event::Closed) {
                 window.close(); // closes the window
             }
         }
         

         
       
        window.clear(); // clears the window to prepare to make the next ball drawing
        window.draw(circle); // draws the ball
        window.display(); // displays the ball
    }

}

int main() {
    bouncingBall();
    /*bool stopMenu = false;
    int choice = 0;
    while (!stopMenu) {
        cout << "Welcome to the animations program \n";
        cout << "Enter 1 to see the bouncing ball animation \n";
        cout << "Enter any other value to exit \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bouncingBall();
            system("cls"); // clears the screen so that the menu can be displayed on the same spot


            break;
        default:
            stopMenu = true;

            break;
        }

    }*/
    
    return 0;
}
