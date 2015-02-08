################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/config/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../PQueue.cpp \
../QueueManager.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
PQueue.o \
QueueManager.o

OBJS_AS_ARGS +=  \
PQueue.o \
QueueManager.o

C_DEPS +=  \
PQueue.d \
QueueManager.d

C_DEPS_AS_ARGS +=  \
PQueue.d \
QueueManager.d

OUTPUT_FILE_PATH +=libQueueManagerAtmel.a

OUTPUT_FILE_PATH_AS_ARGS +=libQueueManagerAtmel.a

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
../../arduinoCore/libcore.a \
C:/Users/Ron/Documents/ArduinoRailroad/QueueManagerAtmel/stlport/Debug/libstlport.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler





./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -D__AVR_ATmega2560__ -DARDUINO=156 -DARDUINO_MAIN -DF_CPU=16000000L -D__AVR__  -I"../../../ArduinoSrc/tools/avr/lib/gcc/avr/4.8.1/include" -I"../../../ArduinoSrc/tools/avr/avr/include" -I"../../../ArduinoSrc/tools/avr/avr/include/avr" -I"../../../ArduinoSrc/avr/libraries" -I"../../QueueManagerAtmel" -I"../../../ArduinoSrc/avr/variants/mega" -I"../../../ArduinoSrc/avr/cores/arduino" -I"../../../ArduinoLibraries/SoftwareSerial" -I"../../../ArduinoLibraries/SPI" -I"../../stlport"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -Wundef -pedantic -mmcu=atmega2560 -c -fno-exceptions -include Arduino.h -v -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)


$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Archiver : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-ar.exe$(QUOTE) -r  -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) 
	@echo Finished building target: $@
	
	




# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "libQueueManagerAtmel.elf" "libQueueManagerAtmel.a" "libQueueManagerAtmel.hex" "libQueueManagerAtmel.lss" "libQueueManagerAtmel.eep" "libQueueManagerAtmel.map" "libQueueManagerAtmel.srec" "libQueueManagerAtmel.usersignatures"
	