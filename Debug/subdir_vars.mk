################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../lnk_msp430fr5739.cmd 

CFG_SRCS += \
../main.cfg 

C_SRCS += \
../LM94022_temperature_sensor.c \
../MCP9700A_temp_sensor.c \
../TMP112_I2C_temperature_sensor.c \
../main.c 

OBJS += \
./LM94022_temperature_sensor.obj \
./MCP9700A_temp_sensor.obj \
./TMP112_I2C_temperature_sensor.obj \
./main.obj 

C_DEPS += \
./LM94022_temperature_sensor.pp \
./MCP9700A_temp_sensor.pp \
./TMP112_I2C_temperature_sensor.pp \
./main.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_OPTS += \
./configPkg/compiler.opt 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_FILES__QUOTED += \
"configPkg\linker.cmd" \
"configPkg\compiler.opt" 

GEN_MISC_DIRS__QUOTED += \
"configPkg\" 

C_DEPS__QUOTED += \
"LM94022_temperature_sensor.pp" \
"MCP9700A_temp_sensor.pp" \
"TMP112_I2C_temperature_sensor.pp" \
"main.pp" 

OBJS__QUOTED += \
"LM94022_temperature_sensor.obj" \
"MCP9700A_temp_sensor.obj" \
"TMP112_I2C_temperature_sensor.obj" \
"main.obj" 

C_SRCS__QUOTED += \
"../LM94022_temperature_sensor.c" \
"../MCP9700A_temp_sensor.c" \
"../TMP112_I2C_temperature_sensor.c" \
"../main.c" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 


