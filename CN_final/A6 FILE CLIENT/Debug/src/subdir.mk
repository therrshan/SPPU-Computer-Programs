################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/A6\ FILE\ CLIENT.cpp 

OBJS += \
./src/A6\ FILE\ CLIENT.o 

CPP_DEPS += \
./src/A6\ FILE\ CLIENT.d 


# Each subdirectory must supply rules for building sources it contributes
src/A6\ FILE\ CLIENT.o: ../src/A6\ FILE\ CLIENT.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/A6 FILE CLIENT.d" -MT"src/A6\ FILE\ CLIENT.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


