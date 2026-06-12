idf_component_register(SRCS "main.cpp"
                        REQUIRES owgl driver esp_driver_uart
                        PRIV_REQUIRES spi_flash
                        INCLUDE_DIRS "")
