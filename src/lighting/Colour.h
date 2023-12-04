#include <stdio.h>
#include <iostream>

class Colour {
public:
    // Constructors
    Colour() : colour(0) {}
    Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        setRGBW(r, g, b, w);
    }

    // Setters
    void setRGBW(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        colour = (w << 24) | (r << 16) | (g << 8) | b;
    }

    void setR(uint8_t r) {
        colour = (colour & 0xFF00FFFF) | (static_cast<uint32_t>(r) << 16);
    }

    void setG(uint8_t g) {
        colour = (colour & 0xFFFF00FF) | (static_cast<uint32_t>(g) << 8);
    }

    void setB(uint8_t b) {
        colour = (colour & 0xFFFFFF00) | static_cast<uint32_t>(b);
    }

    void setW(uint8_t w) {
        colour = (colour & 0x00FFFFFF) | (static_cast<uint32_t>(w) << 24);
    }

    // Getters
    uint8_t getR() const {
        return static_cast<uint8_t>((colour >> 16) & 0xFF);
    }

    uint8_t getG() const {
        return static_cast<uint8_t>((colour >> 8) & 0xFF);
    }

    uint8_t getB() const {
        return static_cast<uint8_t>(colour & 0xFF);
    }

    uint8_t getW() const {
        return static_cast<uint8_t>((colour >> 24) & 0xFF);
    }

    // Display the RGBW values
    void display() const {
        std::cout << "R: " << static_cast<int>(getR()) << ", "
                  << "G: " << static_cast<int>(getG()) << ", "
                  << "B: " << static_cast<int>(getB()) << ", "
                  << "W: " << static_cast<int>(getW()) << std::endl;
    }

private:
    uint32_t colour;
};