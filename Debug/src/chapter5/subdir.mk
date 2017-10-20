################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/chapter5/Lsy54.cpp 

OBJS += \
./src/chapter5/Lsy54.o 

CPP_DEPS += \
./src/chapter5/Lsy54.d 


# Each subdirectory must supply rules for building sources it contributes
src/chapter5/%.o: ../src/chapter5/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


