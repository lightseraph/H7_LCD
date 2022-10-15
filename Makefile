##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.17.1] date: [Sat Oct 15 05:42:47 EDT 2022] 
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = H7_LCD


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
Core/Src/main.c \
Core/Src/gpio.c \
Core/Src/fmc.c \
Core/Src/stm32h7xx_it.c \
Core/Src/stm32h7xx_hal_msp.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_fmc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sdram.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c \
Core/Src/system_stm32h7xx.c \
Core/Src/quadspi.c \
Core/Src/rtc.c \
Core/Src/tim.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_qspi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rtc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rtc_ex.c \
Core/Src/jpeg.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_jpeg.c \
Utilities/JPEG/jpeg_utils.c \
Core/Src/spi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_nand.c \
Core/Src/ltdc.c \
Core/Src/usart.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ltdc.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ltdc_ex.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c \
LIBJPEG/App/libjpeg.c \
Middlewares/Third_Party/LibJPEG/source/jcapimin.c \
Middlewares/Third_Party/LibJPEG/source/jcapistd.c \
Middlewares/Third_Party/LibJPEG/source/jdapimin.c \
Middlewares/Third_Party/LibJPEG/source/jdapistd.c \
Middlewares/Third_Party/LibJPEG/source/jcomapi.c \
Middlewares/Third_Party/LibJPEG/source/jcparam.c \
Middlewares/Third_Party/LibJPEG/source/jctrans.c \
Middlewares/Third_Party/LibJPEG/source/jdtrans.c \
Middlewares/Third_Party/LibJPEG/source/jcinit.c \
Middlewares/Third_Party/LibJPEG/source/jcmaster.c \
Middlewares/Third_Party/LibJPEG/source/jcmainct.c \
Middlewares/Third_Party/LibJPEG/source/jcprepct.c \
Middlewares/Third_Party/LibJPEG/source/jccoefct.c \
Middlewares/Third_Party/LibJPEG/source/jccolor.c \
Middlewares/Third_Party/LibJPEG/source/jcsample.c \
Middlewares/Third_Party/LibJPEG/source/jcdctmgr.c \
Middlewares/Third_Party/LibJPEG/source/jfdctint.c \
Middlewares/Third_Party/LibJPEG/source/jfdctfst.c \
Middlewares/Third_Party/LibJPEG/source/jfdctflt.c \
Middlewares/Third_Party/LibJPEG/source/jchuff.c \
Middlewares/Third_Party/LibJPEG/source/jcarith.c \
Middlewares/Third_Party/LibJPEG/source/jcmarker.c \
Middlewares/Third_Party/LibJPEG/source/jdatadst.c \
Middlewares/Third_Party/LibJPEG/source/jdmaster.c \
Middlewares/Third_Party/LibJPEG/source/jdinput.c \
Middlewares/Third_Party/LibJPEG/source/jdmainct.c \
Middlewares/Third_Party/LibJPEG/source/jdcoefct.c \
Middlewares/Third_Party/LibJPEG/source/jdpostct.c \
Middlewares/Third_Party/LibJPEG/source/jdmarker.c \
Middlewares/Third_Party/LibJPEG/source/jdhuff.c \
Middlewares/Third_Party/LibJPEG/source/jdarith.c \
Middlewares/Third_Party/LibJPEG/source/jddctmgr.c \
Middlewares/Third_Party/LibJPEG/source/jidctint.c \
Middlewares/Third_Party/LibJPEG/source/jidctfst.c \
Middlewares/Third_Party/LibJPEG/source/jidctflt.c \
Middlewares/Third_Party/LibJPEG/source/jdsample.c \
Middlewares/Third_Party/LibJPEG/source/jdcolor.c \
Middlewares/Third_Party/LibJPEG/source/jdmerge.c \
Middlewares/Third_Party/LibJPEG/source/jquant1.c \
Middlewares/Third_Party/LibJPEG/source/jquant2.c \
Middlewares/Third_Party/LibJPEG/source/jdatasrc.c \
Middlewares/Third_Party/LibJPEG/source/jaricom.c \
Middlewares/Third_Party/LibJPEG/source/jerror.c \
Middlewares/Third_Party/LibJPEG/source/jmemmgr.c \
Middlewares/Third_Party/LibJPEG/source/jutils.c \
Middlewares/Third_Party/LibJPEG/source/jmemnobs.c \
Core/Src/dma2d.c \
Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma2d.c

# ASM sources
ASM_SOURCES =  \
startup_stm32h750xx.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m7

# fpu
FPU = -mfpu=fpv5-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32H750xx


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-ICore/Inc \
-IDrivers/STM32H7xx_HAL_Driver/Inc \
-IDrivers/STM32H7xx_HAL_Driver/Inc/Legacy \
-IDrivers/CMSIS/Device/ST/STM32H7xx/Include \
-IDrivers/CMSIS/Include \
-IUtilities/JPEG \
-ILIBJPEG/App \
-ILIBJPEG/Target \
-IMiddlewares/Third_Party/LibJPEG/include


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS += $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32H750XBHx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
