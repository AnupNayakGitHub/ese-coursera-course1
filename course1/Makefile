include sources.mk 

# overrides
PLATFORM = HOST

#common variables
SRC_DIR = src
BASENAME= course1
SWITCH = -DCOURSE1 -DVERBOSE

#platform specific variables
ifeq ($(PLATFORM),HOST)
  CC = gcc
  SRC = $(HOST_SRC)
  INC = $(foreach d, $(HOST_INC), -I$d)
  TARGET = $(BASENAME).out
  CFLAGS = -Wall -Werror -g -O0 -std=c99 \
	   $(INC)
  CPPFLAGS = -D$(PLATFORM) $(SWITCH)
  LDFLAGS = -Wl,-Map=$(BASENAME).map 
else ifeq ($(PLATFORM),MSP432)
  CPU = cortex-m4
  ARCH = -mthumb \
	 -march=armv7e-m \
	 -mfloat-abi=hard \
	 -mfpu=fpv4-sp-d16
  SPECS = nosys.specs
  LINKER_FILE = msp432p401r.lds 

  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  SRC = $(MSP432_SRC)
  INC = $(foreach d, $(MSP432_INC), -I$d)
  TARGET = $(BASENAME).out
  CFLAGS = -Wall -Werror -g -O0 -std=c99 \
	   -mcpu=$(CPU) $(ARCH) --specs=$(SPECS) \
	   $(INC)
  CPPFLAGS = -D$(PLATFORM) $(SWITCH)
  LDFLAGS = -Wl,-Map=$(BASENAME).map -T $(LINKER_FILE)
endif

OBJS = $(SRC:.c=.o)
%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
#	$(CC) $(CFLAGS) $(CPPFLAGS) -D$(PLATFORM) -c $< -o $@

%.i : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -E -c $< -o $@

%.asm : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -S -c $< -o $@

%.d : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -M -c $< -o $@

.PHONY: build
build : all
.PHONY: all
all : $(TARGET)

.PHONY: compile-all
compile-all : $(OBJS)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@
#	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $@

.PHONY: clean
clean:
	rm -f *.out *.i *.asm *.o *.d *.map
