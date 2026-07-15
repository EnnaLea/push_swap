NAME = push_swap
CHECKER = checker
BONUS = bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

SRC = disorder \
        normalize \
        operations_swap \
        operations_push \
        operations_rotate \
        operations_rev_rotate \
        push_swap \
        sort_adaptive \
        sort_complex \
        sort_medium \
        sort_simple \
        stack_operations \
        stack \
        utils_find \
        utils \
        utils_write \
        utils_parsing \
        utils_push_swap \
        utils_medium \
        utils_token \
        bench \

SRC_MAIN = main.c
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))
TEST_SRCS = $(wildcard tests/test_*.c)
TEST_TARGETS = $(TEST_SRCS:tests/test_%.c=test_%)

BONUS_SRC = checker_bonus \
            checker_main_bonus \
            checker_op_bonus

BONUS_OBJS = $(addprefix bonus/, $(addsuffix .o, $(BONUS_SRC)))

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS) $(SRC_MAIN)
	$(CC) $(CFLAGS) $(SRC_MAIN) $(OBJS) -o $(NAME)

$(CHECKER): $(OBJS) checker_linux
	cp checker_linux $(CHECKER)
	chmod +x $(CHECKER)

bonus/%.o: bonus/%.c
	@mkdir -p bonus                       
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(BONUS_OBJS)
	$(RM) $(CHECKER)                     
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS) -o $(CHECKER)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_TARGETS) $(CHECKER)

re: fclean all

debug:
	@echo "SRC = $(SRC)"
	@echo "OBJS = $(OBJS)"
	@echo "BONUS_OBJS = $(BONUS_OBJS)"

.PHONY: all clean fclean re bonus all_tests run_tests