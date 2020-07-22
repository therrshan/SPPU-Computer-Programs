################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/A6\ Chat\ Client.cpp \
../src/A6\ Chat\ Server.cpp 

OBJS += \
./src/A6\ Chat\ Client.o \
./src/A6\ Chat\ Server.o 

CPP_DEPS += \
./src/A6\ Chat\ Client.d \
./src/A6\ Chat\ Server.d 


# Each subdirectory must supply rules for building sources it contributes
src/A6\ Chat\ Client.o: ../src/A6\ Chat\ Client.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/A6 Chat Client.d" -MT"src/A6\ Chat\ Client.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/A6\ Chat\ Server.o: ../src/A6\ Chat\ Server.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/A6 Chat Server.d" -MT"src/A6\ Chat\ Server.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


