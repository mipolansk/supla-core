################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/client/call_handler/abstract_client_srpc_call_handler.cpp \
../src/client/call_handler/channel_set_value.cpp \
../src/client/call_handler/channel_set_value_b.cpp \
../src/client/call_handler/get_next.cpp \
../src/client/call_handler/register_client.cpp \
../src/client/call_handler/register_client_b.cpp \
../src/client/call_handler/register_client_c.cpp \
../src/client/call_handler/register_client_d.cpp \
../src/client/call_handler/set_value.cpp 

CPP_DEPS += \
./src/client/call_handler/abstract_client_srpc_call_handler.d \
./src/client/call_handler/channel_set_value.d \
./src/client/call_handler/channel_set_value_b.d \
./src/client/call_handler/get_next.d \
./src/client/call_handler/register_client.d \
./src/client/call_handler/register_client_b.d \
./src/client/call_handler/register_client_c.d \
./src/client/call_handler/register_client_d.d \
./src/client/call_handler/set_value.d 

OBJS += \
./src/client/call_handler/abstract_client_srpc_call_handler.o \
./src/client/call_handler/channel_set_value.o \
./src/client/call_handler/channel_set_value_b.o \
./src/client/call_handler/get_next.o \
./src/client/call_handler/register_client.o \
./src/client/call_handler/register_client_b.o \
./src/client/call_handler/register_client_c.o \
./src/client/call_handler/register_client_d.o \
./src/client/call_handler/set_value.o 


# Each subdirectory must supply rules for building sources it contributes
src/client/call_handler/%.o: ../src/client/call_handler/%.cpp src/client/call_handler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__DEBUG=1 -DUSE_DEPRECATED_EMEV_V1 -D__TEST=1 -D__OPENSSL_TOOLS=1 -D__BCRYPT=1 -I../src -I../src/asynctask -I../src/mqtt -I$(INCMYSQL) -I../src/user -I../src/device -I../src/client -I$(SSLDIR)/include -I../src/test -O2 -g3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -D_FORTIFY_SOURCE=2 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-client-2f-call_handler

clean-src-2f-client-2f-call_handler:
	-$(RM) ./src/client/call_handler/abstract_client_srpc_call_handler.d ./src/client/call_handler/abstract_client_srpc_call_handler.o ./src/client/call_handler/channel_set_value.d ./src/client/call_handler/channel_set_value.o ./src/client/call_handler/channel_set_value_b.d ./src/client/call_handler/channel_set_value_b.o ./src/client/call_handler/get_next.d ./src/client/call_handler/get_next.o ./src/client/call_handler/register_client.d ./src/client/call_handler/register_client.o ./src/client/call_handler/register_client_b.d ./src/client/call_handler/register_client_b.o ./src/client/call_handler/register_client_c.d ./src/client/call_handler/register_client_c.o ./src/client/call_handler/register_client_d.d ./src/client/call_handler/register_client_d.o ./src/client/call_handler/set_value.d ./src/client/call_handler/set_value.o

.PHONY: clean-src-2f-client-2f-call_handler

