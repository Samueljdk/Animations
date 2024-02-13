#include <SFML/Graphics.hpp> // sfml is a graphics libraary for drawing the shapes
#include <iostream>
#include <cstdlib> // allows me to access the system cmd functions such as clear 
using namespace sf;
using namespace std;

void bouncingBall() {
    /*VideoMode desktopMode = VideoMode::getDesktopMode();
    int screenWidth = desktopMode.width;
    int screenHeight = desktopMode.height;*/
    
    int screenWidth = 600;
    int screenHeight = 600;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "Bouncing Ball Animation");
    window.setPosition(Vector2i(0, 0)); // sets the position of the window at top left corner
   
    /*
     float horizontalPosition = static_cast<float>(screenWidth-100);
     float verticalPosition = static_cast<float>(screenHeight - 100);*/
     float horizontalPosition = 0;
     float verticalPosition = 0;
     float hChange = 0;
     float vChange = 0;
     float slope = 1;
     // drawing the circle

     CircleShape circle(50); // radius of 50
     
     bool stopBouncing = false;
     while (!stopBouncing && window.isOpen()) {
         if (verticalPosition >= 500) {
             vChange -= 0.001;

         }
         else if (verticalPosition<=100){
             vChange += 0.001;

         }
       //  hChange += 0.001;
         
         horizontalPosition = horizontalPosition + hChange;
         verticalPosition =verticalPosition * slope + vChange;
        circle.setPosition(horizontalPosition,verticalPosition); // position on the window
        // circle.setPosition(horizontalPosition, verticalPosition);
         
         
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
