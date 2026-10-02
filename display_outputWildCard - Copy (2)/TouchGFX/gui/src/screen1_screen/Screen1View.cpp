#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Utils.hpp>
#include <cstdio> // Required for snprintf

extern "C" {
    extern int16_t sine_wave[];
}

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // Clear default graph points
    waveGraph.clear();

    // Load all 100 points of the sine wave into the graph
    for (int i = 0; i < 100; i++)
    {
        waveGraph.addDataPoint(sine_wave[i]);
    }

    // Force the graph to repaint on screen
    waveGraph.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateValue(int newValue)
{
    float voltage = 2.0f;

    Unicode::snprintfFloat(
        textArea1Buffer,
        TEXTAREA1_SIZE,
        "%.2f V",
        voltage
    );

    textArea1.invalidate();
}
