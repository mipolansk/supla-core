################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/vbt/abstract_vbt_condition.cpp \
../src/vbt/value_based_trigger.cpp \
../src/vbt/value_based_triggers.cpp 

CPP_DEPS += \
./src/vbt/abstract_vbt_condition.d \
./src/vbt/value_based_trigger.d \
./src/vbt/value_based_triggers.d 

OBJS += \
./src/vbt/abstract_vbt_condition.o \
./src/vbt/value_based_trigger.o \
./src/vbt/value_based_triggers.o 


# Each subdirectory must supply rules for building sources it contributes
src/vbt/%.o: ../src/vbt/%.cpp src/vbt/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__BCRYPT=1 -D__SUPLA_SERVER=1 -DSPROTO_WITHOUT_OUT_BUFFER -DSRPC_WITHOUT_OUT_QUEUE -DUSE_DEPRECATED_EMEV_V1 -D__OPENSSL_TOOLS=1 -I$(INCMYSQL) -I../src/mqtt -I../src/client -I../src/user -I../src/device -I../src -I$(SSLDIR)/include -O2 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -std=c++11 -fPIE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-vbt

clean-src-2f-vbt:
	-$(RM) ./src/vbt/abstract_vbt_condition.d ./src/vbt/abstract_vbt_condition.o ./src/vbt/value_based_trigger.d ./src/vbt/value_based_trigger.o ./src/vbt/value_based_triggers.d ./src/vbt/value_based_triggers.o

.PHONY: clean-src-2f-vbt

