################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Modeller/Angles.cpp \
../Modeller/Circle.cpp \
../Modeller/Color.cpp \
../Modeller/Cone.cpp \
../Modeller/Cube.cpp \
../Modeller/Cylinder.cpp \
../Modeller/Point.cpp \
../Modeller/Primed.cpp \
../Modeller/Quad.cpp \
../Modeller/Shape.cpp \
../Modeller/Sphere.cpp \
../Modeller/Texture.cpp \
../Modeller/Triangle.cpp \
../Modeller/command.cpp \
../Modeller/modeller.cpp \
../Modeller/scope.cpp 

OBJS += \
./Modeller/Angles.o \
./Modeller/Circle.o \
./Modeller/Color.o \
./Modeller/Cone.o \
./Modeller/Cube.o \
./Modeller/Cylinder.o \
./Modeller/Point.o \
./Modeller/Primed.o \
./Modeller/Quad.o \
./Modeller/Shape.o \
./Modeller/Sphere.o \
./Modeller/Texture.o \
./Modeller/Triangle.o \
./Modeller/command.o \
./Modeller/modeller.o \
./Modeller/scope.o 

CPP_DEPS += \
./Modeller/Angles.d \
./Modeller/Circle.d \
./Modeller/Color.d \
./Modeller/Cone.d \
./Modeller/Cube.d \
./Modeller/Cylinder.d \
./Modeller/Point.d \
./Modeller/Primed.d \
./Modeller/Quad.d \
./Modeller/Shape.d \
./Modeller/Sphere.d \
./Modeller/Texture.d \
./Modeller/Triangle.d \
./Modeller/command.d \
./Modeller/modeller.d \
./Modeller/scope.d 


# Each subdirectory must supply rules for building sources it contributes
Modeller/%.o: ../Modeller/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


