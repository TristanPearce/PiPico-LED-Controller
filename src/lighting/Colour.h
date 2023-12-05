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
    Colour() : colour_grbw(0) {}
    Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        setRGBW(r, g, b, w);
    }

    // Setters
    void setRGBW(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        colour_grbw = (static_cast<uint32_t>(g) << GREEN_OFFSET) | (static_cast<uint32_t>(r) << RED_OFFSET) | static_cast<uint32_t>(b) << BLUE_OFFSET;
    }

    void setR(uint8_t r) {
        colour_grbw = (colour_grbw & 0xFFFF00FF) | (static_cast<uint32_t>(r) << RED_OFFSET);
    }

    void setG(uint8_t g) {
        colour_grbw = (colour_grbw & 0xFF00FFFF) | (static_cast<uint32_t>(g) << GREEN_OFFSET);
    }

    void setB(uint8_t b) {
        colour_grbw = (colour_grbw & 0xFFFFFF00) | (static_cast<uint32_t>(b) << BLUE_OFFSET);
    }

    void setW(uint8_t w) {
        colour_grbw = (colour_grbw & 0x00FFFFFF) | (static_cast<uint32_t>(w) << WHITE_OFFSET);
    }

    // Getters
    uint8_t getR() const {
        return static_cast<uint8_t>((colour_grbw >> RED_OFFSET) & 0xFF);
    }

    uint8_t getG() const {
        return static_cast<uint8_t>((colour_grbw >> GREEN_OFFSET) & 0xFF);
    }

    uint8_t getB() const {
        return static_cast<uint8_t>(colour_grbw >> BLUE_OFFSET& 0xFF);
    }

    uint8_t getW() const {
        return static_cast<uint8_t>((colour_grbw >> WHITE_OFFSET) & 0xFF);
    }

    // Display the RGBW values
    void display() const {
        std::cout << "R: " << static_cast<int>(getR()) << ", "
                  << "G: " << static_cast<int>(getG()) << ", "
                  << "B: " << static_cast<int>(getB()) << ", "
                  << "W: " << static_cast<int>(getW()) << std::endl;
    }

    explicit operator uint32_t() const {
        return colour_grbw;
    }

    // FLOATING POINT HELPERS


    void setRFloat(float r) {
        colour_grbw = (colour_grbw & 0xFFFF00FF) | (static_cast<uint32_t>(r) << RED_OFFSET);
    }

    void setGFloat(float g) {
        colour_grbw = (colour_grbw & 0xFF00FFFF) | (static_cast<uint32_t>(g) << GREEN_OFFSET);
    }

    void setBFloat(float b) {
        colour_grbw = (colour_grbw & 0xFFFFFF00) | (static_cast<uint32_t>(b) << BLUE_OFFSET);
    }

    void setWFloat(float w) {
        colour_grbw = (colour_grbw & 0x00FFFFFF) | (static_cast<uint32_t>(w) << WHITE_OFFSET);
    }

    // Getters
    float getRFloat() const {
        return (static_cast<uint8_t>((colour_grbw >> RED_OFFSET) & 0xFF) / 255.0f);
    }

    float getGFloat() const {
        return (static_cast<uint8_t>((colour_grbw >> GREEN_OFFSET) & 0xFF) / 255.0f);
    }

    float getBFloat() const {
        return (static_cast<uint8_t>(colour_grbw >> BLUE_OFFSET& 0xFF) / 255.0f);
    }

    float getWFloat() const {
        return (static_cast<uint8_t>((colour_grbw >> WHITE_OFFSET) & 0xFF) / 255.0f);
    }

    static const Colour RED;
    static const Colour GREEN;
    static const Colour BLUE;
    static const Colour BLACK;
    static const Colour WHITE;
    static const Colour GRAY;
    static const Colour SILVER;
    static const Colour MAROON;
    static const Colour YELLOW;
    static const Colour OLIVE;
    static const Colour NAVY;
    static const Colour PURPLE;
    static const Colour TEAL;
    static const Colour FUCHSIA;
    static const Colour AQUA;
    static const Colour LIME;

private:
    /// @brief Colour in Green - Red - Blue - White (8-bits per)
    uint32_t colour_grbw;
};