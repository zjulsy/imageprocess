################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/chapter3/Lsy310.cpp \
../src/chapter3/Lsy312.cpp \
../src/chapter3/Lsy314.cpp \
../src/chapter3/Lsy320.cpp \
../src/chapter3/Lsy326.cpp \
../src/chapter3/Lsy327.cpp \
../src/chapter3/Lsy33.cpp \
../src/chapter3/Lsy333.cpp \
../src/chapter3/Lsy334.cpp \
../src/chapter3/Lsy335.cpp \
../src/chapter3/Lsy338.cpp \
../src/chapter3/Lsy340.cpp \
../src/chapter3/Lsy342.cpp \
../src/chapter3/Lsy343.cpp \
../src/chapter3/Lsy35.cpp \
../src/chapter3/Lsy39.cpp 

OBJS += \
./src/chapter3/Lsy310.o \
./src/chapter3/Lsy312.o \
./src/chapter3/Lsy314.o \
./src/chapter3/Lsy320.o \
./src/chapter3/Lsy326.o \
./src/chapter3/Lsy327.o \
./src/chapter3/Lsy33.o \
./src/chapter3/Lsy333.o \
./src/chapter3/Lsy334.o \
./src/chapter3/Lsy335.o \
./src/chapter3/Lsy338.o \
./src/chapter3/Lsy340.o \
./src/chapter3/Lsy342.o \
./src/chapter3/Lsy343.o \
./src/chapter3/Lsy35.o \
./src/chapter3/Lsy39.o 

CPP_DEPS += \
./src/chapter3/Lsy310.d \
./src/chapter3/Lsy312.d \
./src/chapter3/Lsy314.d \
./src/chapter3/Lsy320.d \
./src/chapter3/Lsy326.d \
./src/chapter3/Lsy327.d \
./src/chapter3/Lsy33.d \
./src/chapter3/Lsy333.d \
./src/chapter3/Lsy334.d \
./src/chapter3/Lsy335.d \
./src/chapter3/Lsy338.d \
./src/chapter3/Lsy340.d \
./src/chapter3/Lsy342.d \
./src/chapter3/Lsy343.d \
./src/chapter3/Lsy35.d \
./src/chapter3/Lsy39.d 


# Each subdirectory must supply rules for building sources it contributes
src/chapter3/%.o: ../src/chapter3/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/opencv -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


