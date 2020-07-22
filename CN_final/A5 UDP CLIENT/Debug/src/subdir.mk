################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/A5\ UDP\ CLIENT.cpp 

OBJS += \
./src/A5\ UDP\ CLIENT.o 

CPP_DEPS += \
./src/A5\ UDP\ CLIENT.d 


# Each subdirectory must supply rules for building sources it contributes
src/A5\ UDP\ CLIENT.o: ../src/A5\ UDP\ CLIENT.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/A5 UDP CLIENT.d" -MT"src/A5\ UDP\ CLIENT.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


