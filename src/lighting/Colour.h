#pragma once

#include <stdio.h>
#include <iostream>

#define GREEN_OFFSET 16
#define RED_OFFSET 8
#define BLUE_OFFSET 0
#define WHITE_OFFSET 24

struct Colour {
public:
    // Constructors
    Colour() : colour(0) {}
    Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        setRGBW(r, g, b, w);
    }

    // Setters
    void setRGBW(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        colour = (static_cast<uint32_t>(g) << GREEN_OFFSET) | (static_cast<uint32_t>(r) << RED_OFFSET) | static_cast<uint32_t>(b) << BLUE_OFFSET;
    }

    void setR(uint8_t r) {
        colour = (colour & 0xFFFF00FF) | (static_cast<uint32_t>(r) << RED_OFFSET);
    }

    void setG(uint8_t g) {
        colour = (colour & 0xFF00FFFF) | (static_cast<uint32_t>(g) << GREEN_OFFSET);
    }

    void setB(uint8_t b) {
        colour = (colour & 0xFFFFFF00) | static_cast<uint32_t>(b) << BLUE_OFFSET;
    }

    void setW(uint8_t w) {
        colour = (colour & 0x00FFFFFF) | (static_cast<uint32_t>(w) << WHITE_OFFSET);
    }

    // Getters
    uint8_t getR() const {
        return static_cast<uint8_t>((colour >> RED_OFFSET) & 0xFF);
    }

    uint8_t getG() const {
        return static_cast<uint8_t>((colour >> GREEN_OFFSET) & 0xFF);
    }

    uint8_t getB() const {
        return static_cast<uint8_t>(colour >> BLUE_OFFSET& 0xFF);
    }

    uint8_t getW() const {
        return static_cast<uint8_t>((colour >> WHITE_OFFSET) & 0xFF);
    }

    // Display the RGBW values
    void display() const {
        std::cout << "R: " << static_cast<int>(getR()) << ", "
                  << "G: " << static_cast<int>(getG()) << ", "
                  << "B: " << static_cast<int>(getB()) << ", "
                  << "W: " << static_cast<int>(getW()) << std::endl;
    }

    explicit operator uint32_t() const {
        return colour;
    }

private:
    uint32_t colour;
};