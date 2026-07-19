CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror
SRC = bit_access.c bit_count.c bit_transform.c bit_math.c bit_xor.c bit_range.c bit_pattern.c bit_advanced.c
BUILD = build
APP = $(BUILD)/bitwise
TEST = $(BUILD)/bitwise_test

.PHONY: all run test clean

all: $(APP)

$(BUILD):
	mkdir -p $(BUILD)

$(APP): main.c $(SRC) bitwise.h | $(BUILD)
	$(CC) $(CFLAGS) main.c $(SRC) -o $(APP)

run: $(APP)
	./$(APP)

$(TEST): test.c $(SRC) bitwise.h | $(BUILD)
	$(CC) $(CFLAGS) test.c $(SRC) -o $(TEST)

test: $(TEST)
	./$(TEST)

clean:
	rm -f $(APP) $(TEST)
	rmdir $(BUILD) 2>/dev/null || true
