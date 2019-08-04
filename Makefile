NAME					= libArduino.a
INC_NAME				= $(sort libArduino.h)
SRC_NAME				= $(sort libDigitalRead.c libPinMode.c libDelay.c \
	libDigitalWrite.c)

COMPILE_FLAGS			= -Wall -Wextra -Werror
DEVICE					= atmega328p
CLOCK					= 16000000

## don't need to be setup
OBJ_NAME					= $(SRC_NAME:.c=.o)
SRC_PATH					= ./srcs/
OBJ_PATH					= ./objs/
INC_PATH					= ./incs/

SRC							= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ							= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC							= $(addprefix $(INC_PATH),$(INC_NAME))

All: $(NAME)

$(NAME): $(OBJ)
	@avr-ar -r $(NAME) $(OBJ)
	@avr-objdump -h -S $(NAME)  > $(NAME:.a=.lss)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@avr-gcc -I $(INC_PATH) $(COMPILE_FLAGS) -Os -DF_CPU=$(CLOCK)UL -mmcu=$(DEVICE) -o $@ -c $<

size: $(NAME)
	@avr-size --format=avr --mcu=$(DEVICE) $(NAME)

clean: $(OBJ)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME:.a=.lss)

.PHONY: All clean fclean
