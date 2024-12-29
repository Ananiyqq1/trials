#include <SFML/Graphics.hpp>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Circle Example");

    // Create a circle shape
    sf::CircleShape circle(50); // Radius of 50
    circle.setFillColor(sf::Color::Green); // Set color to green
    circle.setPosition(375, 275); // Start position in the center

    // Variables for bouncing animation
    float speed = 0.5f; // Speed of the bounce
    float direction = 1.0f; // 1 for down, -1 for up

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window when requested
            }
        }

        // Update circle position for bouncing effect
        float newY = circle.getPosition().y + speed * direction;

        // Check boundaries and reverse direction if needed
        if (newY >= 500) { // Bottom boundary (600 - radius)
            newY = 500; // Keep it within bounds
            direction = -1.0f; // Change direction to up
        } else if (newY <= 225) { // Top boundary (0 + radius)
            newY = 225; // Keep it within bounds
            direction = 1.0f; // Change direction to down
        }

        circle.setPosition(375, newY); // Update circle's Y position

        window.clear(); // Clear the window with black color
        window.draw(circle); // Draw the circle
        window.display(); // Display what has been drawn
    }

    return 0;
}

