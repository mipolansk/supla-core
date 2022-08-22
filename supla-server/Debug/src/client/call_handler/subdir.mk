################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/client/call_handler/abstract_client_srpc_call_handler.cpp \
../src/client/call_handler/register_client.cpp \
../src/client/call_handler/register_client_b.cpp \
../src/client/call_handler/register_client_c.cpp \
../src/client/call_handler/register_client_d.cpp 

CPP_DEPS += \
./src/client/call_handler/abstract_client_srpc_call_handler.d \
./src/client/call_handler/register_client.d \
./src/client/call_handler/register_client_b.d \
./src/client/call_handler/register_client_c.d \
./src/client/call_handler/register_client_d.d 

OBJS += \
./src/client/call_handler/abstract_client_srpc_call_handler.o \
./src/client/call_handler/register_client.o \
./src/client/call_handler/register_client_b.o \
./src/client/call_handler/register_client_c.o \
./src/client/call_handler/register_client_d.o 


# Each subdirectory must supply rules for building sources it contributes
src/client/call_handler/%.o: ../src/client/call_handler/%.cpp src/client/call_handler/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	$(CXX) -D__DEBUG=1 -DSPROTO_WITHOUT_OUT_BUFFER -DSRPC_WITHOUT_OUT_QUEUE -DUSE_DEPRECATED_EMEV_V1 -D__OPENSSL_TOOLS=1 -D__SSOCKET_WRITE_TO_FILE=$(SSOCKET_WRITE_TO_FILE) -D__BCRYPT=1 -I$(INCMYSQL) -I../src/mqtt -I../src/device -I../src/user -I../src -I$(SSLDIR)/include -I../src/client -O2 -g3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -D_FORTIFY_SOURCE=2 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-client-2f-call_handler

clean-src-2f-client-2f-call_handler:
	-$(RM) ./src/client/call_handler/abstract_client_srpc_call_handler.d ./src/client/call_handler/abstract_client_srpc_call_handler.o ./src/client/call_handler/register_client.d ./src/client/call_handler/register_client.o ./src/client/call_handler/register_client_b.d ./src/client/call_handler/register_client_b.o ./src/client/call_handler/register_client_c.d ./src/client/call_handler/register_client_c.o ./src/client/call_handler/register_client_d.d ./src/client/call_handler/register_client_d.o

.PHONY: clean-src-2f-client-2f-call_handler

