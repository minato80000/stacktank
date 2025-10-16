#pragma once
#include <Arduino.h>
volatile int targetDirection = 0; // -90(left) to +90(right)
void taskWheel(void *pvParameters)
{
    int crtDirection = 0;
    for (;;)
    {
        if (crtDirection != targetDirection)
        {
            if (crtDirection < targetDirection)
            {
                // turn right
                crtDirection++;
            }
            else
            {
                // turn left
                crtDirection--;
            }
            vTaskDelay(8 / portTICK_PERIOD_MS); // 8msで約1度動くので，8msごとに更新
        }
        else
        {
            vTaskDelay(10 / portTICK_PERIOD_MS); // 10msごとにチェック
        }
    }
};
