################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/google/google_home_client2.cpp \
../src/google/google_home_credentials2.cpp \
../src/google/google_home_credentials_dao.cpp \
../src/google/google_home_state_report_request2.cpp \
../src/google/google_home_sync_request2.cpp \
../src/google/google_home_sync_search_condition.cpp \
../src/google/googlehomeclient.cpp \
../src/google/googlehomecredentials.cpp \
../src/google/googlehomerequest.cpp \
../src/google/googlehomestatereportrequest.cpp 

CPP_DEPS += \
./src/google/google_home_client2.d \
./src/google/google_home_credentials2.d \
./src/google/google_home_credentials_dao.d \
./src/google/google_home_state_report_request2.d \
./src/google/google_home_sync_request2.d \
./src/google/google_home_sync_search_condition.d \
./src/google/googlehomeclient.d \
./src/google/googlehomecredentials.d \
./src/google/googlehomerequest.d \
./src/google/googlehomestatereportrequest.d 

OBJS += \
./src/google/google_home_client2.o \
./src/google/google_home_credentials2.o \
./src/google/google_home_credentials_dao.o \
./src/google/google_home_state_report_request2.o \
./src/google/google_home_sync_request2.o \
./src/google/google_home_sync_search_condition.o \
./src/google/googlehomeclient.o \
./src/google/googlehomecredentials.o \
./src/google/googlehomerequest.o \
./src/google/googlehomestatereportrequest.o 


# Each subdirectory must supply rules for building sources it contributes
src/google/%.o: ../src/google/%.cpp src/google/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	$(CXX) -D__DEBUG=1 -D__SUPLA_SERVER=1 -DSPROTO_WITHOUT_OUT_BUFFER -DSRPC_WITHOUT_OUT_QUEUE -DUSE_DEPRECATED_EMEV_V1 -D__OPENSSL_TOOLS=1 -D__SSOCKET_WRITE_TO_FILE=$(SSOCKET_WRITE_TO_FILE) -D__BCRYPT=1 -I$(INCMYSQL) -I../src/mqtt -I../src/device -I../src/user -I../src -I$(SSLDIR)/include -I../src/client -O2 -g3 -Wall -fsigned-char -c -fmessage-length=0 -fstack-protector-all -D_FORTIFY_SOURCE=2 -std=c++11 -fPIE -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-google

clean-src-2f-google:
	-$(RM) ./src/google/google_home_client2.d ./src/google/google_home_client2.o ./src/google/google_home_credentials2.d ./src/google/google_home_credentials2.o ./src/google/google_home_credentials_dao.d ./src/google/google_home_credentials_dao.o ./src/google/google_home_state_report_request2.d ./src/google/google_home_state_report_request2.o ./src/google/google_home_sync_request2.d ./src/google/google_home_sync_request2.o ./src/google/google_home_sync_search_condition.d ./src/google/google_home_sync_search_condition.o ./src/google/googlehomeclient.d ./src/google/googlehomeclient.o ./src/google/googlehomecredentials.d ./src/google/googlehomecredentials.o ./src/google/googlehomerequest.d ./src/google/googlehomerequest.o ./src/google/googlehomestatereportrequest.d ./src/google/googlehomestatereportrequest.o

.PHONY: clean-src-2f-google

