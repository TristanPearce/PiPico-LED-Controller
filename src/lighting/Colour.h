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
    Colour() : colour_wgrb(0) {}
    Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        setRGBW(r, g, b, w);
    }

    #pragma region BYTE METHODS

    // Setters
    void setRGBW(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
        colour_wgrb = (static_cast<uint32_t>(g) << GREEN_OFFSET) | (static_cast<uint32_t>(r) << RED_OFFSET) | static_cast<uint32_t>(b) << BLUE_OFFSET | static_cast<uint32_t>(w) << WHITE_OFFSET;
    }

    void setR(uint8_t r) {
        colour_wgrb = (colour_wgrb & 0xFFFF00FF) | (static_cast<uint32_t>(r) << RED_OFFSET);
    }

    void setG(uint8_t g) {
        colour_wgrb = (colour_wgrb & 0xFF00FFFF) | (static_cast<uint32_t>(g) << GREEN_OFFSET);
    }

    void setB(uint8_t b) {
        colour_wgrb = (colour_wgrb & 0xFFFFFF00) | (static_cast<uint32_t>(b) << BLUE_OFFSET);
    }

    void setW(uint8_t w) {
        colour_wgrb = (colour_wgrb & 0x00FFFFFF) | (static_cast<uint32_t>(w) << WHITE_OFFSET);
    }

    // Getters
    uint8_t getR() const {
        return static_cast<uint8_t>((colour_wgrb >> RED_OFFSET) & 0xFF);
    }

    uint8_t getG() const {
        return static_cast<uint8_t>((colour_wgrb >> GREEN_OFFSET) & 0xFF);
    }

    uint8_t getB() const {
        return static_cast<uint8_t>((colour_wgrb >> BLUE_OFFSET) & 0xFF);
    }

    uint8_t getW() const {
        return static_cast<uint8_t>((colour_wgrb >> WHITE_OFFSET) & 0xFF);
    }

    #pragma endregion



    #pragma region FLOATING METHODS

    void setRFloat(float r) {
        colour_wgrb = (colour_wgrb & 0xFFFF00FF) | (static_cast<uint32_t>(r) << RED_OFFSET);
    }

    void setGFloat(float g) {
        colour_wgrb = (colour_wgrb & 0xFF00FFFF) | (static_cast<uint32_t>(g) << GREEN_OFFSET);
    }

    void setBFloat(float b) {
        colour_wgrb = (colour_wgrb & 0xFFFFFF00) | (static_cast<uint32_t>(b) << BLUE_OFFSET);
    }

    void setWFloat(float w) {
        colour_wgrb = (colour_wgrb & 0x00FFFFFF) | (static_cast<uint32_t>(w) << WHITE_OFFSET);
    }

    // Getters
    float getRFloat() const {
        return (static_cast<uint8_t>((colour_wgrb >> RED_OFFSET) & 0xFF) / 255.0f);
    }

    float getGFloat() const {
        return (static_cast<uint8_t>((colour_wgrb >> GREEN_OFFSET) & 0xFF) / 255.0f);
    }

    float getBFloat() const {
        return (static_cast<uint8_t>(colour_wgrb >> BLUE_OFFSET& 0xFF) / 255.0f);
    }

    float getWFloat() const {
        return (static_cast<uint8_t>((colour_wgrb >> WHITE_OFFSET) & 0xFF) / 255.0f);
    }

    #pragma endregion



    #pragma region OPERATORS

    explicit operator uint32_t() const {
        return colour_wgrb;
    }

    // Overload * operator for uint8_t scalar
    Colour operator*(uint8_t scalar) const {
        Colour result = *this;
        result.setR(result.getR() * scalar / 255);
        result.setG(result.getG() * scalar / 255);
        result.setB(result.getB() * scalar / 255);
        result.setW(result.getW() * scalar / 255);
        return result;
    }

    // Scale a colour by a value between 0 and 1
    Colour operator*(float scalar) const {
        Colour result = Colour(
            (this->getRFloat() * scalar),
            (this->getGFloat() * scalar),
            (this->getBFloat() * scalar),
            (this->getWFloat() * scalar));
        return result;
    }

    // Average 2 colours
    Colour operator+(Colour other) const {
        Colour result = Colour(
            (this->getR() + other.getR() / 2),
            (this->getG() + other.getG() / 2),
            (this->getB() + other.getB() / 2),
            (this->getW() + other.getW() / 2));
        return result;
    }

    #pragma endregion



    #pragma region PRESET COLOURS

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

    #pragma endregion

private:
    /// @brief Colour in Green - Red - Blue - White (8-bits per)
    uint32_t colour_wgrb;
};