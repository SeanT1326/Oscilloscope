#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>
#include <cstdio>

// Bring in C variables declared in main.c
extern "C" {
    extern int16_t display_buffer[100];
    extern volatile float currentVoltage;
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // Clear initial state
    waveGraph.clear();
    waveGraph.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateValue(int newValue)
{
    // Clear previous line data
    waveGraph.clear();

    // Add 100 new points from the display buffer
    for (int i = 0; i < 100; i++)
    {
        waveGraph.addDataPoint(display_buffer[i]);
    }

    // Force redraw of graph widget
    waveGraph.invalidate();

    // Update voltage readout text
    Unicode::snprintfFloat(
        textArea1Buffer,
        TEXTAREA1_SIZE,
        "%.2f V",
        currentVoltage
    );
    textArea1.invalidate();
}
