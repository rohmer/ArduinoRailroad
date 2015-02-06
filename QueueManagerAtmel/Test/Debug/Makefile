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
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../MyClass.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
MyClass.o

OBJS_AS_ARGS +=  \
MyClass.o

C_DEPS +=  \
MyClass.d

C_DEPS_AS_ARGS +=  \
MyClass.d

OUTPUT_FILE_PATH +=Test.elf

OUTPUT_FILE_PATH_AS_ARGS +=Test.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
C:/Arduino/ArduinoRailroad/QueueManagerAtmel/arduinoCore/libcore.a \
C:/Arduino/ArduinoRailroad/QueueManagerAtmel/QueueManagerAtmel/Debug/libQueueManagerAtmel.a \
C:/Arduino/ArduinoRailroad/QueueManagerAtmel/stlport/Debug/libstlport.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -D__AVR_ATmega2560__ -DARDUINO=156 -DARDUINO_MAIN -DF_CPU=16000000L -D__AVR__  -I"c:/program files (x86)/arduino/hardware/tools/avr/lib/gcc/avr/4.3.2/include" -I"c:/program files (x86)/arduino/hardware/tools/avr/avr" -I"c:/program files (x86)/arduino/hardware/tools/avr/avr/include/avr" -I"c:/program files (x86)/arduino/hardware/tools/avr/avr/include" -I"c:/users/rohmer/Arduino/libraries/libraries" -I"c:/Program Files (x86)/Arduino/hardware/arduino/avr/libraries" -I"c:/Program Files (x86)/Arduino/libraries" -I"../../Test"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega2560 -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-static -Wl,-Map="Test.map" -Wl,--start-group -Wl,-lcore -Wl,-lQueueManagerAtmel -Wl,-lstlport  -Wl,--end-group -Wl,-L"C:\Arduino\ArduinoRailroad\QueueManagerAtmel\arduinoCore" -Wl,-L"C:\Arduino\ArduinoRailroad\QueueManagerAtmel\QueueManagerAtmel\Debug" -Wl,-L"C:\Arduino\ArduinoRailroad\QueueManagerAtmel\stlport\Debug"  -Wl,--gc-sections -mmcu=atmega2560 -Wl,--gc-sections  -Wl,-e,_trampoline,-nostartfiles,-sma  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Test.elf" "Test.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Test.elf" "Test.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Test.elf" > "Test.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Test.elf" "Test.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "Test.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Test.elf" "Test.a" "Test.hex" "Test.lss" "Test.eep" "Test.map" "Test.srec" "Test.usersignatures"
	