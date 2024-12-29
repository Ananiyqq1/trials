#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Circle with Keyboard Control");

    // Create a circle shape
    sf::CircleShape circle(25); // Radius of 25
    circle.setFillColor(sf::Color::Green); // Set color to green
    circle.setPosition(100, 275); // Start position

    // Variables for bouncing animation
    float speed = 5.0f; // Speed of the bounce
    float gravity = 0.5f; // Gravity effect
    float velocity = 0.0f; // Vertical velocity

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window when requested
            }
        }

        // Handle keyboard input for moving the circle up or down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            velocity = -speed; // Move up when Up arrow is pressed
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            velocity = speed; // Move down when Down arrow is pressed
        } else {
            velocity += gravity; // Apply gravity when no key is pressed
        }

        // Update circle position based on velocity
        float newY = circle.getPosition().y + velocity;

        // Keep within window bounds
        if (newY >= 600 - circle.getRadius() * 2) { // Bottom boundary
            newY = 600 - circle.getRadius() * 2; // Keep it within bounds
            velocity = 0; // Stop falling when hitting the bottom
        } else if (newY <= 0) { // Top boundary
            newY = 0; // Keep it within bounds
            velocity = 0; // Stop rising when hitting the top
        }

        circle.setPosition(100, newY); // Update circle's Y position

        window.clear(); // Clear the window with black color
        window.draw(circle); // Draw the circle (the bird)
        window.display();     // Display what has been drawn
    }

    return 0;
}

