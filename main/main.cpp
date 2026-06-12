#include <stdio.h>
#include "esp_system.h"
#include "driver/uart.h"
#include "owgl.h"
struct header
{
    uint8_t header = 227;
} hdr;
struct ack
{
    header h = hdr;
    bool ackSignal; // false = send again true = continue
} Ack;
struct updateReq
{
    uint16_t checksum;
    uint32_t updateLength; // in number of packets
} Request;
struct updatePkg
{
    uint32_t packetNumber;
    uint16_t checksum;
    uint8_t packet[1024];
};
void ackSignal()
{
}
uint16_t crc(const uint8_t *data, size_t len)
{
    uint16_t crc = 0xFFFF;
    for (size_t i = 0; i < len; i++)
    {
        crc ^= data[i];
        for (int j = 0; j < 8; j++)
            crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : (crc >> 1);
    }
    return crc;
}
extern "C" void app_main(void)
{
    init();
    uart_driver_install(
        UART_NUM_0,
        2048,
        1048,
        0,
        NULL,
        0);
    uint8_t buf[1026];

    while (1)
    {
        int len = uart_read_bytes(UART_NUM_0, buf, sizeof(buf) - 1,
                                  100 / portTICK_PERIOD_MS);

        if (len > 0)
        {
            if (len == 6)
            {
                Request.checksum = ((uint16_t)buf[0] << 8) | buf[1];
                Request.updateLength = (uint32_t)buf[2] | ((uint32_t)buf[3] << 8) | ((uint32_t)buf[4] << 16) | ((uint32_t)buf[5]);
            }
            buf[len] = 0;
            printf("recv: %s\n", (char *)buf);
        }
    }
}