################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/chapter4/Lsy442.cpp \
../src/chapter4/Lsy449.cpp 

OBJS += \
./src/chapter4/Lsy442.o \
./src/chapter4/Lsy449.o 

CPP_DEPS += \
./src/chapter4/Lsy442.d \
./src/chapter4/Lsy449.d 


# Each subdirectory must supply rules for building sources it contributes
src/chapter4/%.o: ../src/chapter4/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


