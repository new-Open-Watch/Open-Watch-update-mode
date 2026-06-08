idf_component_register(SRCS "main.cpp"
                        REQUIRES driver fatfs sdmmc
                        PRIV_REQUIRES spi_flash
                        INCLUDE_DIRS "")

