#include <driver/i2s.h>
#include "Define.h" 
#include "Audio.h"

i2s_config_t i2s_config;
i2s_pin_config_t pin_config;

void I2S_Audio_Init()
{
  i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 8000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 16,
    .dma_buf_len = 256,
    .use_apll = false
  };

  pin_config = {
    .bck_io_num = Audio_BCK,        // Bit Clock
    .ws_io_num = Audio_WS,          // Word Select
    .data_out_num = Audio_Data_Out, // Data Out
    .data_in_num = I2S_PIN_NO_CHANGE
  };
}

void I2S_Audio_Driver_Start()
{
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config); 
}

void I2S_Audio_Driver_Stop()
{
  i2s_driver_uninstall(I2S_NUM_0);
}

void Audio_Write()
{
  size_t bytes_written;
  
  I2S_Audio_Driver_Start();
  i2s_write(I2S_NUM_0, rawData, sizeof(rawData), &bytes_written, portMAX_DELAY);
  i2s_zero_dma_buffer(I2S_NUM_0);
  I2S_Audio_Driver_Stop();
}
