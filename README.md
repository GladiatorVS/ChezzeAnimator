# ChezzeAnimator

**ChezzeAnimator** is a lightweight, header-based C++ class for animating `float` values using a wide selection of easing functions. It is well-suited for UI animations (e.g., ImGui) or general-purpose use without any external dependencies.

---

## Features

- Supports 20+ easing functions (Linear, Quadratic, Cubic, Quartic, Quintic, Sine, Expo, Circular, etc.)
- Simple and efficient API: `start()`, `stop()`, `update()`
- Custom callback upon animation completion
- Dynamically adjustable speed, easing type, and destination value
- Based solely on the C++ Standard Library

---

## Constructor

```cpp
ChezzeAnimator(
    float* value,            // Pointer to the float to animate
    float to,                // Target value
    AnimType anim,           // Easing type
    float durationMs         // Animation duration in milliseconds
);
```

---

## Public Methods

### Control

```cpp
void start();               // Starts the animation
void stop();                // Stops the animation
void update();              // Updates the animation (should be called per frame)

bool isStarted();           // Returns true if animation is running
```

### Configuration

```cpp
void setToValue(float to);
void setToValue(float to, AnimType anim);
void setStartValue(float value);
void setType(AnimType type);
void setSpeed(float durationMs);

void setCompleteCallback(std::function<void()> callback);
```

---

## Easing Types

The `AnimType` enum includes the following easing functions:

```cpp
enum AnimType {
    Linear,
    InQuad, OutQuad, InOutQuad,
    InCubic, OutCubic, InOutCubic,
    InQuart, OutQuart, InOutQuart,
    InQuint, OutQuint, InOutQuint,
    InSine, OutSine, InOutSine,
    InExpo, OutExpo, InOutExpo,
    InCirc, OutCirc, InOutCirc
};
```

Easing functions are defined externally in `easing.h` and referenced via a static table.

---

## Usage Example (with ImGui)

```cpp
static float size = 50;
static ChezzeAnimator animator(&size, 200, ChezzeAnimator::InOutQuad, 1000);

if (ImGui::Button("Start"))
    animator.start();

animator.update();
ImGui::Button("Animated", {size, size});
```

For a complete set of examples, refer to the `example\example2\ui.h` file.

---

## Integration Notes

- C++17 or higher is required (C++20 recommended for `std::lerp`)
- Only uses standard headers: `<chrono>`, `<functional>`, `<array>`

---

## File Structure

```
Animator.h       // Main class definition
Animator.cpp     // Class implementation
easing.h         // Easing functions
```

---

## License

MIT License. Free for use in personal and commercial projects with attribution.
