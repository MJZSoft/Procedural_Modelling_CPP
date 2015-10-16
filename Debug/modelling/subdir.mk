################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../modelling/Angles.cpp \
../modelling/Circle.cpp \
../modelling/Color.cpp \
../modelling/Cone.cpp \
../modelling/Cube.cpp \
../modelling/Cylinder.cpp \
../modelling/Point.cpp \
../modelling/Primed.cpp \
../modelling/Quad.cpp \
../modelling/Shape.cpp \
../modelling/Sphere.cpp \
../modelling/Texture.cpp \
../modelling/Triangle.cpp \
../modelling/command.cpp \
../modelling/modeller.cpp \
../modelling/scope.cpp 

OBJS += \
./modelling/Angles.o \
./modelling/Circle.o \
./modelling/Color.o \
./modelling/Cone.o \
./modelling/Cube.o \
./modelling/Cylinder.o \
./modelling/Point.o \
./modelling/Primed.o \
./modelling/Quad.o \
./modelling/Shape.o \
./modelling/Sphere.o \
./modelling/Texture.o \
./modelling/Triangle.o \
./modelling/command.o \
./modelling/modeller.o \
./modelling/scope.o 

CPP_DEPS += \
./modelling/Angles.d \
./modelling/Circle.d \
./modelling/Color.d \
./modelling/Cone.d \
./modelling/Cube.d \
./modelling/Cylinder.d \
./modelling/Point.d \
./modelling/Primed.d \
./modelling/Quad.d \
./modelling/Shape.d \
./modelling/Sphere.d \
./modelling/Texture.d \
./modelling/Triangle.d \
./modelling/command.d \
./modelling/modeller.d \
./modelling/scope.d 


# Each subdirectory must supply rules for building sources it contributes
modelling/%.o: ../modelling/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


