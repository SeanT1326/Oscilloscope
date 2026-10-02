#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "cmsis_os.h"//gives access to osMessageQueueGet

extern osMessageQueueId_t guiQueueHandle;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    int receivedValue = 0;

    // Check if a message is available in the queue without blocking
    if (osMessageQueueGet(guiQueueHandle, &receivedValue, NULL, 0) == osOK)
    {
        // Notify the active screen presenter
        if (modelListener != nullptr)
        {
            modelListener->onValueUpdated(receivedValue);
        }
    }
}
