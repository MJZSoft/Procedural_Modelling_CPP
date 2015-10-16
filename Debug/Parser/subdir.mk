################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Parser/lexer.cpp \
../Parser/parser.cpp \
../Parser/scanner.cpp 

OBJS += \
./Parser/lexer.o \
./Parser/parser.o \
./Parser/scanner.o 

CPP_DEPS += \
./Parser/lexer.d \
./Parser/parser.d \
./Parser/scanner.d 


# Each subdirectory must supply rules for building sources it contributes
Parser/%.o: ../Parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


