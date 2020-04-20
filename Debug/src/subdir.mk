################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LibwebsocketsExample.c \
../src/ProtocolWebsocket.c 

OBJS += \
./src/LibwebsocketsExample.o \
./src/ProtocolWebsocket.o 

C_DEPS += \
./src/LibwebsocketsExample.d \
./src/ProtocolWebsocket.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


