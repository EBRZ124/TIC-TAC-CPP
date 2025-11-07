#pragma once
#include "raylib.h"

class Button {
public:
    Button();
    Button(const char* imagePath, Vector2 imagePosition, float scale);
    ~Button();

    void init(const char* imagePath, Vector2 imagePosition, float scale);
    void Draw();
    bool isPressed(Vector2 mousePos, bool mousePressed);

    // Optional helpers
    Vector2 getPosition() const { return position; }
    float getWidth() const { return static_cast<float>(texture.width); }
    float getHeight() const { return static_cast<float>(texture.height); }

private:
    Texture2D texture;
    Vector2 position;
};
